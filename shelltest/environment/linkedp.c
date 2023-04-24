#include "main.h"

char *_getenv(const char *name);

path_node_t *build_path()
{
    char *path_var = NULL, *path_copy = NULL, *direc = NULL;

    path_var = _getenv("PATH");
    if (path_var == NULL)
    {
        printf("La variable de entorno PATH no ha sido encontrada\n");
        return (NULL);
    }

    path_copy = strdup(path_var);
    if (path_copy == NULL)
    {
        printf("Error: No se ha podido alocar memoria\n");
        return (NULL);
    }

    path_node_t *head = NULL;
    path_node_t *tail = NULL;

    direc = strtok(path_copy, ":");
    while (direc != NULL)
    {
        path_node_t *nuevo = malloc(sizeof(path_node_t));
        if (nuevo == NULL)
        {
            printf("Error: No se ha podido allocar memoria\n");
            return (NULL);
        }

        nuevo->direc = strdup(direc);
        if (nuevo->direc == NULL)
        {
            printf("Error: NO se ha podido alocar memoria\n");
            free(nuevo);
            return (NULL);
        }

        nuevo->next = NULL;
        if (tail == NULL)
        {
            head = nuevo;
        }
        else
        {
            tail->next = nuevo;
        }
        tail = nuevo;
        direc = strtok(NULL, ":");
    }
    free(path_copy);
    return (head);
}


void free_path_list(path_node_t *head)
{
    while (head != NULL)
    {
        path_node_t *temp = head;
        head = head->next;
        free(temp->direc);
        free(temp);
    }
}

int main()
{
    path_node_t *head = build_path();
    path_node_t *current = NULL;
    if (head == NULL)
    {
        return (1);
    }
    for (current = head; current != NULL; current = current->next)
    {
        printf("%s\n", current->direc);
    }
    free_path_list(head);
    return (0);
}