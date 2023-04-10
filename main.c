#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"

void arrayPrint(int arr[], int arrLength);
void arrayFillRandom(int arr[], int arrLength);
int* arrayFilterEven(int arr[], int arrLength, int *filterLength);

int main() {

    srand(time(NULL)); //inicializador de numeros aleatorios
    int *arr = NULL;
    int len;

    // Gestão de Memória Dinâmica - 1

    do {
		printf("Len Value? ");
	} while(!readInteger(&len)); /* loops while invalid */

    //arr = (int*)malloc(len * sizeof(int));
      arr = (int*)calloc(len,  sizeof(int));
      
    if (arr == NULL) { // verificação da alocação de memória
        printf("Erro: não foi possível alocar memória.\n");
        return EXIT_FAILURE; // termina o programa com erro
    }

    arrayPrint(arr, len);

    // Gestão de Memória Dinâmica - 2

    arrayFillRandom(arr,len);
    arrayPrint(arr,len);

    arr = (int*)realloc(arr, len * 2 * sizeof(int));
    int doubleLen = len * 2;

    arrayPrint(arr,doubleLen);

    // Gestão de Memória Dinâmica - 3
    
    int *filterLength = &len;

    int *evenArr = arrayFilterEven(arr, len, filterLength);
    printf("%d\n", *filterLength);
    arrayPrint(evenArr, *filterLength);

    free(arr);

    return EXIT_SUCCESS;
}

void arrayPrint(int arr[], int arrLength) {

    if(arr == NULL) {
        printf("(NULL array)\n");
        return;
    }

    printf("Array (size = %d} contents: { ", arrLength);

    for(int i=0; i<arrLength; i++) {
        printf("%d ", arr[i]);
    }

    printf("}\n");
}

// Gestão de Memória Dinâmica - 2

 void arrayFillRandom(int arr[], int arrLength){

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = rand() % 51;
    }
    
 }

 // Gestão de Memória Dinâmica - 3

 int* arrayFilterEven(int arr[], int arrLength, int *filterLength){

    int *newArr = NULL;
    int countEven = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if(arr[i] % 2 == 0){
            countEven++;
        }
    }
    
    newArr = (int *)malloc(countEven * sizeof(int));
    int j = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if(arr[i] % 2 == 0){

            newArr[j] = arr[i];
            j++;
        }
    }

    *filterLength = countEven;
    return newArr;
      
 }
