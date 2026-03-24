#include <stdio.h>
#include <ctype.h>

char input[100];
int pos = 0;

// Forward declarations
int E();
int T();
int F();

// E -> T + E | T
int E() {
    int value = T();

    while (input[pos] == '+') {
        pos++; // skip '+'
        value += E();
    }

    return value;
}

// T -> F * T | F
int T() {
    int value = F();

    while (input[pos] == '*') {
        pos++; // skip '*'
        value *= T();
    }

    return value;
}

// F -> (E) | digit
int F() {
    int value;

    if (input[pos] == '(') {
        pos++; // skip '('
        value = E();
        pos++; // skip ')'
    } else if (isdigit(input[pos])) {
        value = input[pos] - '0'; // convert char to int
        pos++;
    }

    return value;
}

int main() {
    printf("Enter expression. ");
    scanf("%s", input);

    int result = E();

    printf("Result: %d\n", result);

    return 0;
}