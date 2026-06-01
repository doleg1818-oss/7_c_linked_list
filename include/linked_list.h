#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>


typedef struct linked_list_node
{
    int value;
    struct linked_list_node *next;
}linked_list_node_t;

typedef struct 
{
    linked_list_node_t *head;
    size_t count;
}linked_list_t;

void linked_list_init(linked_list_t *list);
bool linked_list_push_front(linked_list_t *list, linked_list_node_t *node);
bool linked_list_push_back(linked_list_t *list, linked_list_node_t *node);
bool linked_list_pop_front(linked_list_t *list, linked_list_node_t **out_node);
linked_list_node_t *linked_list_find(linked_list_t *list, int value);
size_t linked_list_count(const linked_list_t *list);
bool linked_list_remove(linked_list_t *list, linked_list_node_t *node);


#endif
