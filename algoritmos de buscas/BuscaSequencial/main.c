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

int buscaSequencial(int list[], int sizeList, int key){

    for(int i = 0; i < sizeList; i++){
        if(list[i] == key){
            return i;
        }
    }
    return -1;

}

int main()
{
    int sizeList = 10;
    int rand_max = 10;
    int list[sizeList];

    complete_List(list, sizeList, rand_max);

    print_List(list, sizeList);

    int search;

    do{
        printf("Type a number to search: \n");
        scanf("%d", &search);

        int indice_busca = buscaSequencial(list, sizeList, search);
        if(indice_busca == -1){
            printf("element not found\n");
        }else{
            printf("%d position\n", indice_busca+1);
        }

        printf("Finalize no-0/yes-1\n");
        scanf("%d", &search);
    }while(search != 1);

    return 0;
}
