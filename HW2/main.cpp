#include <iostream>

template <typename T>
struct Node{
    T val;
    Node* prev;
    Node* next;
    Node() : val(), prev(nullptr), next(nullptr) {}
    Node(const T& value): val(value), prev(nullptr), next(nullptr){}
};

template <typename T>
class DoubleLinkedList{
private:
    Node<T> head;
    Node<T> tail;
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {} //constructor base

    T front(){

    }

    T back(){

    }

    void push_front(T){

    }

    void push_back(T){

    }

    T pop_front(){

    }

    T pop_back(){

    }

    void insert(T, int){

    }

    void remove(int){

    }

    T operator[](int){

    }

    bool empty(){

    }

    int size(){

    }

    void clear(){

    }

    void reverse(){
        
    }
};