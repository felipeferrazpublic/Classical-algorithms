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

int add_list_sort(List *li, void *add_element, int *add_key, int size_refe){

    if(li == NULL)
        return 0;

    No *no = (No *)malloc(sizeof(No));
    no->ponteiro = (refe*) malloc(sizeof(refe)*size_refe);
    no->key = (int*) malloc(sizeof(int)*size_refe);

    no->data = malloc(li->size_dado);
    memcpy(no->data, add_element, li->size_dado);

    for(int i = 0; i < size_refe; i++){
        if(li -> size_list == 0){
            no->ponteiro[i].pos = NULL;
            no->ponteiro[i].pre = NULL;
            li->first_no[i] = no;
            li->last_no[i] = no;
        }
        else {
            No *anterior = NULL, *atual = li -> first_no[i];

            while(atual != NULL && atual->key[i] < add_key[i]){
                anterior = atual;
                atual = anterior->ponteiro[i].pos;
            }
            if(atual == li -> first_no[i]){
                no->ponteiro[i].pre = NULL;
                li->first_no[i]->ponteiro[i].pre = no;
                no->ponteiro[i].pos = li->first_no[i];
                li->first_no[i] = no;
            } else {
                no->ponteiro[i].pos = anterior->ponteiro[i].pos;
                no->ponteiro[i].pre = anterior;
                anterior->ponteiro[i].pos = no;

                if(atual != NULL) {
                    atual->ponteiro[i].pre = no;
                }
                else{
                    li->last_no[i] = no;
                }
            }
        }
        no->key[i] = add_key[i];
    }
    li -> size_list++;
    return 1;
}

void delete_list(List *li){

    if (li != NULL){
        No* auxList;
        while(li->first_no[0] != NULL){
            auxList = li->first_no[0];
            li->first_no[0] = li->first_no[0]->ponteiro[0].pos;
            free(auxList->data);
            free(auxList->key);
            free(auxList->ponteiro);
            free(auxList);
        }
        free(li->last_no);
        free(li->first_no);
        free(li);
    }
}

int remove_data(List* li, int position, int parameter){
    if (li == NULL || li->first_no[parameter] == NULL){
        return 0;
    }

    if (position > li->size_list || position < 1){
        return 0;
    }
    if (parameter < 0 || parameter >= li->size_refe){
        return 0;
    }

    No* auxList = li->first_no[parameter];

    int i = 1;

    while(auxList->ponteiro[parameter].pos != NULL && i < position){
        i++;
        auxList = auxList->ponteiro[parameter].pos;
    }
    for(i = 0; i < li->size_refe; i++){
        if(auxList->ponteiro[i].pre == NULL){
            li->first_no[i] = auxList->ponteiro[i].pos;
        }
        else if(auxList->ponteiro[i].pos == NULL){
            auxList->ponteiro[i].pre->ponteiro[i].pos = NULL;
            li->last_no[i] = auxList->ponteiro[i].pre;
        }
        else{
            auxList->ponteiro[i].pre->ponteiro[i].pos = auxList->ponteiro[i].pos;
            auxList->ponteiro[i].pos->ponteiro[i].pre = auxList->ponteiro[i].pre;
        }
    }
    free(auxList->data);
    free(auxList->key);
    free(auxList->ponteiro);
    free(auxList);

    li->size_list--;

    return 1;
}

int search_data(List* li, int position, int parameter, void* data){
    if (li == NULL || li->first_no[parameter] == NULL){
        return 0;
    }
    if (position > li->size_list || position < 1){
        return 0;
    }
    if (parameter < 0 || parameter >= li->size_refe){
        return 0;
    }
    No* auxList = li->first_no[parameter];

    int i = 1;

    while(auxList->ponteiro[parameter].pos != NULL && i < position){
        i++;
        auxList = auxList->ponteiro[parameter].pos;
    }
    memcpy(data, auxList->data, li->size_dado);

    return 1;
}

int size_list(List* li){
    if(li == NULL){
        return 0;
    }
    return li->size_list;
}
