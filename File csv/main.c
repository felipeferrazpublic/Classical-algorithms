#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UI_console.h"


// Dois erros -> Não está mostrando o segundo tipo do pokemon
// e o total point está saindo em ordem errada
int main()
{
    int max_fields = 152;
    Pokemon pokedex[max_fields];
    int max_line_lenght = 1500;

    FILE *file = fopen("Pokemon.csv", "r");

    if (file == NULL) {
        printf("Arquivo nao encontrado");
        return 1;
    }

    char line[max_line_lenght];
    int indexPokedex = 0;
    char *field;

    while(fgets(line, max_line_lenght, file) != NULL) {
        field = strtok(line, ",");
        int fieldCount = 0;
        if (indexPokedex == 0){
            indexPokedex++;
            continue;
        }
        while (field != NULL && fieldCount < max_fields) {
            //printf("%s\n", field);
            switch(fieldCount){
            case 0:
                pokedex[indexPokedex].ID = atoi(field);
                break;
            case 2:
                strcpy(pokedex[indexPokedex].type1, field);
                break;
            case 3:
                if(field)
                strcpy(pokedex[indexPokedex].type2, field);
                break;
            case 4:
                pokedex[indexPokedex].total = atoi(field);
                break;
            case 5:
                pokedex[indexPokedex].HP = atoi(field);
                break;
            case 6:
                pokedex[indexPokedex].Attack = atoi(field);
                break;
            case 7:
                pokedex[indexPokedex].Defense = atoi(field);
                break;
            case 8:
                pokedex[indexPokedex].Sp_Attack = atoi(field);
                break;
            case 9:
                pokedex[indexPokedex].Sp_Defense = atoi(field);
                break;
            case 10:
                pokedex[indexPokedex].Speed = atoi(field);
                break;
            case 11:
                pokedex[indexPokedex].Stage = atoi(field);
                break;
            case 12:
                strcpy(pokedex[indexPokedex].Legendary, field);
                break;
            default:
                strcpy(pokedex[indexPokedex].name, field);
                break;

            }
            field = strtok(NULL, ",");
            fieldCount++;
        }
        printPokemon(pokedex[indexPokedex]);
        indexPokedex++;
    }

    fclose(file);


/*
    struct Pokemon Bulbasaur;
    void *nome;
    Bulbasaur.ID = 1;
    char name[] = "Bulbasaur";
    nome = (char *) name;
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
*/

    return 0;
}
