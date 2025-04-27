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
        if(size ==0){
            throw out_of_range("La lista esta vacia");
        }

        Node* toDelete = sentinel ->next;

        // Actualizamos los enlaces de los punteros

        sentinel ->next = toDelete->next;
        toDelete->next->prev = sentinel;

        delete toDelete;
        size--;

    }

    T pop_back(){
        if(size ==0){
            throw out_of_range("La lista esta vacia");
        }

        Node* toDelete = sentinel ->next;

        // Actualizamos los enlaces de los punteros

        sentinel ->  prev = toDelete->next;
        toDelete -> prev->next = sentinel;

        delete toDelete;
        size--;

    }

    void insert(T elem, int index){
        if (index < 0 || index > size) {
            throw out_of_range("Fuera de rango");
        }

        Node* current = sentinel->next;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        Node* newNode = new Node(elem);

        newNode->prev = current->prev;
        newNode->next = current;

        current->prev->next = newNode;
        current->prev = newNode;

        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Fuera de rango");
        }

        Node* current = sentinel->next;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
        --size;
    }

    T operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Fuera de rango");
        }

        Node* current = sentinel->next;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->data;
    }

    int list_size() {
        return size;
    }

    void reverse() {
        Node* current = sentinel;
        while (true) {
            Node* temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
            if (current == sentinel) {
                break;
            }
        }
    }
};