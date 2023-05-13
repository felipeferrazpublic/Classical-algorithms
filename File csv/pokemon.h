//No arquivo csv pokemon.csv usado não tem pokemon do tipo Dark

const char *TYPE [] = {"Grass","Poison","Fire","Flying"\
                ,"Water","Bug","Normal","Electric"\
                ,"Ground","Fairy","Psychic"\
                ,"Rock", "Steel","Ice","Ghost"\
                ,"Fighting","Dragon","Dark"
};

struct Pokemon {
        int ID;
        char name[20];
        int type1;
        int type2;
        int total;
        int HP;
        int Attack;
        int Defense;
        int Sp_Attack;
        int Sp_Defense;
        int Speed;
        int Stage;
        int Legendary;
};
