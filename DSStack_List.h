#ifndef DSSTACK_LIST_H
#define DSSTACK_LIST_H
#include "DSList.h"

template <typename Object>
class DSStack_List{
    private:
    DSList<Object> stack;

    public:
        //add element (push_back)
        void push(Object x){
            stack.push_back(x);
        }

        //return top element (last element added)
        Object peek(){
            int size = stack.listSize();
            return stack[size-1];
        }

        //remove top element (last element added)
        void pop(){
            stack.pop_back();
        }

        //is it empty?
        bool empty(){
            return stack.empty();
        }

        //remove all elements
        void clear(){
            stack.clear();
        }
};
#endif