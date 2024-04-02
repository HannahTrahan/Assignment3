#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// add includes
#include "DSList.h"
using namespace std;

TEST_CASE("Check that DSList works", "[DSList]")
{
    // add test cases (create lists and specify what the expected output is)
    //test cases for int stack
    DSList<int> testInt;
    testInt.push_front(1);
    testInt.push_back(2);
    testInt.push_front(3);
    REQUIRE(testInt[0] == 3);
    testInt.push_front(4);
    testInt.pop_back();
    testInt.pop_front();
    REQUIRE(testInt.listSize() == 2);
    testInt.push_front(5);
    REQUIRE(testInt.find(3) == 1);
    testInt.clear();
    REQUIRE(testInt.empty() == true);

    //test cases for string stack
    DSList<string> testString;
    testString.push_front("one");
    testString.push_back("two");
    testString.push_front("three");
    REQUIRE(testString[0] == "three");
    testString.push_front("four");
    testString.pop_back();
    testString.pop_front();
    REQUIRE(testString.listSize() == 2);
    testString.push_front("five");
    REQUIRE(testString.find("three") == 1);
    testString.clear();
    REQUIRE(testString.empty() == true);

    //test cases for char stack
    DSList<char> testChar;
    testChar.push_front('!');
    testChar.push_back('@');
    testChar.push_front('#');
    REQUIRE(testChar[0] == '#');
    testChar.push_front('$');
    testChar.pop_back();
    testChar.pop_front();
    REQUIRE(testChar.listSize() == 2);
    testChar.push_front('%');
    REQUIRE(testChar.find('#') == 1);
    testChar.clear();
    REQUIRE(testChar.empty() == true);
}

// you can run the test using Run CTest in the task bar or by running the tests executable. 