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

typedef struct list_void {
    void *data;

    list_void *next_no1;
    list_void *before_no1;

    list_void *next_no2;
    list_void *before_no2;

    list_void *next_no3;
    list_void *before_no3;

} list_void;

typedef struct header {

    list_void *first_element;
    list_void *last_element;
    int size_byte;
    int size_element;

} header;

int add_list(header descritor, Pokemon *pokemon);
int read_list(header descritor, Pokemon *pokemon);
//int delete_list(header descritor, Pokemon *Pokemon);
