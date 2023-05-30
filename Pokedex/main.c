#include "Lista.h"

int main()
{
    int option;
    Header descritor_list;
    descritor_list.first_no = NULL;
    descritor_list.last_no = NULL;

    do{
        printf("0 - Sair do programa\n");
        printf("1 - inserir no hp\n");
        printf("2 - imprimir lista de hp\n");
        printf("Digite abaixo sua opcao: \n");
        scanf("%d", &option);

        switch(option){
        case 0:
            break;
        case 1:
            printf("Digite o valor do hp: \n");
            Pokemon charmander;
            scanf("%d", &charmander.HP);
            inserir_element_sort(descritor_list, charmander);
            break;
        case 2:
            printf_hp(descritor_list.first_no);
            break;
        default:
            printf("opicao nao existe");
            break;
        }
    }while(option != 0);
    return 0;
}
