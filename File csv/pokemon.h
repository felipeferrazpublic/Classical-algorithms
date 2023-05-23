//No arquivo csv pokemon.csv usado não tem pokemon do tipo Dark

const char *TYPE [] = {"Grass","Poison","Fire","Flying"\
                ,"Water","Bug","Normal","Electric"\
                ,"Ground","Fairy","Psychic"\
                ,"Rock", "Steel","Ice","Ghost"\
                ,"Fighting","Dragon","Dark"
};

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

int readFile_pokemon(FILE *file,int max_line, Pokemon pokedex[]) {

    int max_fieldCount = 13;
    int max_line_lenght = 500;

    if (file == NULL) {
        return 0;
    }

    char line[max_line_lenght];
    int indexPokedex = 0;
    char *field;

    while(fgets(line, sizeof(line), file) != NULL) {
        field = strtok(line, ",");
        int fieldCount = 0;
        if (indexPokedex == 0){
            indexPokedex++;
            continue;
        }
        while (field != NULL && fieldCount < max_fieldCount) {
            switch(fieldCount){
            case 0:
                pokedex[indexPokedex].ID = atoi(field);
                break;
            case 2:
                strcpy(pokedex[indexPokedex].type1, field);
                break;
            case 3:
                //Tabela ASCII
                if (field[0] < 48 || 57 < field[0]) {
                    strcpy(pokedex[indexPokedex].type2, field);
                    break;
                }
                else{
                    strcpy(pokedex[indexPokedex].type2, "xxxx");
                    fieldCount++;
                }
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
                //Tabela ASCII
                if (field[0]==70 || field[0]==102){
                    strcpy(pokedex[indexPokedex].Legendary, "FALSE");
                }
                else{
                    strcpy(pokedex[indexPokedex].Legendary, "TRUE");
                }
                break;
            default:
                strcpy(pokedex[indexPokedex].name, field);
                break;

            }
            field = strtok(NULL, ",");
            fieldCount++;
        }
        indexPokedex++;
    }

    fclose(file);
    return 1;
}
