#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <cassert>

using namespace std;

int strcmp_case_insensitive(string string_1, string string_2) {
    char cStringOne[string_1.length()];
    char cStringTwo[string_2.length()];

    for (int i = 0; i < sizeof(cStringOne); i++) {
        cStringOne[i] = string_1.at(i);
    }

    for (int i = 0; i < sizeof(cStringTwo); i++) {
        cStringTwo[i] = string_2.at(i);
    }

    int result = strcmp (cStringOne, cStringTwo);

    if (result == 0) { 
        return 0;
    } else if (result > 0) {
        return 1;
    } else if (result < 0) {
        return -1;
    }
}

int main () {

    string str1 = "string one";
    string str2 = "string two";

    assert.


    return 0;
}