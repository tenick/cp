#include "sll.h"

template <typename T>
SLinkedList<T>::Node::Node(T value, Node* n)
    : data(value), next(n) {}

template <typename T>
void SLinkedList<T>::addFront(T value){
    if (isEmpty()) 
        head = tail = new Node(value, nullptr);
    else
        head = new Node(value, head);
    length++;
}

template <typename T>
void SLinkedList<T>::addBack(T value){
    if (isEmpty())
        head = tail = new Node(value, nullptr);
    else {
        tail->next = new Node(value, nullptr);
        tail = tail->next;
    }
    length++;
}

template <typename T>
void SLinkedList<T>::removeBack(){
    if (!isEmpty()){
        Node* h = head;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        }
        else {
            while(h->next != tail)
                h = h->next;
            
            delete tail;
            tail = h;
            tail->next = nullptr;
        }
        length--;
    }
}

template <typename T>
void SLinkedList<T>::removeFront(){
    if (!isEmpty()){
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } 
        else {
            Node* next = head->next;
            delete head;
            head = next;
        }
        length--;
    }
}

template <typename T>
void SLinkedList<T>::traverse(){
    if (!isEmpty()) {
        Node* node = head;
        int count = 0;
        printf("[ ");
        while (node != nullptr) {
            if (count != length - 1)
                printf("%d, ", node->data);
            else
                printf("%d", node->data);
            node = node->next;
            count += 1;
        }
        printf(" ]\n");
    }
    else {
        printf("[ ]\n");
    }
}
template <typename T>
void SLinkedList<T>::reverse(){
    Node* temp = nullptr;
    tail = head;

    while (head != nullptr) {
        Node* next = head->next;
        head->next = temp;
        temp = head;
        head = next;
    }
    head = temp;
}

template <typename T>
bool SLinkedList<T>::isEmpty(){
    return length == 0;
}

template <typename T>
int SLinkedList<T>::size(){
    return length;
}

template <typename T>
SLinkedList<T>::~SLinkedList(){
    delete head;
    delete tail;
}
