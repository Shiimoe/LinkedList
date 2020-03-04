#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

node_t *ll_prepend(int value, node_t *head)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = head;
    return node;
}

node_t *ll_node(int value)
{
    return ll_prepend(value, NULL);
}

node_t *ll_append(int value, node_t *butt)
{
    if (butt->next != NULL) {
        perror("Can only append to end of list.");
        exit(1);
    }
    node_t *new = ll_node(value);
    return butt->next = new;
}

size_t ll_length(node_t *head)
{
    // if (head == NULL) return 0;
    // if (head->next == NULL) return 1;
    // if (head->next->next == NULL) return 2;
    node_t *current_node = head;
    size_t i = 0;
    while (current_node != NULL) {
        current_node = current_node->next;
        // printf("%ld\n", (size_t)current_node->next);
        // printf("%ld\n", i);
        i++;
    }
    return i;
}

node_t *ll_get(node_t *head, size_t index)
{
    node_t *current_node = head;
    for (size_t i = 0; i < index; i++) {
        current_node = current_node->next;
    }
    return current_node;
}

node_t *ll_remove_after(node_t *before)
{
    node_t *for_removal = before->next;
    node_t *after = for_removal->next;
    before->next = after;
    return for_removal;
}

node_t *ll_remove(node_t *head, size_t index)
{
    return ll_remove_after(ll_get(head, index - 1));
}

node_t *ll_last(node_t *head)
{
    node_t *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    return current_node;
}

void ll_insert_after(node_t *before, node_t *insertee)
{
    node_t *after = before->next;
    before->next = insertee;
    node_t *insertee_butt = ll_last(insertee);
    insertee_butt->next = after;
}

void ll_insert(node_t *head, size_t index, node_t *insertee)
{
    ll_insert_after(ll_get(head, index - 1), insertee);
}

char *ll_string(node_t *head)
{
    char *string = malloc(sizeof(char)*ll_length(head)*20);
    size_t off = 0;
    node_t *current_node = head;
    while (current_node != NULL) {
        off += sprintf(string+off, "%d -> ", current_node->value);
        current_node = current_node->next;
    }
    string[off-4] = '\0';
    return string; 
}