#include "../Linked List/Singly/sll.h"
#include <cstdio>
#include <stdlib.h>

template <typename T>
class Stack{
    SLinkedList<T> sll;
public:
    void push(T value){
        sll.addBack(value);
    }
    // BETTER TO USE DOUBLY LINKED LIST FOR STACK BECAUSE REMOVEBACK IS O(N) FOR SINGLY LINKEDL IST, BUT O(1) FOR DOUBLY LINKED LIST
    void pop(){
        sll.removeBack();
    }
    T peek(){
        try {
            if (isEmpty())
                throw sll.size();
            return sll.tail->data;
        }
        catch(int){
            printf("Cant peek on an empty stack!\n");
            exit(1);
        }
    }
    bool isEmpty(){
        return sll.isEmpty();
    }
    int size(){
        return sll.size();
    }
};

int main(){
    Stack<int> x;
    x.push(5);
    x.push(69);
    printf("%d\n", x.size());
}