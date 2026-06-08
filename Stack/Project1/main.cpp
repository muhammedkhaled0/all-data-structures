#include <iostream>
#include "Stack.cpp"

using namespace std;

int main() {
    Stack<int> s;

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << "Length = " << s.Length() << endl;
    cout << "Top = " << s.Top() << endl;

    s.Pop();

    cout << "After Pop:" << endl;
    cout << "Length = " << s.Length() << endl;
    cout << "Top = " << s.Top() << endl;

    while (!s.empty()) {
        cout << s.Top() << " ";
        s.Pop();
    }

    cout << endl;

    return 0;
}