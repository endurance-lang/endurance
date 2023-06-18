#include "print-source-code.h"

void printSourceCodeWithLineNumbers(const char* sourceCode) {
    int lineNumber = 1;

    printf("%d: ", lineNumber);
    while (*sourceCode != '\0') {
        putchar(*sourceCode);

        if (*sourceCode == '\n') {
            lineNumber++;
            printf("%d: ", lineNumber);
        }

        sourceCode++;
    }

    printf("\n");
}
