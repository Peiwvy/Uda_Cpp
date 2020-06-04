/*
Doubly linked lists
Doubly linked list is a type of data structure that is made up of so called objects
that are created using self referential structures. Each of these nodes contain three
attributes, namely the value and the reference to the next list object and the reference
to the previous list object.

Because the list is linked in both directions, any node has the ability to access any
other node. That means that the user of a doubly linked list need only keep track of
a single node.

The last node in the list points forward to nothing, which can be represented by nullptr.
The same is true for the first node in the list, which points backward to nothing.

In this exercise you will create a doubly linked list, which exposes 4 methods:

    push_back(): add values to the end of the list
    push_front(): add values to the beginning to the list
    pop_back(): delete values from the end of the list
    pop_front(): delete values from the front of the list

Also, you will implement a helper function, empty(), which returns whether or not
the list has any nodes.

Steps
    Declare class List to represent the doubly linked list
    Declare struct Node to represent the nodes in the list
    Declare a constructor for struct Node
    Declare a member variable head that belongs to class List and points to the first node in the list
    Declare a member variable head that belongs to class List and points to the first node in the list
    Declare a constructor for the doubly linked list
    Declare a destructor for class List
    Implement the class List destructor to delete all of the nodes in the list
    Declare List::PushFront() to push nodes onto the front of the list
    Declare List::PushBack() to push nodes onto the back of the list
    Declare List::PopFront() to delete nodes from the front of the list
    Declare List::PopBack() to delete nodes from the back of the list
    Declare List::Size() to count the number of nodes in the list
    Test that all member functions in class List behave properly, even if the list is empty

*/
#include <iostream>

namespace custom {
    template<typename T>
    class list {
        // This class will have node structure
        struct node {
            
            // node attributes
            T value;
            node* prev;
            node* next;

            // constructors for initialization of these attributes
            node (T val, node* _prev, node* _next) : value(val), prev(_prev), next(_next) {}
        };

        // second attribute of the list is head, which points to the beginning of the list
        node *head;

        // thrid attribute of the list is tail, which points to the end of the list
        node *tail;

        public:
        
        // default list constructor and destructor
        list() : head(NULL), tail(NULL) {}
        ~list();

        /* ---- method declaration --- */
        void push_front(T);
        void push_back(T);
        T pop_back();
        T pop_front();
        bool empty() const { return (!head || !tail); }
        void print();
    };

    /* --- class method definition --- */
    template<typename T>
    void list<T>::push_front(T value) {
        head = new node(value, NULL, head);

        if(head->next) {
            head->next->prev = head;
        }

        if(list<T>::empty()) {
            tail = head;
        }
    }

    template<typename T>
    void list<T>::push_back(T value) {
        tail = new node(value, tail, NULL);

        if(tail->prev) {
            tail->prev->next = tail;
        }

        if(list<T>::empty()) {
            head = tail;
        }
    }

    template<typename T>
    list<T>::~list() {
        while(head) {
            node* temp(head);
            head = head->next;
            delete temp;
        }
    }

    template<typename T>
    T list<T>::pop_back() {
        if(list::empty()) {
            throw("list : list empty");
        }

        node *temp(tail);
        T value = tail->value;
        tail = tail->prev;

        if(tail) {
            tail->next = NULL;
        }
        else {
            head = NULL;
        }

        delete temp;
        return value;
    }

    template<typename T>
    T list<T>::pop_front() {
        if(list::empty()) {
            throw("list: list empty");
        }

        node *temp(head);
        T value = head->value;
        head = head->next;

        if(head) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }

        delete temp;
        return value;
    }

    template<typename T>
    void list<T>::print() {
        node* ptr(head);

        while(ptr != NULL) {
            std::cout << ptr->value << " ";
            ptr = ptr->next;
        }
        std::cout << "\n";
    }
}

/* --- main function --- */
int main() {
    custom::list<int> list;
    list.push_back(8);
    list.push_back(7);
    list.push_front(6);
    std::cout << "List contains: ";
    list.print();
    std::cout << "Removing last element: " << list.pop_back() << "\n";
    std::cout << "Now List contains: ";
    list.print();
}
// List contains: 6 8 7 
// Removing last element: 7
// Now List contains: 6 8 