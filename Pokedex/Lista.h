#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pokemon {
        int ID;
        char name[20];
        char type1[20];
        char type2[20];
        int total;
        int HP;
        int Attack;
        int Defense;
        int Sp_Attack;
        int Sp_Defense;
        int Speed;
        int Stage;
        char Legendary[20];
} Pokemon;

typedef struct no {
    Pokemon pokemon;
    struct no *pos_hp;
    struct no *pre_hp;
}No;

typedef struct Header {
    int size_list;
    struct no *first_no;
    struct no *last_no;

}Header;

void printf_dados_no(No *no){
    for(int i = 0; i < 100; i++){
        printf("-");
    }
    printf("\n");
    printf("\t\t\t\t\t\tPokemon\n");
    for(int i = 0; i < 100; i++){
        printf("-");
    }
    printf("\n");

    if (strcmp(no->pokemon.Legendary, "FALSE")==0){
        printf("ID: %d\t\tName: %s\n",no->pokemon.ID, no->pokemon.name);
    }
    else{
        printf("ID: %d\t\tName: %s\tLegendary\n", no->pokemon.ID, no->pokemon.name);
    }
    if (strcmp(no->pokemon.type2, "xxxx")==0){
        printf("Type: %s\tStage: %d\n", no->pokemon.type1, no->pokemon.Stage);
    }
    else{
        printf("Type1: %s\tType2: %s\tStage: %d\n", no->pokemon.type1,
                no->pokemon.type2, no->pokemon.Stage);
    }
    printf("HP: %d\t\tSpeed: %d\tTotal of point: %d\n",
           no->pokemon.HP, no->pokemon.Speed, no->pokemon.total);
    printf("Attack: %d\tDefense: %d\tSp_Attack: %d\t\tSp_Defense: %d\n",
           no->pokemon.Attack, no->pokemon.Defense,
           no->pokemon.Sp_Attack, no->pokemon.Sp_Defense);

    for(int i = 0; i < 100; i++){
        printf("-");
    }
    printf("\n");
}

void printf_hp(No *no){
    printf("Lista de HP: \n");
    while(no) {
        printf("%d ", no->pokemon.HP);
        no = no->pos_hp;
    }
}

void inserir_element_sort(Header descritor, Pokemon pokemon){
    No *aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->pokemon = pokemon;
        novo->pos_hp = NULL;
        novo->pre_hp = NULL;
        if(descritor.first_no == NULL){
            descritor.first_no = novo;
            descritor.last_no = novo;
        }
        else if(novo->pokemon.HP < descritor.first_no->pokemon.HP){
           novo->pos_hp = descritor.first_no;
           descritor.first_no->pre_hp = novo;
           descritor.first_no = novo;
        }
        else {
            aux = descritor.first_no;
            while(aux->pos_hp && novo->pokemon.HP < aux->pokemon.HP){
                aux = aux->pos_hp;
            };
            if (aux->pos_hp) {
                novo->pos_hp = aux;
                novo->pre_hp = aux->pre_hp;
                aux->pre_hp = novo;
                novo->pre_hp->pos_hp = novo;
            }
            else {
                novo->pre_hp = aux;
                aux->pos_hp = novo;
                descritor.last_no = novo;
            }
        }
    }
    else {
        printf("Erro ao alocar ");
    }
}
