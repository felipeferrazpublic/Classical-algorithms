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

void bubble_sort(int list[], int size){
    for (int i = size-1; i > 0 ; i--){
        for(int j = 0; j < i; j++){
            if (list[j] > list[j+1]){
                int swap = list[j];
                list[j] = list[j+1];
                list[j+1] = swap;
            }
        }
    }
}

void print_List(int list[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main()
{
    int sizeList = 10;
    int rand_max = 100;
    int list[sizeList];

    complete_List(list, sizeList, rand_max);

    print_List(list, sizeList);

    bubble_sort(list, sizeList);

    print_List(list, sizeList);

    return 0;
}
