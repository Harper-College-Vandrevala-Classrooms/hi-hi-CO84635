#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <cctype>

using namespace std;

int strcmp_case_insensitive(string string_1, string string_2, bool skip_spaces = false) {
    char cStringOne[string_1.length() + 1];
    char cStringTwo[string_2.length() + 1];

    int indexOne = 0;
    for (int i = 0; i < string_1.length(); i++) {
        if (!(skip_spaces && string_1[i] == ' ')) {
            cStringOne[indexOne++] = tolower(string_1[i]);
        }
    }
    cStringOne[indexOne] = '\0';

    int indexTwo = 0;
    for (int i = 0; i < string_2.length(); i++) {
        if (!(skip_spaces && string_2[i] == ' ')) {
            cStringTwo[indexTwo++] = tolower(string_2[i]);
        }
    }
    cStringTwo[indexTwo] = '\0';

    int result = strcmp(cStringOne, cStringTwo);

    if (result == 0) {
        return 0;
    } else if ( result > 0) {
        return 1;
    } else {
        return -1;
    }
}

int main () {
    assert(strcmp_case_insensitive("my cool string", "mycoolstring", true) == 0);
    assert(strcmp_case_insensitive("My Cool String", "MyCoolString", true) == 0);
    assert(strcmp_case_insensitive("My Cool String", "mycoolstring", true) == 0);
    assert(strcmp_case_insensitive("My Cool String ", "mycoolstring", true) == 0);
    assert(strcmp_case_insensitive(" My Cool String", "mycoolstring", true) == 0);
    assert(strcmp_case_insensitive("Another string", "mycoolstring", true) != 0);

    assert(strcmp_case_insensitive("coffee", "coffee") == 0);
    assert(strcmp_case_insensitive("Coffee ", "coffee") != 0);

    assert(strcmp_case_insensitive("coffee", "coffee") == 0);
    assert(strcmp_case_insensitive("water", "water") == 0);
    assert(strcmp_case_insensitive("milk", "milk") == 0);
    assert(strcmp_case_insensitive("COFFEE", "COFFEE") == 0);
    assert(strcmp_case_insensitive("WATER", "WATER") == 0);
    assert(strcmp_case_insensitive("MILK", "MILK") == 0);
    assert(strcmp_case_insensitive("Coffee", "coffee") == 0);
    assert(strcmp_case_insensitive("Water", "water") == 0);
    assert(strcmp_case_insensitive("Milk", "milk") == 0);
    assert(strcmp_case_insensitive("coffee", "Coffee") == 0);
    assert(strcmp_case_insensitive("water", "Water") == 0);
    assert(strcmp_case_insensitive("milk", "Milk") == 0);

    assert(strcmp_case_insensitive("string one", "string two") == -1);
    assert(strcmp_case_insensitive("string one", "string one") == 0);
    assert(strcmp_case_insensitive("string two", "string one") == 1);

    assert(strcmp_case_insensitive("hello", "hello") == 0);
    assert(strcmp_case_insensitive("Hi", "hi") == 0);
    assert(strcmp_case_insensitive("hello", "Hi") == -1);
    assert(strcmp_case_insensitive("Hi", "Hi") == 0);
    assert(strcmp_case_insensitive("Dog", "dog") == 0);
    assert(strcmp_case_insensitive("Milk", "MilkChocolate") == -1);
    assert(strcmp_case_insensitive("MilkChocolate", "Milk") == 1);

    assert(strcmp_case_insensitive("", "") == 0);
    assert(strcmp_case_insensitive("", "owen") == -1);
    assert(strcmp_case_insensitive("owen", "") == 1);

    assert(strcmp_case_insensitive("123", "123") == 0);
    assert(strcmp_case_insensitive("123", "125") == -1);

    assert(strcmp_case_insensitive("@@@@", "Hello") == -1);
    assert(strcmp_case_insensitive("", "Hello") == -1);

    assert(strcmp_case_insensitive("Coding", "CoDING") == 0);
    assert(strcmp_case_insensitive("Hello World", "hello world") == 0);

    assert(strcmp_case_insensitive("A", "a") == 0); 
    assert(strcmp_case_insensitive("abc", "xyz") == -1);
    assert(strcmp_case_insensitive("   ", "   ") == 0);
    assert(strcmp_case_insensitive("Hello@World", "hello@world") == 0);

    assert(strcmp_case_insensitive("pneumonoultramicroscopicsilicovolcanoconiosis", "pneumonoultramicroscopicsilicovolcanoconiosis") == 0);
    
    cout << "All of the test passed!" << endl;
    return 0;
}