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

void merge(int list[], int left[], int right[], int mid, int mid2){
    int i = 0, j = 0, k = 0;
    while(i < mid && j < mid2) {
        if (left[i] <= right[j]){
            list[k++] = left[i++];
        }
        else{
            list[k++] = right[j++];
        }
    }
    while(i < mid){
        list[k++] = left[i++];
    }
    while(j < mid2){
        list[k++] = right[j++];
    }
}

void merge_sort(int list[], int sizeList){
    if (sizeList >= 2) {

        int mid = sizeList / 2;
        int mid2 = sizeList - mid;
        int left[mid];
        int right[mid2];

        for(int i = 0; i < mid; i++){
            left[i] = list[i];
        }

        for(int i = mid; i < sizeList; i++){
            right[i - mid] = list[i];
        }

        merge_sort(left, mid);
        merge_sort(right, mid2);

        merge(list, left, right, mid, mid2);
    }
}

int buscaBinaria(int list[], int low, int high, int key){
    if((high-low) < 1){
        return -1;
    }

    int mid = (high - low)/2 + low;

    if(list[mid] == key){
        return mid;
    }
    else if(list[mid] > key){
        return buscaBinaria(list, low, mid, key);
    }
    else{
        return buscaBinaria(list, mid+1, high, key);
    }
}

int main()
{
    int sizeList = 10;
    int rand_max = 100;
    int list[sizeList];

    complete_List(list, sizeList, rand_max);

    merge_sort(list, sizeList);

    print_List(list, sizeList);

    int key;

    do{
        printf("Type a number to search: \n");
        scanf("%d", &key);

        int indice_busca = buscaBinaria(list, 0, sizeList, key);
        if(indice_busca == -1){
            printf("element not found\n");
        }else{
            printf("%d position\n", indice_busca+1);
        }

        printf("Finalize no-0/yes-1\n");
        scanf("%d", &key);
    }while(key != 1);

    return 0;
}
