#include <iostream>
using namespace std;
template <typename T>

class CircularDoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };

    Node* sentinel;
    int size;

public:
    CircularDoublyLinkedList() {
        sentinel = new Node();
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        size = 0;
    }

    bool empty() const {
        return size == 0;
    }

    T front() const {
        if (empty()) {
            throw runtime_error("La lista está vacía");
        }
        return sentinel->next->data;
    }


    T back() const {
        if (empty()) {
            throw runtime_error("La lista está vacía");
        }
        return sentinel->prev->data;
    }

    void push_front(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        Node* first = sentinel->next;
        newNode->prev = sentinel;
        newNode->next = first;
        first->prev = newNode;
        sentinel->next = newNode;
        size++;
    }
    void push_back(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        Node* last = sentinel->prev;
        newNode->prev = last;
        newNode->next = sentinel;
        last->next = newNode;
        sentinel->prev = newNode;
        size++;
    }

    void clear() {
        Node* curr = sentinel->next;
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        size = 0;

        while(curr != sentinel) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    T pop_front(){

    }

    T pop_back(){

    }

    void insert() {

    }
    void remove() {

    }

    T operator[](int index) {

    }

    int list_size() {

    }

    void reverse() {

    }
};