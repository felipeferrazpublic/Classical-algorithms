#include <stdio.h>
#include <stdlib.h>

// lista ponto h

#define SIZE_LIST 100

struct student {
    int ID;
    char name[30];
    float test1, test2, test3;
};

typedef struct list List;
List* create_list();
void free_list(List* list);


// lista ponto c

struct list{
    int size_element;
    struct student data[SIZE_LIST];
    /*
    struct data{
        struct student[SIZE_LIST];
    }
    */
};

List* create_list(){
    List* list;
    list = (List*) malloc(sizeof(struct list));
    if(list != NULL){
        list->size_element = 0;
    }
    return list;
}

void free_list(List* list){
    free(list);
}

// main.c

int main() {

    List *list;
    list = create_list();
    free_list(list);
    
    return 0;
}
