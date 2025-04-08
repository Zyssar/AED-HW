#include <iostream> //esto para debuggear :p

using namespace std;

template <typename T>
struct node {
    T data;
    node* next;
};

template <typename T>
class forwardList {
private:
    node<T>* head;
public:
    forwardList() {
        head = nullptr;
    }

    T front() {
        if (head==nullptr){throw out_of_range();}
        return head->data;
    }

    T back() {
        node<T>* temp = head;
        if (head==nullptr){throw out_of_range();}
        while (temp->next!=nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(T data) {
        auto* temp = new node<T>;
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    void push_back(T data) {

        auto* newNode = new node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        if (head==nullptr) {
            head = newNode;
            return head;
        }
        else{
            node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
        }
        temp-> next = newNode;
    }

    T pop_front() {
        if (head==nullptr){throw out_of_range();}
        node<T>* temp = head;
        head = head->next;
        T data = temp->data;
        delete temp;
        return data;
    }

    T pop_back() {
        if(head==nullptr){throw out_of_range();}
        if (head->next == nullptr) {
            T data = head->data;
            delete head;
            head = nullptr;
            return data;
        }
        node<T>* temp = head;
        node<T>* last = head;
        while (temp->next->next!=nullptr) {
            temp=temp->next;
            cout << endl << "working" << endl;
        }
        last = temp->next;
        T data = last->data;

        delete last;
        temp->next = nullptr;
        return data;
    }

    T operator[](const int index) {
        node<T>* temp = head;
        for (int i = 0; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp==nullptr) {
            return NULL;
        }
        return temp->data;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        node<T>* temp = head;
        int sz=0;
        while (temp!=nullptr) {
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    void clear() {
        while (head!=nullptr) {
            node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void sort() {
        head = mergeSort(head);
    }

    node<T> *mergeSort(node<T> *head) {
        if (head==nullptr || head->next==nullptr) {
            return head;
        }
        node<T>* second = split(head);
        head = mergeSort(head);
        second = mergeSort(second);

        return merge(head,second);
    }

    node<T> *merge(node<T> *half1, node<T> *half2) {
        if (half1 == nullptr){return half2;}
        if (half2 == nullptr){return half1;}

        if ((half1->data) < (half2->data)) {
            half1->next = merge(half1->next, half2);
            return half1;
        }else {
            half2->next = merge(half1, half2->next);
            return half2;
        }
    }

    node<T>* split(node<T>* head) {
        if(!head || !head->next) return nullptr;
        node<T>* slow = head;
        node<T>* fast = head->next;
        while (fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        node<T>* temp = slow->next;
        slow->next = nullptr;
        return temp; // dos punteros comienzan a recorrer la lista 2 en 2 y el otro 1 en en 1
        // cuando el primero termina el segundo se queda en la mitad
        //se parte el slow o el segundo haciendo que ya no apunte a nada
        //previamente haciendo que un head temporal sea el siguiente de slow
        //head queda como quedo solo que ahora la mitad ya no apunta a nada
        //y se retorna temp que es la cabeza de lo que era fast, la segund mitad
    }



    void reverse() {
        forwardList temp;
        node<T>* tempNode = head;
        while (head!=nullptr) {
            temp.push_front(head->data);
            head = head->next;
            delete tempNode;
            tempNode = head;
        }
        head = temp.head;
    }

};


int main() {

}