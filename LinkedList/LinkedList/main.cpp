#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main() {
    LinkedList<int> list;

    cout << "Append 10, 20, 30\n";
    list.Append(10);
    list.Append(20);
    list.Append(30);

    cout << "List: ";
    for (int i = 0; i < list.Length(); i++)
        cout << list.At(i) << " ";
    cout << "\n\n";

    cout << "Insert 15 at pos 1\n";
    list.InsertAt(1, 15);

    cout << "List: ";
    for (int i = 0; i < list.Length(); i++)
        cout << list.At(i) << " ";
    cout << "\n\n";

    cout << "Insert 5 at pos 0\n";
    list.InsertAt(0, 5);

    cout << "List: ";
    for (int i = 0; i < list.Length(); i++)
        cout << list.At(i) << " ";
    cout << "\n\n";

    cout << "Delete at pos 2\n";
    list.DeleteAt(2);

    cout << "List: ";
    for (int i = 0; i < list.Length(); i++)
        cout << list.At(i) << " ";
    cout << "\n\n";

    cout << "Delete first element (pos 0)\n";
    list.DeleteAt(0);

    cout << "List: ";
    for (int i = 0; i < list.Length(); i++)
        cout << list.At(i) << " ";
    cout << "\n\n";

    cout << "Final length = " << list.Length() << endl;

    return 0;
}