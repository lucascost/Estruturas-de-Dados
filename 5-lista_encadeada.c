#include <stdio.h>
#include <stdlib.h>

// Cria uma lista encadeada sem tamanho definido

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

t_no *criar_lista (){
    t_no *aux;
    aux = malloc(sizeof(t_no));
    (*aux).valor = preencher();
    (*aux).prox = NULL;

    return aux;
}

t_no *adicionar_no (t_no *no){
    t_no *aux;
    aux = malloc(sizeof(t_no));
    (*aux).valor = preencher();
    (*aux).prox = no;

    return aux;
}

t_no *liberar_ponteiros(t_no *no){

    if((*no).prox==NULL){
        free((*no).prox);
        return NULL;
    } else{
       (*no).prox= liberar_ponteiros((*no).prox);
       free((*no).prox);
       return NULL;
    }
}

int main() {
    t_no *lista = NULL;
    int r;

    do{
        system("cls");

        printf(">1 - Adicionar numero\n>2 - Exibir lista \n\n");
        scanf("%i",&r);

        if(r==1){
            if(lista==NULL)
                lista = criar_lista();
            else
                lista = adicionar_no(lista);
        }

       if(r==2){
            t_no *aux = lista;
            do{
               printf("> %i \n",(*aux).valor);
               aux=(*aux).prox;
            }while(aux!=NULL);
            system("pause");
        }

    }while(r<3);

    lista=liberar_ponteiros(lista);
    free(lista);

    return 0;
}
