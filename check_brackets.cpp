#include "check_brackets.h"

//check using list implementation
int check_brackets::checkListStack(char *fileName){
    //open file
    ifstream file;
    file.open(fileName);
    if(!file.is_open()){
        std::cerr << "error, file not open" << std::endl;
    }
    //read line by line
    vector<char> openBrackets = {'[', '(', '{'};
    vector<char> closeBrackets = {']', ')', '}'};
    string currLine;
    int lineNum = 0;
    listStack.clear();
    DSStack_List<int> lineNumbers;
    while(getline(file, currLine)){
        lineNum++;
        for(size_t i=0; i<currLine.size(); i++){
            //if there is an open bracket/parenthesis
            if(currLine.at(i) == '[' || currLine.at(i) == '(' || currLine.at(i) == '{'){
                listStack.push(currLine.at(i));
                lineNumbers.push(lineNum);
            }
            //if there is a closing bracket/parenthesis
            else if(currLine.at(i) == ']' || currLine.at(i) == ')' || currLine.at(i) == '}'){
                //if stack is empty, there is a stray closing bracket/parenthesis
                if(listStack.empty()){
                    cout << fileName << ": stray closing bracket " << currLine.at(i) << " in line " << lineNum << endl;
                    return 1;
                }
                //if stack is not empty but the brackets/parentheses don't match
                else if((listStack.peek() == '[' && currLine.at(i) != ']') || (listStack.peek() == '(' && currLine.at(i) != ')') || (listStack.peek() == '{' && currLine.at(i) != '}')){
                    cout << fileName << ": bracket mismatch for " << listStack.peek() << "in line " << lineNum << endl;
                    return 1;
                }
                //if brackets/parenthesis match
                else{
                    listStack.pop();
                    lineNumbers.pop();
                }
            }
        }
    }
    if(listStack.empty()){
        cout << fileName << ": OK" << endl;
    }
    else{
        cout << fileName << ": stray open bracket " << listStack.peek() << " at line " << lineNumbers.peek() << endl;
        return 1;
    }
    file.close();
    return 0;
}

//check using array implementation
int check_brackets::checkArrayStack(char *fileName){
    //open file
    ifstream file;
    file.open(fileName);
    if(!file.is_open()){
        std::cerr << "error, file not open" << std::endl;
    }
    //read line by line
    vector<char> openBrackets = {'[', '(', '{'};
    vector<char> closeBrackets = {']', ')', '}'};
    string currLine;
    int lineNum = 0;
    arrayStack.clear();
    DSStack_array<int> lineNumbers;
    while(getline(file, currLine)){
        lineNum++;
        for(size_t i=0; i<currLine.size(); i++){
            //if there is an open bracket/parenthesis
            if(currLine.at(i) == '[' || currLine.at(i) == '(' || currLine.at(i) == '{'){
                arrayStack.push(currLine.at(i));
                lineNumbers.push(lineNum);
            }
            //if there is a closing bracket/parenthesis
            else if(currLine.at(i) == ']' || currLine.at(i) == ')' || currLine.at(i) == '}'){
                //if stack is empty, there is a stray closing bracket/parenthesis
                if(arrayStack.empty()){
                    cout << fileName << ": stray closing bracket " << currLine.at(i) << " in line " << lineNum << endl;
                    return 1;
                }
                //if stack is not empty but the brackets/parentheses don't match
                else if((arrayStack.peek() == '[' && currLine.at(i) != ']') || (arrayStack.peek() == '(' && currLine.at(i) != ')') || (arrayStack.peek() == '{' && currLine.at(i) != '}')){
                    cout << fileName << ": bracket mismatch for " << arrayStack.peek() << "in line " << lineNum << endl;
                    return 1;
                }
                //if brackets/parenthesis match
                else{
                    arrayStack.pop();
                    lineNumbers.pop();
                }
            }
        }
    }
    if(arrayStack.empty()){
        cout << fileName << ": OK" << endl;
    }
    else{
        cout << fileName << ": stray open bracket " << arrayStack.peek() << " at line " << lineNumbers.peek() << endl;
        return 1;
    }
    file.close();
    return 0;
}