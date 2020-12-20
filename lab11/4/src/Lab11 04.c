#include <malloc.h>
#include <time.h>
#include <iostream>

int main()
{   
    srand(time(NULL));
    /* Визначення розміру масиву */
    int N = rand() % 10;
    /* Задання динамічного масиву для запису туди результату */
    int* ResultMass = (int*)malloc(N * sizeof(int));
    /* Задання динамічного двовимірного масиву */
    int** Mass = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        *(Mass + i) = (int*)malloc(N * sizeof(int));
    }

    /* Цикл для заповнення масиву випадковими числами */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(Mass + i) + j) = rand() % 10;
            printf("%4d", *(*(Mass + i) + j));
        }
        printf("\n");
    }
    
    for (int i = 0; i < N * 4; i++) 
    {
        printf("_");
    }
    printf("\n");
    
    /* Цикл для перенесення діагональних елементів в массив для результату */
    for (int i = 0; i < N; i++) {
        *(ResultMass + i) = *(*(Mass + i) + i);
        printf("%4d", *(ResultMass + i));
    }
    
    printf("\n");
    for (int i = 0; i < N * 4; i++) {
        printf("_");
    }
    printf("\n");

    /* Буферна змінна для перестановки елементів масиву */
    int tmp;

    /* Цикл для "сортування бульбашкою" результуючого масиву */
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (*(ResultMass + j) > *(ResultMass + j + 1)) {
                tmp = *(ResultMass + j);
                *(ResultMass + j) = *(ResultMass + j + 1);
                *(ResultMass + j + 1) = tmp;
            }
        }
    }

    /* Цикл для виведення елементів масиву */
    for (int i = 0; i < N; i++) {
        printf("%4d", *(ResultMass + i));
    }

    return 0;
}