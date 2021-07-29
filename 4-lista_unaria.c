#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}t_no;

int preencher(){
    int n;
    system("cls");
    printf("Informe o valor:\n");
    scanf("%i",&n);

    return n;
}

t_no *criar_no (){
    t_no *aux; //
    aux = malloc(sizeof(t_no));
    (*aux).valor = preencher();
    (*aux).prox = NULL;

    return aux;
}

int main() {
    t_no *lista;
    int r;

    lista = criar_no();

    do{
        system("cls");

        printf(">1 - Exibir valor \n>2 - Alterar Valor\n\n");
        scanf("%i",&r);

        if(r==1){
            printf("Valor : %i\n",(*lista).valor);
            system("pause");
        }

        if(r==2){
            (*lista).valor = preencher();
        }

    }while(r<3);

    lista=NULL;
    free(lista);

    return 0;
}

