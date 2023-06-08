#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>

#define MAX_LEN 200

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

int main(){

    int size_parametro = 3;
    List *li = cria_lista(sizeof(Pokemon), size_parametro);

    int teste = 0;
    char buffer[MAX_LEN];

    Pokemon pokemon;
    int keys[size_parametro];

    FILE* file = fopen("Pokemon.csv", "r");

    if (file == NULL) {
        printf (" Erro ao abrir o arquivo .\n");
        return 1;
    }

    fgets (buffer, sizeof(buffer), file);

    while (fgets(buffer, sizeof(buffer), file) != NULL ) {
        teste = 0;
        for(int i = 0; i < strlen(buffer)-1; i++){
            if (buffer[i] == buffer[i+1] && buffer[i] == ','){
                teste = 1;
                break;
            }
        }

        char id_str[20];
        char nome[20];
        char tipo1[20];
        char tipo2[20];
        char total_str[20];
        char hp_str[20];
        char attack_str[20];
        char defense_str[20];
        char sp_atk_str[20];
        char sp_def_str[20];
        char speed_str[20];
        char stage[20];
        char legend_str[20];

        strcpy(id_str, strtok ( buffer , ","));
        strcpy(nome, strtok ( NULL , ","));
        strcpy(tipo1, strtok ( NULL , ","));
        strcpy(tipo2, strtok ( NULL , ","));

        if (teste == 1){
            strcpy(total_str, tipo2);
            strcpy(tipo2, "xxxx");
        }
        else{
            strcpy(total_str, strtok ( NULL , ","));
        }
        strcpy(hp_str, strtok ( NULL , ","));
        strcpy(attack_str, strtok ( NULL , ","));
        strcpy(defense_str, strtok ( NULL , ","));
        strcpy(sp_atk_str, strtok ( NULL , ","));
        strcpy(sp_def_str, strtok ( NULL , ","));
        strcpy(speed_str, strtok ( NULL , ","));
        strcpy(stage, strtok ( NULL , ","));
        strcpy(legend_str, strtok ( NULL , ","));

/*
        id_str = strtok ( buffer , ",") ;

        nome = strtok ( NULL , ",");

        tipo1 = strtok ( NULL , ",");

        tipo2 = strtok ( NULL , ",");

        if (teste == 1){
            strcpy(total_str, tipo2);
        }

        total_str = strtok ( NULL , ",") ;

        hp_str = strtok ( NULL , ",") ;

        attack_str = strtok ( NULL , ",");

        defense_str = strtok ( NULL , ",") ;

        sp_atk_str = strtok ( NULL , ",");

        sp_def_str = strtok ( NULL , ",");

        speed_str = strtok ( NULL , ",") ;

        stage

        legend_str = strtok ( NULL , ",");

        printf("%s\n", total_str);
*/
        // Converção de strings para tipos primitivos

        pokemon.ID = atoi( id_str );

        strcpy(pokemon.name, nome);

        strcpy(pokemon.type1, tipo1);

        strcpy(pokemon.type2, tipo2);

        pokemon.total = atoi ( total_str ) ;

        pokemon.HP = atoi ( hp_str );

        pokemon.Attack = atoi ( attack_str );

        pokemon.Defense = atoi ( defense_str );

        pokemon.Sp_Attack = atoi ( sp_atk_str );

        pokemon.Sp_Defense = atoi ( sp_def_str );

        pokemon.Speed = atoi(speed_str) ;

        pokemon.Stage = atoi(stage);

        strcpy(pokemon.Legendary, legend_str);

        //printf("erro\n");

        keys[0] = pokemon.ID;
        keys[1] = pokemon.HP;
        keys[2] = pokemon.Attack;
        add_list_sort(li, &pokemon, keys, size_parametro);

        //getchar () ;
    }

    fclose ( file );

/*
    Pokemon Bulbasaur = {1,"Bulbasaur","Grass","Poison",318,45,49,49,65,65,45,1,"FALSE"};
    int keys[] = {Bulbasaur.ID, Bulbasaur.HP, Bulbasaur.Attack};
    add_list_sort(li, &Bulbasaur, keys, size_parametro);

    Pokemon charmander = {4,"Charmander","Fire","",309,39,52,43,60,50,65,1,"FALSE"};
    int keys2[] = {charmander.ID, charmander.HP, charmander.Attack};
    add_list_sort(li, &charmander, keys2, size_parametro);

    Pokemon Squirtle = {7,"Squirtle","Water","",314,44,48,65,50,64,43,1,"FALSE"};
    int keys3[] = {Squirtle.ID, Squirtle.HP, Squirtle.Attack};
    add_list_sort(li, &Squirtle, keys3, size_parametro);

    Pokemon Meowth = {52,"Meowth","Normal","",290,40,45,35,40,40,90,1,"FALSE"};
    int keys4[] = {Meowth.ID, Meowth.HP, Meowth.Attack};
    add_list_sort(li, &Meowth, keys4, size_parametro);

*/

    Pokemon charmander2;

    for(int i = 1; i <= size_list(li); i++){
        if (search_data(li, i, 0, &charmander2)){
            printf("%d\n", charmander2.total);
        }
    }

    remove_data(li, 1, 3);
    printf("%d", li->size_list);
    delete_list(li);

    return 0;
}
