# C - CREATING a Simple Shell<br>
> This repository contains the code for a simple shell created as part of the curriculum of the Holberton School. It is designed to replicate some of the basic functionalities of the standard shell, including executing commands and running scripts.

## Functions and System calls used<br>

- all functions from strings.h
- ``execve`` (man 2 execve)
- ``exit`` (man 3 exit)
- ``fork`` (man 2 fork)
- ``free`` (man 3 free)
- ``getline`` (man 3 getline)
- ``isatty`` (man 3 isatty)
- ``malloc`` (man 3 malloc)
- ``perror`` (man 3 perror)
- ``fprintf`` (man 3 fprintf)
- ``stat`` (__xstat) (man 2 stat)
- ``strtok`` (man 3 strtok)
- ``wait`` (man 2 wait)

## Requirements for the Shell<br>

- All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options ``-g -Wall -Werror -Wextra -pedantic -std=gnu89 -o hsh``
- Code passes the betty checks successfully.
- Use the least amount of System calls.
- Shell does not have any memory leaks, tested with valgrind ``valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh``
- No more than 5 functions per file.
- All prototypes of all functions are included in header file main.h.

## What our Shell supports<br>

- Interactive mode
- Non-interactive mode
- Arguments
- Error messages
- Exit built-in
- Ctrl + D
- Env built-in

## Functions used in our shell<br>


| Function | Description |
| --- | --- | 
| [checkemptiness](/support_functions.c) | Verifies if the command we give is empty. |
| [exq](/support_functions.c) | Executes the splitted command. |
| [_perror](/support_functions.c) | Prints error message in a certain format. |
| [splitter](/splitter.c) | Divides the command according to certain delimiters. |
| [free_token](/splitter.c) | Frees the splitted command. |
| [get_path](/get_location.c) | Obtains the absolute route of the command. |
| [_getenv](/environment.c) | Obtains the environment variable. |
| [shell](/shell.c) | Is in charge of executing the RPEL loop. |

## FILES of our repository

- [environment.c](/environment.c) - Contains the _getenv function.
- [get_location.c](/get_location.c) - Contains our own path function.
- [main.h](/main.h) - Our header file.
- [shell.c](/shell.c) - Contains our loop.
- [splitter.c](/splitter.c) - splitter and free_token function.
- [support_functions.c](/support_functions.c) - Auxiliary functions.


## Authors

[Felipe Pereira Forte](https://github.com/felipf)

[Gabriel Delgado](https://github.com/Gabr1el20)
