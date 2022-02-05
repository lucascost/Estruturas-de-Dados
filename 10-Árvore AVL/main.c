#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <math.h>
#include "funcoes.c"

//Autor: Lucas Costa    13/10/2021
/*
	Este algoritmo gera uma árvore e faz o balanceamento a medida que os dados são inseridos
	Há duas formas de exibição, horizontal e vertical(esta funciona com numeros de até 2 dígitos apenas)
*/

t_no *criaNo(int n){
    t_no *novo;
    novo = (t_no*)malloc(sizeof(t_no));
    novo->dir=NULL;
    novo->esq=NULL;
    novo->valor=n;
    novo->altura=0;
    return novo;
}

int altura(t_no *r){
    if(r==NULL)
        return -1;
    else return r->altura;
}

int balanceamento(t_no *r){
    return abs(altura(r->esq) - altura(r->dir));
}

t_no *rotacaoEsq(t_no *raiz){
    int e,d;
    t_no *aux;
    aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;

    e=altura(raiz->esq);
    d=altura(raiz->dir);
    raiz->altura = (e>d)? e+1:d+1;
    d=raiz->altura;
    aux->altura = (e>d)? e+1:d+1;

    return aux;
}
t_no *rotacaoDir(t_no *raiz){
    int e,d;
    t_no *aux;
    aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    e=altura(raiz->esq);
    d=altura(raiz->dir);
    raiz->altura = (e>d)? e+1:d+1;
    e=raiz->altura;
    aux->altura = (e>d)? e+1:d+1;

    return aux;
}
t_no *rotacaoDirEsq(t_no *raiz){
    raiz->esq=rotacaoDir(raiz->esq);
    return rotacaoEsq(raiz);
}
t_no *rotacaoEsqDir(t_no *raiz){
    raiz->dir = rotacaoEsq(raiz->dir);
    return rotacaoDir(raiz);
}

t_no *insereAvl(t_no *r, int n){
    t_no *aux=r;
    int e,d;
    if(r==NULL) {
        return criaNo(n);
    } else {
        if(n == r->valor){
            printf("\nInserção inválida, número repetido.");
            sleep(1);
        } else {
            if(n < r->valor){
                r->esq=insereAvl(r->esq,n);
                if(balanceamento(r) >1){
                    if(n < r->esq->valor)
                        aux=rotacaoEsq(r);
                    else
                        aux= rotacaoDirEsq(r);
                }
            } else {
                if(n > r->valor){
                    r->dir=insereAvl(r->dir,n);
                    if(balanceamento(r) >1){
                        if(n > r->dir->valor){
                            aux=rotacaoDir(r);
                        } else {
                            aux= rotacaoEsqDir(r);
                        }
                    }
                }
            }
        }
        e=altura(aux->esq);
        d=altura(aux->dir);
        aux->altura = (e>d)? e+1:d+1;
        return aux;
    }
}

void emOrdem(t_no *r){
    if(r!=NULL){
        emOrdem(r->esq);
        printf("%i ",r->valor);
        emOrdem(r->dir);
    }
}

void preOrdem(t_no *r){
    if(r!=NULL){
        printf("%i ",r->valor);
        emOrdem(r->esq);
        emOrdem(r->dir);
    }
}

void posOrdem(t_no *r){
    emOrdem(r->esq);
    emOrdem(r->dir);
    printf("%i ",r->valor);
}

int qtNos(t_no *r){
    if(r==NULL)
        return 0;
    else
        return 1+qtNos(r->esq)+ qtNos(r->dir);
}

void mostrarH(t_no *r, int h)
{
    int i;
    if(r!= NULL){
        mostrarH(r->dir, h+1);
        for(i=0; i<h; i++){
            printf("   ");
        }
        printf("%d\n", r->valor);
        mostrarH(r->esq, h+1);
    }
}



t_no *excluir(t_no *r){
    if(r!=NULL){
        excluir(r->esq);
        excluir(r->dir);
    } else
        free(r);
    return NULL;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    int n,r;
    int mostrar_percurso=-1, visualizacao=1;
    t_no *raiz=NULL;

    do{
        system("pause");
        system("cls");
        if(raiz!=NULL){
            int nos= qtNos(raiz);

            printf("\n  Árvore\n\n");
            if(visualizacao>0)
                mostrarV(raiz);
            else
                mostrarH(raiz,0);
            printf("_________________________________________________________________");
            printf("\n  Qtd. de nós: %i   ",nos);
            printf("  Altura: %i\n",raiz->altura);
            if(mostrar_percurso>0){
                printf("\n\n  Percursos\n");
                printf("  Em Ordem: ");
                emOrdem(raiz);
                printf("\n  Pré Ordem: ");
                preOrdem(raiz);
                printf("\n  Pós Ordem: ");
                posOrdem(raiz);
                printf("\n\n");
            }

        } else {
            printf("\n  Não há árvore para exibir.\n\n");
            printf("  _________________________________________________________________\n");
        }
        printf("\n  1 - Inserir");
        printf("\n  2 - Mostrar/Ocultar Percursos");
        printf("\n  3 - Excluir árvore");
        printf("\n  4 - Trocar visualização");
        printf("\n  5 - Sair\n  > ");
        scanf("%i",&r);

        if(r==1){
            printf("\n  Informe o valor:\n  ");
            scanf("%i",&n);
            raiz=insereAvl(raiz,n);
        }
        if(r==2)
            mostrar_percurso*=-1;
        if(r==3)
            raiz=excluir(raiz);
        if(r==4)
            visualizacao*=-1;

    }while(r!=5);
    printf("Finalizando... ");
    excluir(raiz);
    return 0;
}
