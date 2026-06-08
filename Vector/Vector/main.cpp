#include <iostream>
#include "Vector.cpp"

using namespace std;

int main() {
    Vector<int> v;

    cout << "Is empty? " << v.empty() << endl;

    // Append elements
    v.Append(10);
    v.Append(20);
    v.Append(30);
    v.Append(40);

    cout << "Length after append: " << v.Length() << endl;

    // Access elements
    cout << "Element at index 0: " << v.At(0) << endl;
    cout << "Element at index 2: " << v.At(2) << endl;

    // Insert in middle
    v.insertAt(2, 99);

    cout << "After insertAt(2, 99):" << endl;
    for (int i = 0; i < v.Length(); i++) {
        cout << v.At(i) << " ";
    }
    cout << endl;

    // Delete element
    v.deleteAt(1);

    cout << "After deleteAt(1):" << endl;
    for (int i = 0; i < v.Length(); i++) {
        cout << v.At(i) << " ";
    }
    cout << endl;

    cout << "Final length: " << v.Length() << endl;

    return 0;
}