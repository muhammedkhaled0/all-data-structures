#include <iostream>
#include "BST.cpp"
using namespace std;

int main() {
    BST<int> tree;

    cout << "==== TEST: empty() ====" << endl;
    cout << "Is empty? " << tree.empty() << endl;

    cout << "\n==== INSERT NODES ====" << endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Length: " << tree.length() << endl;

    cout << "\n==== INORDER (sorted) ====" << endl;
    tree.traverse(0);

    cout << "\n==== PREORDER ====" << endl;
    tree.traverse(1);

    cout << "\n==== POSTORDER ====" << endl;
    tree.traverse(2);

    cout << "\n==== CONTAINS TEST ====" << endl;
    cout << "Contains 40? " << tree.contains(40) << endl;
    cout << "Contains 100? " << tree.contains(100) << endl;

    cout << "\n==== FIND NODE TEST ====" << endl;
    Node<int>* found = tree.findNode(60);
    if (found)
        cout << "Found node: " << found->data << endl;

    cout << "\n==== REMOVE LEAF NODE (20) ====" << endl;
    tree.remove(20);
    tree.traverse(0);

    cout << "\n==== REMOVE NODE WITH ONE CHILD (30) ====" << endl;
    tree.remove(30);
    tree.traverse(0);

    cout << "\n==== REMOVE NODE WITH TWO CHILDREN (70) ====" << endl;
    tree.remove(70);
    tree.traverse(0);

    cout << "\n==== REMOVE ROOT (50) ====" << endl;
    tree.remove(50);
    tree.traverse(0);

    cout << "\n==== FINAL LENGTH ====" << endl;
    cout << tree.length() << endl;

    cout << "\n==== FINAL TREE EMPTY CHECK ====" << endl;
    cout << "Is empty? " << tree.empty() << endl;

    return 0;
}