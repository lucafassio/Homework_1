#include <iostream>
using namespace std;

typedef struct node node_t;
typedef struct list list_t;

node_t *create_node(int value);

list_t *create_list();

bool list_is_empty(list_t *list);

bool push_front(list_t *list, int value);

bool push_back(list_t *list, int value);

bool pop_front(list_t *list);

bool pop_back(list_t *list);

bool insert(list_t *list, int value, int pos);

bool erase(list_t *list, int pos);

bool check_pos(list_t *list, int num);

void print_list(list_t *list);

void clear_list(list_t *list);