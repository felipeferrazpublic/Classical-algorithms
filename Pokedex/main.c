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

void print_pokemon(Pokemon pokemon);

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
        if (pokemon.Legendary[strlen(pokemon.Legendary)-1] == '\n' ){
            pokemon.Legendary[strlen(pokemon.Legendary)-1] = '\0';
            //pokemon.Legendary[strlen(pokemon.Legendary)+1] = '\0';
        }

        keys[0] = pokemon.ID;
        keys[1] = pokemon.HP;
        keys[2] = pokemon.Attack;
        add_list_sort(li, &pokemon, keys, size_parametro);

    }

    fclose ( file );
    int option = 0;
    int option2 = 0;

    do{
        printf("0 - Sair do programa\n");
        printf("1 - imprimir todos os pokemon\n");
        printf("2 - imprimir um pokemon especifico\n");
        printf("3 - imprimir o ultimo\n");
        printf("4 - imprimir o primeiro\n");
        printf("Digite a sua alternativa: \n");

        scanf("%d", &option);
        system("cls");

        switch(option){
            case 0:
                break;
            case 1:
                do{
                    system("cls");
                    printf("Qual a ordem: \n");
                    printf("0 - voltar\n");
                    printf("1 - ID\n");
                    printf("2 - HP\n");
                    printf("3 - Attack\n");
                    printf("Digite a sua alternativa: \n");

                    scanf("%d", &option2);
                    system("cls");

                }while(option2<0 || option2>3);

                if(option2 == 0){
                    break;
                }

                for(int i = 1; i <= size_list(li); i++){
                    search_data(li, i, option2-1, &pokemon);
                    print_pokemon(pokemon);
                }
                break;
            case 2:
                do{
                    system("cls");
                    printf("Qual a ordem: \n");
                    printf("0 - voltar\n");
                    printf("1 - ID\n");
                    printf("2 - HP\n");
                    printf("3 - Attack\n");
                    printf("Digite a sua alternativa: \n");

                    scanf("%d", &option2);
                    system("cls");

                }while(option2<0 || option2>3);

                if(option2 == 0){
                    break;
                }

                int position;
                printf("Qual a posicao: \n");
                scanf("%d", &position);

                if (!search_data(li, position, option2-1, &pokemon)){
                    printf("posicao nao existente\n");
                    break;
                }
                print_pokemon(pokemon);
                break;
            case 3:
                do{
                    system("cls");
                    printf("Qual a ordem do ultimo: \n");
                    printf("0 - voltar\n");
                    printf("1 - ID\n");
                    printf("2 - HP\n");
                    printf("3 - Attack\n");
                    printf("Digite a sua alternativa: \n");

                    scanf("%d", &option2);
                    system("cls");

                }while(option2<0 || option2>3);

                if(option2 == 0){
                    break;
                }
                search_data(li, size_list(li), option2-1, &pokemon);
                print_pokemon(pokemon);
                break;
            case 4:
                do{
                    system("cls");
                    printf("Qual a ordem do primeiro: \n");
                    printf("0 - voltar\n");
                    printf("1 - ID\n");
                    printf("2 - HP\n");
                    printf("3 - Attack\n");
                    printf("Digite a sua alternativa: \n");

                    scanf("%d", &option2);
                    system("cls");

                }while(option2<0 || option2>3);

                if(option2 == 0){
                    break;
                }
                search_data(li, 1, option2-1, &pokemon);
                print_pokemon(pokemon);
                break;
            default:
                printf("alternativa incorreta\n");
                break;
        }
    }while(option!=0);

    delete_list(li);

    return 0;
}

void print_pokemon(Pokemon pokemon){
    printf("------------------------------------------------------------------------------------------------\n");

    printf("ID: %d", pokemon.ID);
    printf("\t\t\tNome: %s", pokemon.name);
    if (strlen(pokemon.name) >= 10){
        printf("\tLendario: %s\n", pokemon.Legendary);
    }
    else{
        printf("\t\tLendario: %s\n", pokemon.Legendary);
    }

    printf("Tipo 1: %s", pokemon.type1);

    if (strlen(pokemon.type1) < 8){
        printf("\t");
    }

    if (strcmp(pokemon.type2, "xxxx")){
        printf("\tTipo 2: %s\t", pokemon.type2);
    }
    else{
        printf("\tTipo 2: \t");
    }
    printf("\tTotal Pontos: %d\n", pokemon.total);

    printf("Hp: %d", pokemon.HP);
    printf("\t\t\tVelocidade: %d", pokemon.Speed);
    printf("\t\tStagio de evolucao: %d\n", pokemon.Stage);

    printf("Attack: %d", pokemon.Attack);
    printf("\t\tDefesa: %d", pokemon.Defense);
    printf("\t\tSp. Attack: %d", pokemon.Sp_Attack);
    printf("\t\tSp. Defesa: %d\n", pokemon.Sp_Defense);

    printf("------------------------------------------------------------------------------------------------\n\n");
}
