#include "list.h"

struct node{
    int value;
    node_t *next;
};

struct list{
    node_t *head;
    int size;
};


node_t *create_node(int value){
    node_t *new_node=new node_t;
    new_node->value=value;
    new_node->next=nullptr;
    return new_node;
}

list_t *create_list(){
    list_t *new_list=new list_t;
    new_list->head=nullptr;
    new_list->size=0;
    return new_list;
}

bool list_is_empty(list_t *list){
    return list->size==0;
}

bool push_front(list_t *list, int value){
    node_t *new_node=create_node(value);
    if(new_node==nullptr) return false;
    new_node->next=list->head;
    list->head=new_node;
    list->size++;
    return true;
}

bool push_back(list_t *list, int value){
    node_t *new_node=create_node(value);
    if(new_node==nullptr) return false;
    if(list_is_empty(list))
        list->head=new_node;
    else{
        node_t *aux=list->head;
        while(aux->next!=nullptr) aux=aux->next;
        aux->next=new_node;
    }
    list->size++;
    return true;
}

bool pop_front(list_t *list){
    if(list_is_empty(list)) return false;
    node_t *aux=list->head;
    list->head=list->head->next;
    delete aux;
    list->size--;
    return true;
}

bool pop_back(list_t *list){
    if(list_is_empty(list)) return false;
    if(list->size==1){
        delete list->head;
        list->head=nullptr;
    }else{
        node_t *aux=list->head;
        while(aux->next->next!=nullptr) aux=aux->next;
        delete aux->next;
        aux->next=nullptr;
    }
    list->size--;
    return true;
}

bool insert(list_t *list, int value, int pos){
    if (!check_pos(list, pos)) return false;
    if(pos==0) return push_front(list, value);
    if(pos>=list->size){
        if (pos>list->size) cout << "Appending at the end of the list." << endl;
        return push_back(list, value);
    }
        node_t *new_node=create_node(value);
    if(new_node==nullptr) return false;
    node_t *aux=list->head;
    for(int i=1; i<pos; i++) aux=aux->next;
    new_node->next=aux->next;
    aux->next=new_node;
    list->size++;
    return true;
}

bool erase(list_t *list, int pos){
    if (!check_pos(list, pos)) return false;
    if(pos==0) return pop_front(list);
    if(pos>=list->size-1){
        if (pos>list->size-1) cout << "Deleting last element." << endl;
        return pop_back(list);
    }
    node_t *aux=list->head;
    for(int i=1; i<pos; i++) aux=aux->next;
    node_t *aux2=aux->next;
    aux->next=aux2->next;
    delete aux2;
    list->size--;
    return true;
}

bool check_pos(list_t *list, int pos){
    try{
        if (pos < 0) {
            throw runtime_error("Index must be positive.");
        } else if (pos > list->size) {
            throw out_of_range("Index out of range. ");
        } else {
            return true;
        }
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    } catch (const out_of_range& e) {
        cout << e.what();
        return true;
    }
    return false;
}

void print_list(list_t *list){
    if (list_is_empty(list)) {
        cout << "List is empty." << endl;
        return;
    }
    if (list->size==1) {
        cout << "List: " << list->head->value << endl;
        return;
    }
    node_t *aux=list->head->next;
    cout << "List: " << list->head->value;
    do{
        cout << " -> " << aux->value;
        aux=aux->next;
    } while(aux!=nullptr);
    cout << endl;
}

void clear_list(list_t *list){
    while(!list_is_empty(list)) pop_front(list);
    delete list;
}