#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE 80

char *builtin_str[] = {"exit", "env"};

int num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

int shell_exit(char **args) {
    return 0;
}

int shell_env(char **args) {
    char **env;

    while (*env) {
        printf("%s\n", *env++);
    }
    return 1;
}

int (*builtin_func[]) (char **) = {
    &shell_exit,
    &shell_env
};

int execute(char **args) {
    if (args[0] == NULL) {
        // Empty command
        return 1;
    }

    for (int i = 0; i < num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s (%s)\n", args[0], strerror(errno));
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        fprintf(stderr, "Error forking\n");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        while (getchar() != '\n');
    }

    return 1;
}

char **parse_line(char *line) {
    char **args = malloc(MAX_LINE * sizeof(char *));
    char *arg;
    int i = 0;

    if (!args) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    arg = strtok(line, " \t\n");
    while (arg != NULL) {
        args[i++] = arg;
        arg = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    return args;
}

int main(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        fflush(stdout);

        line = malloc(MAX_LINE * sizeof(char));
        if (!line) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        if (fgets(line, MAX_LINE, stdin) == NULL) {
            free(line);
            exit(EXIT_SUCCESS);
        }

        args = parse_line(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);

    return EXIT_SUCCESS;
}