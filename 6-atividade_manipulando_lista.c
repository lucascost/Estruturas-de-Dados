#include <stdio.h>
#include <stdlib.h>

//Exibir formatado - ok
//Calcular media - ok
//Contar elementos - ok
//inserir no final
//remover no final

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

void exibir_lista(t_no *lista){
    if(lista==NULL)
        printf("A lista esta vazia!");
    else{
        t_no *aux = lista;
        printf("lista-> ");
        do{
            printf("[ %2i ]->",(*aux).valor);
            aux=(*aux).prox;
        }while(aux!=NULL);
        printf("NULL");
    }
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
        printf(">2 - Calcular media \n");
        printf(">3 - Contar elementos \n");
        scanf("%i",&r);

        if(r==1){
            if(lista==NULL)
                lista = criar_lista();
            else
                lista = adicionar_no(lista);
        }
        if(r==2){
           t_no *aux = lista;
           float media=0;
           int quant=0;

           do{
               media+=(*aux).valor;
               quant++;
               aux=(*aux).prox;
           }while(aux!=NULL);

           media=media/quant;
           printf("\n\n Media = %.1f\n",media);
           system("pause");
        }
        if(r==3){
            if(lista==NULL)
                printf("Lista vazia.\n");
            else{
                t_no *aux = lista;
                int quant=0;
                do{
                    aux=(*aux).prox;
                    quant++;
                }while(aux!=NULL);
                printf("\nA lista tem %i elementos.\n",quant);
            }
            system("pause");
        }
        
    }while(r<4);

    if(lista!=NULL){ //se tentar liberar com a lista vazia da erro
        lista=liberar_ponteiros(lista);
        free(lista);
    }

    return 0;
}
