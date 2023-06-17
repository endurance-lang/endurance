#include "print-source-code.h"

void main() {
    FILE* file = fopen("input.end", "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo\n");
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char* sourceCode = (char*)malloc(fileSize + 1);
    if (sourceCode == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        fclose(file);
    }

    size_t bytesRead = fread(sourceCode, sizeof(char), fileSize, file);
    if (bytesRead != fileSize) {
        fprintf(stderr, "Erro ao ler o arquivo\n");
        fclose(file);
        free(sourceCode);
    }

    sourceCode[fileSize] = '\0';

    fclose(file);

    printSourceCodeWithLineNumbers(sourceCode);

    free(sourceCode);
}