#include <stdio.h>
#include <stdlib.h>

int main(){

    return 0;
}













/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UI_console.h"


// Dois erros -> Não está mostrando o segundo tipo do pokemon
// e o total point está saindo em ordem errada
int main()
{
    Pokemon pokedex[151];
    FILE *file = fopen("Pokemon.csv", "r");








    int result = readFile_pokemon(file, 152, pokedex);
    if (result == 0){
        printf("Erro na leitura do arquivo");
    }
    for(int i = 1; i < 152; i++){
        printPokemon(pokedex[i]);
    }
    return 0;
}
*/
