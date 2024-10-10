#include <cstdio>

#ifndef SLL_H
#define SLL_H

template <typename T>
class SLinkedList {
    class Node {
    public:
        T data;
        Node* next;
        
        Node(T value, Node* n);
    };

    int length = 0;
    
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void addFront(T value);
    void addBack(T value);
    void removeBack();
    void removeFront();
    void traverse();
    void reverse();
    bool isEmpty();
    int size();
    ~SLinkedList();
};

#include "sll.tpp"

#endif
