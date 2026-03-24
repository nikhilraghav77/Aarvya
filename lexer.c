#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Aarvya Keywords
char *keywords[] = {
    "int", "float", "char", "string", "bool",
    "if", "else", "while", "for", "return",
    "function", "print", "input", "exit"
};

int isKeyword(char buffer[]) {
    for(int i = 0; i < 14; i++) {
        if(strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[MAX];
    int i = 0;

    fp = fopen("program.arv", "r");

    if(fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF) {

        if(isspace(ch))
            continue;

        // IDENTIFIER or KEYWORD
        if(isalpha(ch)) {
            buffer[i++] = ch;

            while(isalnum(ch = fgetc(fp))) {
                buffer[i++] = ch;
            }

            buffer[i] = '\0';
            i = 0;

            if(isKeyword(buffer))
                printf("Token: %s -> KEYWORD\n", buffer);
            else
                printf("Token: %s -> IDENTIFIER\n", buffer);

            fseek(fp, -1, SEEK_CUR);
        }

        // NUMBER
        else if(isdigit(ch)) {
            buffer[i++] = ch;

            while(isdigit(ch = fgetc(fp))) {
                buffer[i++] = ch;
            }

            buffer[i] = '\0';
            i = 0;

            printf("Token: %s -> NUMBER\n", buffer);
            fseek(fp, -1, SEEK_CUR);
        }

        // COMMENT
        else if(ch == '/') {
            char next = fgetc(fp);

            if(next == '/') {
                while((ch = fgetc(fp)) != '\n' && ch != EOF);
            } else {
                printf("Token: / -> OPERATOR\n");
                fseek(fp, -1, SEEK_CUR);
            }
        }

        // OPERATORS
        else {
            printf("Token: %c -> OPERATOR\n", ch);
        }
    }

    fclose(fp);
    return 0;
}