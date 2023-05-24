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

void insertion_Sort(int list[], int size){
    for(int j,i = 1; i < size; i++){
            int key = list[i];
            j = i-1;
        while(j >= 0 && list[j] > key){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
    }
}

int main()
{
    int size = 20;
    int list[size];
    complete_List(list, size, 100);
    print_List(list, size);

    insertion_Sort(list, size);

    print_List(list, size);
    return 0;
}
