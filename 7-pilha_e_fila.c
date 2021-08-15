#include <stdio.h>
#include <stdlib.h>

//pilha: insere a esquerda/remove a esquerda
//fila: insere a direita/remove a esquerda

typedef struct no{
    int valor;
    struct no *prox;
}t_no;

typedef struct lista{
    t_no *inicio;
    t_no *fim;
    int tamanho;
}t_lista;

int preencher(){
    int n;
    system("cls");
    printf("\n\nInforme o valor:\n");
    scanf("%i",&n);

    return n;
}

t_no *criar_no (){
    t_no *aux;
    aux = malloc(sizeof(t_no));
    aux->valor = preencher();
    (*aux).prox = NULL;

    return aux;
}

void exibir_lista(t_no *lista){
    if(lista==NULL)
        printf("\n\nLista vazia.");
    else{
        t_no *aux = lista;
        printf("\n\nlista-> ");
        do{
            printf("[ %i ]->",(*aux).valor);
            aux=(*aux).prox;
        }while(aux!=NULL);
        printf("NULL");
    }
}

t_lista *adicionar_no(int m,t_lista *aux){
    if(aux==NULL){
        aux = malloc(sizeof(t_lista));
        aux->inicio=NULL;
        aux->tamanho=0;
    }
    if(m==1){ //adiciona como pilha
        if(aux->inicio==NULL){
            aux->inicio=criar_no();
            aux->fim = aux->inicio;
            aux->tamanho++;
        } else {
            t_no *novo = criar_no();
            novo->prox=aux->inicio;
            aux->inicio=novo;
            aux->tamanho++;
        }
    }
    else{
        if(aux->inicio==NULL) {
            aux->inicio = criar_no();
            aux->fim = aux->inicio;
            aux->tamanho++;
        } else {
            aux->fim->prox = criar_no();
            aux->fim = aux->fim->prox;
            aux->tamanho++;
        }
    }
    return aux;

}

void remover(t_lista *lista){
    t_no *aux=lista->inicio->prox;
    lista->inicio=NULL;
    free(lista->inicio);
    lista->inicio=aux;
    lista->tamanho--;
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

void main(){
    t_lista *lista=NULL;
    int r,modo=1;


    do{
        system("cls");

        printf("Manipulando como ");
        (modo==1)?printf("pilha."):printf("fila.");

        if(lista!=NULL){
            exibir_lista((*lista).inicio);
            printf("\nQt. de elementos: %i",(*lista).tamanho);
        }

        printf("\n\n>1- Adicionar elemento\n>2- Remover elemento\n>3- Alterar modo\n:");
        scanf("%i",&r);

        if(r==1){
                lista=adicionar_no(modo,lista);
        }
        if(r==2){
            if((*lista).inicio!=NULL)
                remover(lista);
        }
        if(r==3) {
            modo *=-1;
            if(lista!=NULL && lista->inicio!=NULL){
                lista->inicio = liberar_ponteiros(lista->inicio);
                lista->tamanho = 0;
            }
        }
    }while(r<4);

    if(lista->inicio!=NULL){
        lista->inicio = liberar_ponteiros(lista->inicio);
        lista->tamanho = 0;
    }
    free(lista->inicio);
    free(lista->fim);
    free(lista);
}
