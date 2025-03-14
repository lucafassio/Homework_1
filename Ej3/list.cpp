#include "list.h"

struct node{
    int value;
    shared_ptr<node> next;
};

struct list {
    shared_ptr<node> head;
    int size;
};

bool list_is_empty(shared_ptr<list_t> l){
    return l->size==0;
}

shared_ptr<node_t> create_node(int value, shared_ptr<node_t> next){
    shared_ptr<node> new_node=make_shared<node_t>();
    new_node->value=value;
    new_node->next=next;
    return new_node;
}

shared_ptr<list_t> create_list(){
    shared_ptr<list> list=make_shared<list_t>();
    list->head=nullptr;
    list->size=0;
    return list;
}

bool push_front(shared_ptr<list_t> l, int value){
    l->head=create_node(value, l->head);
    l->size++;
    return true;
}

bool push_back(shared_ptr<list_t> l, int value){
    if (list_is_empty(l)) l->head=create_node(value, nullptr);
    else{
        shared_ptr aux=l->head;
        while (aux->next)
            aux=aux->next;
        aux->next=create_node(value, nullptr);
    }
    l->size++;
    return true;
}

bool insert(shared_ptr<list_t>  l, int value, int pos){
    if (pos<0){
        cout << "Invalid pos." << endl;
        return false;
    }
    if (pos==0) return push_front(l, value);
    if (pos==l->size) return push_back(l, value);
    if (pos>l->size){
        cout << "Pos is higher than size. Node was inserted at the end." << endl;
        return push_back(l, value);
    }
    shared_ptr aux=l->head;
    for(int i=1; i<pos; i++)
        aux=aux->next;
    aux->next=create_node(value, aux->next);
    l->size++;
    return true;
}

bool pop_front(shared_ptr<list_t>  l){
    if (list_is_empty(l)) return false;
    l->head=l->head->next;
    l->size--;
    return true;
}

bool pop_back(shared_ptr<list_t>  l){
    if (list_is_empty(l)) return false;
    if (l->size==1) return pop_front(l);
    shared_ptr aux=l->head;
    while (aux->next->next)
        aux=aux->next;
    aux->next=nullptr;
    l->size--;
    return true;
}

bool erase(shared_ptr<list_t> l, int pos){
    if (pos<0){
        cout << "Invalid pos." << endl;
        return false;
    }
    if (pos==0) return pop_front(l);
    if (pos==l->size-1) return pop_back(l);
    if (pos>=l->size){
        cout << "Pos is higher than size. Node was erased at the end." << endl;
        return pop_back(l);
    }
    shared_ptr aux=l->head;
    for (int i=0; i<pos-1; i++)
        aux=aux->next;
    aux->next=aux->next->next;
    l->size--;
    return true;
}

void print_list(shared_ptr<list_t>  l){
    if (list_is_empty(l)) {cout << "List is empty." << endl; return;}
    shared_ptr aux=l->head;
    cout << "List: " << aux->value;
    aux=aux->next;
    do{
        cout << " -> " << aux->value;
        aux=aux->next;
    } while(aux);
    cout << endl;
}

void run_3(){
    shared_ptr<list> list=create_list();
    cout << endl << "========== Ej 3: List ==========" << endl;
    int option;
    int error_line;
    while (true){
        try{
            cout << endl << "Choose an option:" << endl << "1. Push front" << endl << "2. Push back" << endl << "3. Pop front" << endl << "4. Pop back" << endl << "5. Insert" << endl << "6. Erase" << endl << "7. Print list" << endl << "8. Exit" << endl;
            cout << endl << "> ";
            cin >> option;
            switch (option){
                case 1:
                    cout << "Value: ";
                    int value;
                    cin >> value;
                    push_front(list, value);
                    cout << "Value " << value << " was pushed to front." << endl;
                    break;
                case 2:
                    cout << "Value: ";
                    cin >> value;
                    push_back(list, value);
                    cout << "Value was " << value << " pushed to back." << endl;
                    break;
                case 3:
                    if (pop_front(list)) cout << "Value was popped from front." << endl;
                    else cout << "List is empty." << endl;
                    break;
                case 4:
                    if (pop_back(list)) cout << "Value was popped from back." << endl;
                    else cout << "List is empty." << endl;
                    break;
                case 5:
                    cout << "Position: ";
                    int pos;
                    cin >> pos;
                    if (pos<0){
                        error_line=__LINE__+1;
                        throw invalid_argument("ERROR - Negative position.");
                    } 
                    cout << "Value: ";
                    cin >> value;
                    insert(list, value, pos);
                    if (pos>list->size) pos=list->size;
                    cout << "Value " << value << " was inserted at position " << pos << "." << endl;
                    break;
                case 6:
                    cout << "Position: ";
                    cin >> pos;
                    if (pos<0) {
                        error_line=__LINE__+1;
                        throw invalid_argument("ERROR - Negative position.");
                    } 
                    erase(list, pos);
                    if (pos>list->size) pos=list->size;
                    cout << "Value at position " << pos << " was erased." << endl;
                    break;
                case 7:
                    print_list(list);
                    break;
                case 8:
                    return;
                default:
                    error_line=__LINE__+1;
                    throw invalid_argument("ERROR - Invalid option.");
                    break;
            }
        }
        catch (invalid_argument &e){
            cout << e.what() << endl;
            logMessage(e.what(), __FILE__, error_line);
        }
        catch (...) {
            cout << "ERROR - Unknown error." << endl;
            logMessage("Unknown error", __FILE__, __LINE__);
        }
    }
}