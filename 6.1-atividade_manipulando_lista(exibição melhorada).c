#include <stdio.h>
#include <stdlib.h>

//Exibir formatado - ok
//Calcular media - ok
//Contar elementos - ok
//inserir no final - ok
//remover no final - ok

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

void adicionar_no (t_no *no){
    while((*no).prox!=NULL){
        no=(*no).prox;
    }
    (*no).prox=criar_lista();
}

int quant_itens(t_no *aux){
    if(aux==NULL)
        return 0;
    else{
        int quant=0;
        do{
            aux=(*aux).prox;
            quant++;
        }while(aux!=NULL);
        return quant;
    }
}

float calcular_media(t_no *aux){
    float media=0;
    int quant=0;

    if(aux!=NULL){
        do{
            media+=(*aux).valor;
            quant++;
            aux=(*aux).prox;
        }while(aux!=NULL);

        media=media/quant;
    }
    return media;
}

void excluir_ultimo(t_no *lista){
    int i,quant=quant_itens(lista);
    for(i=0;i< quant-2;i++){
        lista=(*lista).prox;
    }
    (*lista).prox=NULL;
    free((*lista).prox);
}

void exibir_lista(t_no *lista){
    if(lista==NULL)
        printf("Lista vazia.");
    else{
        t_no *aux = lista;
        printf("lista-> ");
        do{
            printf("[ %i ]->",(*aux).valor);
            aux=(*aux).prox;
        }while(aux!=NULL);
        printf("NULL");
    }
    int total=quant_itens(lista);
    float media = calcular_media(lista);
    printf("\n\nQt. de elementos: %i\tMedia: %.1f",total,media);
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
        exibir_lista(lista);
        printf("\n\n>1 - Adicionar numero\n");
        printf(">2 - Excluir ultimo elemento\n");
        scanf("%i",&r);

        if(r==1){
            if(lista==NULL)
                lista = criar_lista();
            else
                adicionar_no(lista);
        }
        if(r==2){
            if((*lista).prox==NULL){
                free((*lista).prox);
                lista=NULL;
            }else
                excluir_ultimo(lista);
        }
        
    }while(r<5);

    if(lista!=NULL){
        lista=liberar_ponteiros(lista);
        free(lista);
    }

    return 0;
}
