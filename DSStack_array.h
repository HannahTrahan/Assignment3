// Implement a stack based on an array.
#ifndef DSSTACK_ARRAY_H
#define DSSTACK_ARRAY_H

template <typename Object>
class DSStack_array{
    private:
        int len;
        int capacity;
        Object *array;
    public:
        //default constructor:
        DSStack_array(){
            len = 0;
            capacity = 10;
            array = new Object[capacity];
        }

        //rule of three: destructor
        ~DSStack_array(){
            delete[] array;
        }

        //rule of three: copy constructor
        DSStack_array(const DSStack_array &rhs){
            len = rhs.len;
            capacity == rhs.capacity;
            array = new Object[capacity];
            for(int i=0; i<len; i++){
                array[i] = rhs[i];
            }
        }

        //rule of three: copy assignment operator
        DSStack_array &operator=(const DSStack_array &rhs){
            if(this == &rhs){return *this;}
            delete[] array;
            len = rhs.len;
            capacity == rhs.capacity;
            array = new Object[capacity];
            for(int i=0; i<len; i++){
                array[i] = rhs[i];
            }
            return *this;
        }

        //add object
        void push(Object x){
            array[len] = x;
            len++;
            if(len == capacity){
                resize();
            }
        }
        
        //remove top object
        void pop(){
            if(len == 0){
                std::cerr << "error, stack is empty" << std::endl;
            }
            else{
                len--;
            }
        }

        //return top object
        Object peek(){
            if(len == 0){
                std::cerr << "error, stack is empty" << std::endl;
            }
            return array[len-1];
        }
        
        //returns true if no objects in the stack
        bool empty(){
            if(len == 0){return true;}
            else{return false;}
        }
        
        //removes all objects
        void clear(){
            delete[] array;
            len = 0;
            capacity = 10;
            array = new Object[capacity];
        }
        
        //increases capacity
        void resize(){
            capacity*=2;
            Object* temp = new Object[capacity];
            for(int i=0; i<len; i++){
                temp[i] = array[i];
            }
            array = temp;
        }
};
#endif