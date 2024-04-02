#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// add includes
#include "DSStack_array.h"
using namespace std;

TEST_CASE("Check that DSStack_array works", "[DSStack_array]")
{
    // add test cases (create lists and specify what the expected output is)
    //test cases for int stack
    DSStack_array<int> testInt;
    testInt.push(1);
    testInt.push(2);
    testInt.push(3);
    REQUIRE(testInt.peek() == 3);
    testInt.push(4);
    testInt.push(5);
    testInt.pop();
    REQUIRE(testInt.peek() == 4);
    testInt.clear();
    REQUIRE(testInt.empty() == true);

    //test cases for string stack
    DSStack_array<string> testString;
    testString.push("one");
    testString.push("two");
    testString.push("three");
    REQUIRE(testString.peek() == "three");
    testString.push("four");
    testString.push("five");
    testString.pop();
    REQUIRE(testString.peek() == "four");
    testString.clear();
    REQUIRE(testString.empty() == true);

    //test cases for char stack
    DSStack_array<char> testChar;
    testChar.push('!');
    testChar.push('@');
    testChar.push('#');
    REQUIRE(testChar.peek() == '#');
    testChar.push('$');
    testChar.push('%');
    testChar.pop();
    REQUIRE(testChar.peek() == '$');
    testChar.clear();
    REQUIRE(testChar.empty() == true);

}

// you can run the test using Run CTest in the task bar or by running the tests executable. 
