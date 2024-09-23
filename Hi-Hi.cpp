#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <cctype>

using namespace std;

int strcmp_case_insensitive(string string_1, string string_2) {
    char cStringOne[string_1.length() + 1];
    char cStringTwo[string_2.length() + 1];

    for (int i = 0; i < string_1.length(); i++) {
        cStringOne[i] = tolower(string_1[i]);
    }
    cStringOne[string_1.length()] = '\0';

    for (int i = 0; i < string_2.length(); i++) {
        cStringTwo[i] = tolower(string_2[i]);
    }
    cStringTwo[string_2.length()] = '\0';

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

    assert(strcmp_case_insensitive("pneumonoultramicroscopicsilicovolcanoconiosis", "pneumonoultramicroscopicsilicovolcanoconiosis") == 0);
    return 0;
}