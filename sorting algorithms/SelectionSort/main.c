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

void selection(int list[],int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i; j < size; j++){
            if (list[i] > list[j]){
                int swap = list[i];
                list[i] = list[j];
                list[j] = swap;
            }
        }
    }
}

int main()
{
    int size = 20;
    int list[size];
    complete_List(list, size, 100);
    print_List(list, size);

    selection(list, size);

    print_List(list, size);

    return 0;
}
