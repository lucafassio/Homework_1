#include "list.hpp"

struct node{
    int value;
    node_t *next;
};

node_t *create_node(int value){
    node_t *new_node = new node_t;
    new_node->value = value;
    new_node->next = nullptr;
    return new_node;
}