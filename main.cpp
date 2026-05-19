#include <iostream>
#include "BST.h"

using namespace std;

int main() {

    BST<int> t;

    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    cout << "Inorder: ";
    t.inorder();
    cout << endl;

    cout << "Preorder: ";
    t.preorder();
    cout << endl;

    cout << "Postorder: ";
    t.postorder();
    cout << endl;

    cout << "Search 60: "
         << t.search(60) << endl;

    cout << "\nDelete 20" << endl;
    t.remove(20);
    t.inorder();
    cout << endl;

    cout << "\nDelete 30" << endl;
    t.remove(30);
    t.inorder();
    cout << endl;

    cout << "\nDelete 50" << endl;
    t.remove(50);
    t.inorder();
    cout << endl;

    return 0;
}
