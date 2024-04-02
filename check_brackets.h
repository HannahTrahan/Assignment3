#ifndef CHECK_BRACKETS_H
#define CHECK_BRACKETS_H

#include <iostream>
#include <fstream>
#include <vector>
#include "DSList.h"
#include "DSStack_List.h"
#include "DSStack_array.h"

using namespace std;

class check_brackets{

    private:
        DSStack_List<char> listStack;
        DSStack_array<char> arrayStack;

    public:
        int checkListStack(char *fileName);
        int checkArrayStack(char *fileName);

};
#endif