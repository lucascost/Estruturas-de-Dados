#include <stdio.h>
#include <stdlib.h>

// Preenche e exibe um vetor ou matriz, conforme os dados vão sendo adicionados.

#define tam 4

void exibirVetor(int v[],int posicao){
    system("cls");
    for(int i=0;i<posicao;i++){
        printf("[ %i ]  ",v[i]);
    }
    printf("\n");
    if(posicao==tam)
        system("pause");
}

void exibirMatriz(int m[tam][tam], int linhas, int colunas ){
    system("cls");
    for(int i=0;i<linhas;i++){
        if(i==linhas-1){
            for(int j=0;j<colunas;j++){
                printf("[ %i ]  ",m[i][j]);
            }
            printf("\n");
        }else{
            for(int j=0;j<tam;j++){
                printf("[ %i ]  ",m[i][j]);
            }
            printf("\n");
        }
    }
    if(linhas==tam && colunas == tam)
        system("pause");
}

int main(){
    int r=0,i,j;
    int vetor[tam];
    int matriz[tam][tam];
    do{
        system("cls");
        printf("\n> 1- Criar Vetor\n> 2- Criar Matriz\n\n:");
        scanf("%i",&r);

        if(r==1){
            system("cls");
            for(i=0;i<tam;i++){
                printf("\nDigite um valor:\n");
                scanf("%i",&vetor[i]);
                exibirVetor(vetor,i+1);
            }
        }
        if(r==2){
            system("cls");
            for(i=0;i<tam;i++){
                for(j=0;j<tam;j++){
                    printf("\nDigite um valor:\n",i+1,j+1);
                    scanf("%i",&matriz[i][j]);
                    exibirMatriz(matriz,i+1,j+1);
                }
            }
        }
    }while(r<3);
}