#include "./gully.h"

void main(){
    int intArray[] = {1, 2, 3, 4, 5};
    gully(intArray, 1, 3, sizeof(int));

    float floatArray[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    gully(floatArray, 0, 2, sizeof(float));

    // Exemplo de uso com um struct
    struct Person {
        char name[20];
        int age;
    };

    struct Person personArray[] = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 35}};
    gully(personArray, 1, 2, sizeof(struct Person));

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    gully(charArray, 2, 4, sizeof(char));

}