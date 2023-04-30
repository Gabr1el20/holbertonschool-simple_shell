int main(int ac __attribute__((unused)), char *av[] __attribute__((unused)))
{
	char *comando = NULL, **splitted;
	size_t bufsize = 0;
	int status = 0, count = 0, buffer = 0;

	while (1)
	{
		count++;
		isatty(0) == 1 ? write(1, "$ ", 2) : 0;
		buffer = getline(&comando, &bufsize, stdin);
		if (buffer == -1 || strcmp(comando, "exit\n") == 0)
		{
			free(comando);
			break;
		}
		if (comando[buffer - 1] == '\n')
			comando[buffer - 1] = '\0';
		if (strlen(comando) == 1)
			continue;
		if (checkemptiness(comando) == 1)
			continue;
		splitted = splitter(comando);
		status = refcommand(comando, splitted, count);
	}
	return (status);
}

int refcommand(char *command, char **splitted, int count)
{
    char *first = NULL;
    struct stat st;
    int exitcode = 0;

    if (splitted && splitted[0])
    {
        if (stat(splitted[0], &st) == 0)
        {
            first = splitted[0];
            exitcode = exq(first, splitted);
        }
        else if (stat(splitted[0], &st) == -1)
        {
            first = get_path(splitted[0]);
            if (first)
            {
                exitcode = exq(first, splitted);
                if(exitcode == -1)
                {
                    exit(2);
                }
            }
            else
            {
                _perror(splitted[0], count, command);
                exit(127);
            }
            free(first);
        }
    }
    return (exitcode);
}

int exq(char *completo, char **argus)
{
    pid_t pid;
    int status, ret = -1;

    pid = fork();

    if (pid > 0)
    {
        wait(&status);
        if (WIFEXITED(status))
        {
            ret = WEXITSTATUS(status);
        }
    }
    else if (pid == 0)
    {
        execve(completo, argus, environ);
        exit(127);
    }
    else
    {
        ret = -1;
    }
    free_token(argus);
    return (ret);
}