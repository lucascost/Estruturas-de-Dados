#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}t_no;

t_no *cria_lista (int n){
    t_no *aux;
    aux = malloc(sizeof(t_no));
    (*aux).valor = n;
    (*aux).prox = NULL;

    return aux;
}

void muda_valor(t_no *elemento){
    int num;
    system("cls");
    printf("Informe o novo valor:\n");
    scanf("%i",&num);
    (*elemento).valor = num;
}

int main() {
    t_no *lista;
    int r;

    lista = cria_lista(0);

    do{
        system("cls");

        printf(">1 - Exibir valor \n>2 - Alterar Valor\n\n");
        scanf("%i",&r);

        if(r==1){
            printf("Valor : %i\n",(*lista).valor);
            system("pause");
        }

        if(r==2){
            muda_valor(lista);
        }

    }while(r<3);

    lista=NULL;
    free(lista);

    return 0;
}
