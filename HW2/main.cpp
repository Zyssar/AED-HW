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
    Node<T>* head;
    int count; //cuenta de nodos actuales
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

    void insert(T elem, int index){
        if(head==nullptr){
            Node* temp = new Node<T>(elem);
            head = temp;
        }else{
            if((count < index || index < 0){
                throw std::out_of_range("Fuera de rango");
            } //no inserta si es que la posición esta fuera de rango
            Node* temp = head;
            int i = 0;
            while(i != index){
                temp = temp->next;
                i++;
            }
            Node* newN = new Node*;
            newN->val = elem;
            if(temp->prev){
                newN->prev = temp->prev;
                temp->prev->next = newN;
            }
            newN->next = temp;
            temp->prev = newN;
            count++;
        }
    }

    void remove(int index){
        if(count < index || index < 0){
            throw std::out_of_range("Fuera de rango");
        } //no remueve si es que la posición esta fuera de rango
        Node* temp = head;
        int i = 0;
        while(i != index){
            temp = temp->next;
            i++;
        }
        if(temp->prev && temp->next){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
        count--;
    }

    T operator[](int index){   
        if(count < index || index < 0){ 
            throw std::out_of_range("Fuera de rango");
        } //no retorna si es que la posición esta fuera de rango
        Node* temp = head;
        int i = 0;
        while(i != index){
            temp = temp->next;
            i++;
        }
        return temp->val;
    }

    bool empty(){

    }

    int size(){

    }

    void clear(){

    }

    void reverse(){
        Node* temp = head;
        Node* newHead = nullptr;
        while(temp!=nullptr){
            Node* ptrSave = temp->next;
            temp->next = temp->prev;
            temp->prev = ptrSave; //intercambia punteros next y prev por cada iteracion
            
            newHead = temp;
            temp = temp->prev;
        }
        head = newHead;
    }
};


