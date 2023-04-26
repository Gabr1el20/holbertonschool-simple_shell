#include "main.h"

#define MAX_PATH_LENGTH 1024
#define MAX_FILENAME_LENGTH 256
#define PATH_SEPARATOR ":"

int getpath(int argc, char **argv) {
    char *path_env, *path_entry, *path_entry_copy;
    char path[MAX_PATH_LENGTH], filename[MAX_FILENAME_LENGTH], full_path[MAX_PATH_LENGTH + MAX_FILENAME_LENGTH];
    int found = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
        exit(1);
    }

    path_env = getenv("PATH");
    if (!path_env) {
        fprintf(stderr, "Error: PATH environment variable not set.\n");
        exit(1);
    }

    while (*path_env) {
        path_entry = strchr(path_env, *PATH_SEPARATOR);
        if (!path_entry) {
            path_entry = path_env + strlen(path_env);
        }

        if (path_entry - path_env > 0) {
            strncpy(path, path_env, path_entry - path_env);
            path[path_entry - path_env] = '\0';

            for (int i = 1; i < argc; i++) {
                strncpy(filename, argv[i], MAX_FILENAME_LENGTH - 1);
                filename[MAX_FILENAME_LENGTH - 1] = '\0';

                snprintf(full_path, MAX_PATH_LENGTH + MAX_FILENAME_LENGTH, "%s/%s", path, filename);

                if (access(full_path, F_OK) == 0) {
                    printf("%s\n", full_path);
                    found = 1;
                }
            }
        }

        path_env = *path_entry ? path_entry + 1 : path_entry;
    }

    if (!found) {
        printf("No such file in PATH\n");
        return 1;
    }

    return 0;
}