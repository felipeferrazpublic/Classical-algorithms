#include "pokemon.h"
//Tomar cuidado com pokemon que tem o mesmo nome,
//mas generos diferentes(Nidoran)

void printPokemon(struct Pokemon pokemon){
    for(int i = 0; i < 100; i++){
        printf("-");
    }
    printf("\n");
    printf("\t\t\t\t\t\tPokemon\n");
    for(int i = 0; i < 100; i++){
        printf("-");
    }
    printf("\n");

    if (pokemon.Legendary == 0){
        printf("ID: %d\t\tName: %s\n",pokemon.ID, pokemon.name);
    }
    else{
        printf("ID: %d\t\tName: %s\tLegendary\n", pokemon.ID, pokemon.name);
    }
    if (pokemon.type2 == -1){
        printf("Type: %s\tStage: %d\n", TYPE[pokemon.type1], pokemon.Stage);
    }
    else{
        printf("Type1: %s\tType2: %s\tStage: %d\n", TYPE[pokemon.type1],
                TYPE[pokemon.type2], pokemon.Stage);
    }
    printf("HP: %d\t\tSpeed: %d\tTotal of point: %d\n",
           pokemon.HP, pokemon.Speed, pokemon.total);
    printf("Attack: %d\tDefense: %d\tSp_Attack: %d\t\tSp_Defense: %d\n",
           pokemon.Attack, pokemon.Defense,
           pokemon.Sp_Attack, pokemon.Sp_Defense);

    for(int i = 0; i < 100; i++){
        printf("-");
    }
    printf("\n");
}
