#include <stdio.h>
#include <string.h>

int process(char *infname, FILE *output) {
    FILE *inFile = fopen(infname, "r");
    if(!inFile) return 0;
    char input[200];
    int ok = 1;
    while(ok) {
        fscanf(inFile, "inport %s\n", input);
        input[strlen(input)-1] = '\0';
        ok = process(input+1, output);
    }
    
    while(fgets(input, 199, inFile)) fputs(input, output);

    fprintf(output, "\n\n/ahoy end of %s belay/\n\n", infname);

    fclose(inFile);
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("./preprocess <intput_filename> <output_filename>\n");
        return 0;
    }

    FILE *output = fopen(argv[2], "w");

    process(argv[1], output);

    fclose(output);

    return 0;
}