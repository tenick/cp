#include "sll.h"
#include <cstdio>

// add insert at index, remove front, back, at index, search, update
// optional: sort
// optional: different constructors same as dynamicArray needs

int main(){
    SLinkedList<int> x;
    x.addBack(69);
    x.addBack(70);
    x.addBack(420);
    x.addFront(6999);
    x.traverse();
    x.reverse();
    x.traverse();
    x.removeBack();
    x.traverse();
    x.removeFront();
    x.traverse();
    x.removeFront();
    x.traverse();
    x.removeBack();
    
    printf("%d\n", x.size());
    printf("%d\n", x.head);
}