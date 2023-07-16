#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void complete_List(int list[],int size,int rand_max){
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++){
        int num = (rand() % rand_max);
        list[i] = num;
    }
}

void print_List(int list[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

void swap(int list[], int first, int second){
    int swap = list[first];
    list[first] = list[second];
    list[second] = swap;
}

int partition(int list[], int low, int high){
    int pivo, i;
    int pivo_indice = (rand() % (high - low + 1)) + low;

    swap(list, pivo_indice, high);

    pivo = list[high];
    pivo_indice = low;

    for(i = low; i < high; i++){
        if(list[i] <= pivo){
            swap(list, i, pivo_indice);
            pivo_indice++;
        }
    }
    swap(list, pivo_indice, high);
    return pivo_indice;
}

void quick_sort(int list[], int low, int high){
    if (low < high){
        int pivo_indice = partition(list, low, high);

        quick_sort(list, low, pivo_indice - 1);
        quick_sort(list, pivo_indice + 1, high);
    }
}

int main()
{
    int sizeList = 10;
    int rand_max = 100;
    int list[sizeList];

    complete_List(list, sizeList, rand_max);

    print_List(list, sizeList);

    quick_sort(list, 0, sizeList-1);

    print_List(list, sizeList);

    return 0;
}
