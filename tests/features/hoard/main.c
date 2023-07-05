#include "hoard.h"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(intArray) / sizeof(int);
    int condition = 3;
    int result = hoard(intArray, size, &condition, compareInt);
    printf("Int Result: %d\n", result);

    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size = sizeof(floatArray) / sizeof(float);
    float floatCondition = 3.3;
    result = hoard(floatArray, size, &floatCondition, compareFloat);
    printf("Float Result: %d\n", result);

    double doubleArray[] = {1.11, 2.22, 3.33, 4.44, 5.55};
    size = sizeof(doubleArray) / sizeof(double);
    double doubleCondition = 3.33;
    result = hoard(doubleArray, size, &doubleCondition, compareDouble);
    printf("Double Result: %d\n", result);

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size = sizeof(charArray) / sizeof(char);
    char charCondition = 'c';
    result = hoard(charArray, size, &charCondition, compareChar);
    printf("Char Result: %d\n", result);

    return 0;
}
