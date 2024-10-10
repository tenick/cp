#include "../Linked List/Singly/sll.h"
#include <cstdlib>

template <typename T>
class Queue{
    SLinkedList<T> x;
public:
    void enqueue(T value){
        x.addBack(value);
    }
    void dequeue(){
        if (isEmpty()){
            printf("Can't dequeue an empty queue.\n");
            exit(1);
        }
        x.removeFront();
    }
    T peek(){
        if (isEmpty()){
            printf("Can't peek on empty queue.\n");
            exit(1);
        }
        return x.head->data;
    }
    int size(){
        return x.size();
    }
    bool isEmpty(){
        return x.isEmpty();
    }
};

int main(){
    Queue<int> x;
    x.enqueue(5);
    x.enqueue(69);
    x.enqueue(420);
    printf("%d\n", x.peek());
}