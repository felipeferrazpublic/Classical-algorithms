#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    int size_parametro = 2;
    List *li = cria_lista(sizeof(Pokemon), size_parametro);

    Pokemon Bulbasaur = {1,"Bulbasaur","Grass","Poison",318,45,49,49,65,65,45,1,"FALSE"};
    int keys[] = {Bulbasaur.ID, Bulbasaur.HP};
    add_list_sort(li, &Bulbasaur, keys, size_parametro);

    Pokemon charmander = {4,"Charmander","Fire","",309,39,52,43,60,50,65,1,"FALSE"};
    int keys2[] = {charmander.ID, charmander.HP};
    add_list_sort(li, &charmander, keys2, size_parametro);

    Pokemon Squirtle = {7,"Squirtle","Water","",314,44,48,65,50,64,43,1,"FALSE"};
    int keys3[] = {Squirtle.ID, Squirtle.HP};
    add_list_sort(li, &Squirtle, keys3, size_parametro);


/*
    int i;
    int x;
    float y;
    List *li;

    li = cria_lista(sizeof(int));

    for(i = 0; i < 10; i++){
        printf("Digite um numero: ");
        scanf("%d", &x);
        fflush(stdin);
        add_list_sort(li, &x, x);
    }

    puts("\n");
    print_lista(li);
*/
    return 0;
}
