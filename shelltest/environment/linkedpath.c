#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name);

typedef struct path_node {
    char *dir;
    struct path_node *next;
} path_node_t;

path_node_t *build_path_list()
 {
    char *path_var = _getenv("PATH");
    if (path_var == NULL) {
        printf("PATH environment variable not found.\n");
        return NULL;
    }

    char *path_copy = strdup(path_var);
    if (path_copy == NULL) {
        printf("Error: unable to allocate memory.\n");
        return NULL;
    }

    path_node_t *head = NULL;
    path_node_t *tail = NULL;
    char *dir = strtok(path_copy, ":");
    while (dir != NULL) {
        path_node_t *node = malloc(sizeof(path_node_t));
        if (node == NULL) {
            printf("Error: unable to allocate memory.\n");
            return NULL;
        }

        node->dir = strdup(dir);
        if (node->dir == NULL) {
            printf("Error: unable to allocate memory.\n");
            free(node);
            return NULL;
        }

        node->next = NULL;
        if (tail == NULL) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;

        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return head;
}

void free_path_list(path_node_t *head) {
    while (head != NULL) {
        path_node_t *temp = head;
        head = head->next;
        free(temp->dir);
        free(temp);
    }
}

int main() {
    path_node_t *head = build_path_list();
    if (head == NULL) {
        return 1;
    }

    for (path_node_t *curr = head; curr != NULL; curr = curr->next) {
        printf("%s\n", curr->dir);
    }

    free_path_list(head);
    return 0;
}
