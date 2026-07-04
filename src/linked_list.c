#include "linked_list.h"

void linked_list_init(linked_list_t *list)
{
    if(list == NULL)
    {
        return;
    }
    list->head = NULL;
    list->count = 0;
}
bool linked_list_push_front(linked_list_t *list, linked_list_node_t *node)
{
    if(list == NULL || node == NULL)
    {
        return false;
    }
    node->next = list->head;
    /*
    1. node->next = NULL
    2. node->next = node->next - 1

    head node3 -> node2 -> node1
    */ 

    list->head = node;  // Head записав адрес на node
    list->count++;

    return true;
}
bool linked_list_push_back(linked_list_t *list, linked_list_node_t *node)
{
    if(list == NULL || node == NULL)
    {
        return false;
    }
    node->next = NULL;  
    if(list->head == NULL)  // If node is first in linked list
    {
        list->head = node;  // Point on new node
        list->count++;
        return true;
    }

    linked_list_node_t *current = list->head; //  make pointer on list for muvment

    while(current->next != NULL)              // Found lasr node (last node points on the NULL)
    {
        current = current->next;  // Step on the list
    }
    // Last node was found
    current->next = node;       // add node to the last node
    list->count++;

    return true;
}
bool linked_list_pop_front(linked_list_t *list, linked_list_node_t **out_node)
{
    if(list == NULL || out_node == NULL)
    {
        return false;
    }
    if(list->head == NULL)  // No any nodes in list
    {
        *out_node = NULL;
        return false;
    }
    *out_node = list->head; // Copy address first node into out_node
    list->head = list->head->next;  // make the second node like the first node
    (*out_node)->next = NULL;   // delete pointer on the next node
    list->count--;

    return true;
}
linked_list_node_t *linked_list_find(linked_list_t *list, int value)
{
    if(list == NULL)
    {
        return NULL;
    }
    linked_list_node_t *current = list->head;  // Point on the first node

    while(current != NULL)
    {
        if(current->value == value)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
size_t linked_list_count(const linked_list_t *list)
{
    if(list == NULL)
    {
        return 0;
    }
    return list->count;
}
bool linked_list_remove(linked_list_t *list, linked_list_node_t *node)
{
    if(list == NULL || node == NULL)
    {
        return false;
    }
    if(list->head == NULL)  // detect empty list 
    {
        return false;
    }
    if(list->head == node)  // if delete haad (first node)
    {
        list->head = node->next;    // Point on the next node
        node->next = NULL;
        list->count--;
        return true;
    }
    linked_list_node_t *current = list->head;  // Create pointer on the node

    while(current->next != NULL)      
    {
        if(current->next == node)       // if found target node
        {
            current->next = node->next;     // point on the next node
            node->next = NULL;              // Delete target node on the next nodes in the list
            list->count--;
            return true;
        }
        current = current->next;    // Make step
    }
    return false;
}