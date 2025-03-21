#include "list.h"

struct node{
    int value;
    shared_ptr<node> next;
};

struct list {
    shared_ptr<node> head;
    int size;
};

//chequeo si la lista esta vacia
bool list_is_empty(shared_ptr<list_t> l){
    return l->size==0;
}

//creo un nodo con el valor y el next indicado.
shared_ptr<node_t> create_node(int value, shared_ptr<node_t> next){
    shared_ptr<node> new_node=make_shared<node_t>();
    new_node->value=value;
    new_node->next=next;
    return new_node;
}

//creo una lista vacia
shared_ptr<list_t> create_list(){
    shared_ptr<list> list=make_shared<list_t>();
    list->head=nullptr;
    list->size=0;
    return list;
}

//creo un nodo al principio de la lista y aumento el size.
bool push_front(shared_ptr<list_t> l, int value){
    l->head=create_node(value, l->head);
    l->size++;
    return true;
}

//creo un nodo al final de la lista y aumento el size.
bool push_back(shared_ptr<list_t> l, int value){
    //si la lista esta vacia, el nodo creado es el head.
    if (list_is_empty(l)) push_front(l, value);
    else{
        //utilizo un auxiliar para recorrer la lista y llegar al final.
        shared_ptr aux=l->head;
        while (aux->next)
            aux=aux->next;
        aux->next=create_node(value, nullptr);
    }
    l->size++;
    return true;
}

//creo un nodo en el lugar indicado y aumento el size.
bool insert(shared_ptr<list_t>  l, int value, int pos){
    //si la posicion es negativa, lanzo un error.
    if (pos<0){
        cout << "Invalid pos." << endl;
        return false;
    }

    //si la posicion es 0, inserto al principio.
    if (pos==0) return push_front(l, value);

    //si la posicion es igual al size, inserto al final.
    if (pos==l->size) return push_back(l, value);

    //si la posicion es mayor al size, inserto al final e informo.
    if (pos>l->size){
        cout << "Pos is higher than size. Node was inserted at the end." << endl;
        return push_back(l, value);
    }

    //si la posicion esta dentro de la lista recorro hasta la posicion e inserto.
    shared_ptr aux=l->head;
    for(int i=1; i<pos; i++)
        aux=aux->next;
    aux->next=create_node(value, aux->next);
    l->size++;
    return true;
}

//elimino el primer elemento.
bool pop_front(shared_ptr<list_t>  l){
    if (list_is_empty(l)) return false;

    //muevo el head al proximo nodo
    l->head=l->head->next;
    l->size--;
    return true;
}

//elimino el ultimo elemento.
bool pop_back(shared_ptr<list_t>  l){
    if (list_is_empty(l)) return false;

    //si la lista tiene un solo elemento, elimino el head.
    if (l->size==1) return pop_front(l);

    //recorro hasta el final y elimino.
    shared_ptr aux=l->head;
    while (aux->next->next)
        aux=aux->next;
    aux->next=nullptr;
    l->size--;
    return true;
}

//elimino el elemento en la posicion indicada y disminuyo el size.
bool erase(shared_ptr<list_t> l, int pos){
    //si la posicion es negativa, lanzo un error.
    if (pos<0) return false;

    //si la posicion es 0, elimino el primer elemento.
    else if (pos==0) return pop_front(l);

    //si la posicion es igual al size, elimino el ultimo elemento.
    else if (pos==l->size-1) return pop_back(l);

    //si la posicion es mayor al size, elimino el ultimo elemento e informo.
    else {
        cout << "Pos is higher than size. Node was erased at the end." << endl;
        return pop_back(l);
    }

    //si la posicion esta dentro de la lista recorro hasta la posicion y elimino.
    shared_ptr aux=l->head;
    for (int i=0; i<pos-1; i++)
        aux=aux->next;
    aux->next=aux->next->next;
    l->size--;
    return true;
}

void print_list(shared_ptr<list_t>  l){
    //si la lista esta vacia informo.
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
            cout << endl << "Choose an option:\n1. Push front\n2. Push back\n3. Pop front\n4. Pop back\n5. Insert\n6. Erase\n7. Print list\n8. Exit" << endl;
            cout << endl << "> ";
            cin >> option;

            //si se ingresa un char o string, lanzo error.
            if (cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                error_line=__LINE__+1;
                throw invalid_argument("ERROR - Invalid option.");
            }

            int value;
            int pos;
            switch (option){
                case 1:
                    cout << "Value: ";
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
                    cout << "Value: ";
                    cin >> value;
                    cout << "Position: ";
                    cin >> pos;

                    //insert falla si la posicion es negativa.
                    if (!insert(list, value, pos)){
                        error_line=__LINE__+1;
                        throw invalid_argument("ERROR - Negative position.");
                    } 

                    //esta linea solo esta para que en el cout se vea la posicion correcta en caso de que la pos se salga de la lista.
                    if (pos>list->size) pos=list->size-1;

                    cout << "Value " << value << " was inserted at position " << pos << "." << endl;
                    break;
                case 6:
                    if (list_is_empty(list)){
                        cout << "List is empty." << endl;
                        break;
                    }
                    cout << "Position: ";
                    cin >> pos;

                    //erase falla si la posicion es negativa.
                    if (!erase(list, pos)){
                        error_line=__LINE__+1;
                        throw invalid_argument("ERROR - Negative position.");
                    } 

                    //esta linea solo esta para que en el cout se vea la posicion correcta en caso de que la pos se salga de la lista.
                    if (pos>list->size) pos=list->size-1;
                    
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
        //si detecto algun error lo informo, cierro el programa y loggeo el error.
        catch (invalid_argument &e){
            cout << e.what() << endl;
            logMessage(e.what(), __FILE__, error_line);
        }
        catch (...) {
            cout << "ERROR - Unexpected error." << endl;
            logMessage("Unexpected error", __FILE__, __LINE__);
        }
    }
}