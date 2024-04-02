#include <iostream>
#include <algorithm>
#include <chrono>
#include <ratio>

#include "DSList.h"
#include "DSStack_List.h"
#include "DSStack_array.h"
#include "check_brackets.cpp"

using namespace std;

// file names to check are passed on as command line arguments
int main(int argc, char **argv)
{
    if(argc < 2){
        return 1;
    }
    check_brackets checker;
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < argc; ++i){
        //start timer, run checker, end timer for list and array implementation
        auto start = std::chrono::high_resolution_clock::now();
        checker.checkListStack(argv[i]);
        auto stop = std::chrono::high_resolution_clock::now();
        auto int_dur = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);        
        std::cout << argv[i] << " - checking using list implementation took " << int_dur.count() << " milliseconds" << endl;

        start = std::chrono::high_resolution_clock::now();
        checker.checkArrayStack(argv[i]);
        stop = std::chrono::high_resolution_clock::now();
        int_dur = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);        
        std::cout << argv[i] << " - checking using list implementation took " << int_dur.count() << " milliseconds" << endl;
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(stop1-start1); 
    cout << "Checking all files took " << dur.count() << " milliseconds" << endl;
    return 0;
}

// in the terminal type `cd build` and then `./check_brackets test_data/*`