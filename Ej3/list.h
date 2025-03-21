#ifndef LIST_H
#define LIST_H

#include "../Ej2/logmsg.h"
#include <iostream>
#include <memory>
using namespace std;

typedef struct node node_t;
typedef struct list list_t;

shared_ptr<node> create_node(int value, shared_ptr<node> next=nullptr);

shared_ptr<list> create_list();

bool list_is_empty(shared_ptr<list> l);

bool push_front(shared_ptr<list> l, int value);

bool push_back(shared_ptr<list> l, int value);

bool pop_front(shared_ptr<list> l);

bool pop_back(shared_ptr<list> l);

bool insert(shared_ptr<list> l, int value, int pos);

bool erase(shared_ptr<list> l, int pos);

void print_list(shared_ptr<list> l);

void run_3();

#endif // LIST_H