#ifndef DSLIST_H
#define DSLIST_H

/**
 * @brief Singly-linked list that uses positions and has a stack interface
 *
 * Implement all described functions and provide a test program using CATCH2
 * 
 * @tparam Object 
 */
template <typename Object>
class DSList
{
private:
   /**
     * @brief The nested Node data structure
     * 
     * struct is in C++ a class with all public members
     */
    struct Node
    {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {};
    };
    
    Node *head;
    int size;

public:
    // Default constructor
    DSList(){
        head = nullptr;
        size = 0;
    }

    // Rule-of-3: copy constructor
    DSList(const DSList &rhs){
        if(rhs.size == 0){
            std::cout<<"error, empty stack"<<std::endl;
        }
        else{
            head = rhs.head;
            size = rhs.size;
        }
    }

    // Rule-of-3: copy assignment operator
    DSList &operator=(const DSList &rhs){
        clear();
        if(rhs.size == 0){
            std::cout<<"error, empty stack"<<std::endl;
        }
        else{
            head = rhs.head;
            size = rhs.size;
        }
    }

    // Rule-of-3: destructor
    ~DSList(){
        clear();
    }

    //brackets operator
    Object &operator[](const int x){
        if(x < 0 || x >= size){
            std::cout<<"error, index out of bounds"<<std::endl;
        }
        Node *curr = head;
        for(int i=0; i<x && curr != nullptr; i++){
            curr = curr->next;
        }
        return curr->data;
    }

    // size
    int listSize(){
        return size;
    }

    // is the list empty?
    bool empty(){
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }

    // clear the whole list
    void clear(){
        while(!empty()){
            pop_front();
        }
        size = 0;
    }

    // find an element with a specific value (and return the position. First element in list is pos 0). Not found returns -1.
    int find(const Object &x){
        if(size == 0){
            std::cout<<"error, empty stack"<<std::endl;
        }
        int pos = 0;
        Node *curr = head;
        while(curr != nullptr){
            if(curr->data == x){
                return pos;
            }
            else{
                curr = curr->next;
                pos++;
            }
        }
        return -1;
    }

    // insert at the beginning of the list (push_front).
    void push_front(const Object &x){
        Node *newNode = new Node(x, head);
        head = newNode;
        size++;
    }

    // insert at the end of the list (push_back).
    void push_back(const Object &x){
        Node *newNode = new Node(x, nullptr);
        Node *curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
        size++;
    }

    // remove the first element(pop_front)
    void pop_front(){
        if(size == 0){
            std::cout<<"error, empty stack"<<std::endl;
        }
        Node *temp = head->next;
        delete head;
        head = temp;
        size--;
    }

    // remove the last element (pop_back)
    void pop_back(){
        if(size == 0){
            std::cout<<"error, empty stack"<<std::endl;
        }
        if(size == 1){
            delete head;
            head = nullptr;
        }
        else{
            Node *secondLast = head;
            Node *last = head->next;
            while(last->next != nullptr){
                secondLast = last;
                last = last->next;
            }
            secondLast->next = nullptr;
            delete last;
        }
        size--;
    }

};

#endif
