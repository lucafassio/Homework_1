#include "squaremtx.cpp"

int main(){
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;
    vector<int> mtx=create_mtx(size);
    print_mtx(mtx, size);
    cout << "The matrix has been created successfully!" << endl;
    cout << mtx[6] << endl;

    // node_t *nodo = create_node(5);
    // cout << nodo->value << endl;
    return 0;
}