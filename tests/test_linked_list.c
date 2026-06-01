#include "assert.h"
#include "stdio.h"

#include "linked_list.h"

int main(void)
{
    linked_list_t list;

    linked_list_init(&list);
    assert(linked_list_count(&list) == 0);

    linked_list_node_t node_1 =
    {
        .value = 10,
        .next = NULL
    };

    bool status = linked_list_push_front(&list, &node_1);
    assert(status == true);
    assert(linked_list_count(&list) == 1);
    assert(list.head == &node_1);
    assert(list.head->value == 10);

    linked_list_node_t node_2 =
    {
        .value = 20,
        .next = NULL
    };

    status = linked_list_push_back(&list, &node_2);
    assert(status == true);
    assert(linked_list_count(&list) == 2);
    assert(list.head == &node_1);
    assert(list.head->next == &node_2);
    assert(list.head->next->value == 20);
    assert(node_2.next == NULL);

    linked_list_node_t *removed_node = NULL;
    status = linked_list_pop_front(&list, &removed_node);
    assert(status == true);
    assert(removed_node == &node_1);
    assert(removed_node->value == 10);
    assert(removed_node->next == NULL);

    assert(linked_list_count(&list) == 1);
    assert(list.head == &node_2);


    linked_list_node_t *found;
    found = linked_list_find(&list, 20);
    assert(found != NULL);
    assert(found == &node_2);
    assert(found->value == 20);

    printf("LINKED LIST TEST 1 PASSET\n");


    linked_list_t list_1;
    linked_list_init(&list);

    linked_list_node_t node1 = {.value = 10};
    linked_list_node_t node2 = {.value = 20};
    linked_list_node_t node3 = {.value = 30};

    linked_list_push_back(&list_1, &node1);
    linked_list_push_back(&list_1, &node2);
    linked_list_push_back(&list_1, &node3);

    assert(linked_list_count(&list_1) == 3);

    status = linked_list_remove(&list_1, &node2);

    assert(status == true);

    assert(linked_list_count(&list_1) == 2);

    assert(list_1.head == &node1);
    assert(node1.next == &node3);
    assert(node3.next == NULL);

    printf("LINKED LIST TEST 2 PASSET\n");

    
    return 0;
}