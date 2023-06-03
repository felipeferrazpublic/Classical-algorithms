#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

List *cria_lista(int size_dados, int size_refe){

    List *li = (List *)malloc(sizeof(List));

    if(li != NULL){

        li -> size_dado = size_dados;
        li -> size_list = 0;
        li -> size_refe = size_refe;
        li -> first_no = (No**) (malloc(sizeof(No*)*size_refe));
        li -> last_no = (No**) (malloc(sizeof(No*)*size_refe));
    }

    return li;

}

void * aux_add_list(void *dado, void *add, int size_dado){
    dado = malloc(li -> size_list);

    memcpy(dado, add, size_dado);
}

int add_list_sort(List *li, void *add_element, int *add_key, int size_refe){

    if(li == NULL)
        return 0;

    No *no = (No *)malloc(sizeof(No));


    if(li -> size_list == 0){

        no -> pre = NULL;
        no -> pos = NULL;
        li -> first_no = no;
        li -> last_no = no;

    } else {

        No *anterior, *atual = li -> first_no;

        while(atual != NULL && atual -> key < add_key){
            anterior = atual;
            atual = anterior -> pos;
        }
        if(atual == li -> first_no){
            no -> pre = NULL;
            li -> first_no -> pre = no;
            no -> pos = li -> first_no;
            li -> first_no = no;
        } else {
            no -> pos = anterior -> pos;
            no -> pre = anterior;
            anterior -> pos = no;
            if(atual != NULL)
                atual -> pre = no;
            else
                li -> last_no = no;
        }
    }
    no -> key = add_key;
    li -> size_list++;
}

void print_lista(List *li){

    No *no = li -> first_no;

    puts("Sua lista ordenada e:\n");
    while(no != NULL){

        printf("%d.\n", *((int *)no -> data));
        no = no -> pos;
    }

}
