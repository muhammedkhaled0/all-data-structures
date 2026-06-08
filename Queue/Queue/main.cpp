#include <iostream>
#include "Queue.cpp"
using namespace std;

int main() {
    Queue<int> q;

    cout << "Enqueue: 10, 20, 30" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.Front() << endl;

    cout << "\nDequeue one element" << endl;
    q.dequeue();

    cout << "Front element after dequeue: " << q.Front() << endl;

    cout << "\nEnqueue: 40, 50, 60, 70, 80" << endl;
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    cout << "Queue contents: ";
    while (!q.empty()) {
        cout << q.Front() << " ";
        q.dequeue();
    }
    cout << endl;
    return 0;
}