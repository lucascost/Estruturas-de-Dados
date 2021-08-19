#include <stdio.h>
#include <stdlib.h>

//pilha: insere a esquerda/remove a esquerda
//fila: insere a direita/remove a esquerda

typedef struct no{
    int valor;
    struct no *ant;
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
    (*aux).ant = NULL;
    (*aux).prox = NULL;

    return aux;
}

void exibir_lista(t_no *lista){
    if(lista==NULL)
        printf("\n\nLista vazia.");
    else{
        t_no *aux = lista;
        printf("\n\nNULL ");
        printf("<->");
        do{
            printf(" [ %i ] ",(*aux).valor);
            printf("<->");
            aux=(*aux).prox;
        }while(aux!=NULL);
        printf(" NULL");
    }
}

t_lista *adicionar_no(int m,t_lista *lista){
    if(lista==NULL){
        lista = malloc(sizeof(t_lista));
        lista->inicio=NULL;
        lista->tamanho=0;
    }
    if(m==1){ //adiciona como pilha
        if(lista->inicio==NULL){
            lista->inicio=criar_no();
            lista->fim = lista->inicio;
            lista->tamanho++;
        } else {
            t_no *novo = criar_no();
            novo->prox = lista->inicio;
            lista->inicio->ant=novo;
            lista->inicio=novo;
            lista->tamanho++;
        }
    }
    else{ //adiciona como fila
        if(lista->inicio==NULL) {
            lista->inicio = criar_no();
            lista->fim = lista->inicio;
            lista->tamanho++;
        } else {
            t_no *atual = lista->fim;
            atual->prox = criar_no();
            atual=atual->prox;
            atual->ant = lista->fim;
            lista->fim = atual;
            lista->tamanho++;
        }
    }
    return lista;
}

void remover(t_lista *lista){
    t_no *aux=lista->inicio->prox;//guarda segundo elemento

    lista->inicio->ant=NULL;
    free(lista->inicio->ant);

    lista->inicio->prox=NULL;
    free(lista->inicio->prox);

    lista->inicio=aux;
    lista->tamanho--;
}

t_lista *liberar_ponteiros(t_lista *lista){
    while(lista->tamanho>0){
        remover(lista);
    }
    lista->inicio=NULL;
    free(lista->inicio);

    lista->fim=NULL;
    free(lista->fim);

    return NULL;
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
            if(lista!=NULL){
                lista = liberar_ponteiros(lista);
            }
        }
    }while(r<4);
    lista = liberar_ponteiros(lista);
    free(lista);
}