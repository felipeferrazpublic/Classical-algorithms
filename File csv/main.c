#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UI_console.h"

int main()
{
    struct Pokemon Bulbasaur;
    Bulbasaur.ID = 1;
    char name[] = "Bulbasaur";
    strcpy(Bulbasaur.name,name);
    Bulbasaur.type1 = 0;
    Bulbasaur.type2 = 1;
    Bulbasaur.total = 318;
    Bulbasaur.HP = 45;
    Bulbasaur.Attack = 49;
    Bulbasaur.Defense = 49;
    Bulbasaur.Sp_Attack = 65;
    Bulbasaur.Sp_Defense = 65;
    Bulbasaur.Speed = 45;
    Bulbasaur.Stage = 1;
    Bulbasaur.Legendary = 0;
    printPokemon(Bulbasaur);
    return 0;
}
