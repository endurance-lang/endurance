#include <stdio.h>
#include "booty.h"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    int intArraySize = sizeof(intArray) / sizeof(int);
    int intInitialValue = 0;
    int intResult = *(int*)booty(intArray, intArraySize, &intInitialValue, sumInt);
    printf("Int Result: %d\n", intResult);

    return 0;
}
