#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct refe {

    struct no *pos;
    struct no *pre;

} refe;

typedef struct no {

    void *data;
    int *key;
    struct refe *ponteiro;

} No;

typedef struct header {

    int size_refe;
    int size_dado;
    int size_list;

    struct no **first_no;
    struct no **last_no;

} List;

List *cria_lista(int size_dados,int size_refe);

void * aux_add_list(void *dado, void *add, int size_dado);

int add_list_sort(List *li, void *add_element, int *add_key, int size_refe);

void delete_list(List *li);

int remove_data(List* li, int position, int parameter);

int search_data(List* li, int position, int parameter, void* data);

int size_list(List* li);

#endif

