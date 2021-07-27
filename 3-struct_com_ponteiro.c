#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Calcula a distancia entre dois pontos xy, preenchendo os dados atraves de ponteiro.

typedef struct Ponto{
    int x, y;
}t_ponto;

int pot(int num, int exp){
    if(exp==1)
        return num;
    else
        return num* pot(num,exp-1);
}

void preencher(t_ponto *p){
    printf("Digite o valor da coordenada x:\n");
    scanf("%i",&p->x);
    //         &(*p).x

    printf("Digite o valor da coordenada y:\n");
    scanf("%i",&p->y);

    p=NULL;
    free(p);
}

int main() {
    t_ponto ponto,ponto2;
    int r;
    float distancia;

    system("cls");
    preencher(&ponto);

    do{
        system("cls");
        printf(">1 - Exibir coordenadas\n>2 - Calcular distancia ate outro ponto\n>3 - Alterar coordenadas\n\n");
        scanf("%i[^\n]",&r);

        if(r==1){
            printf("\nO ponto atual tem coordenadas x= %i e y= %i\n\n",ponto.x,ponto.y);
            system("pause");
        }

        if(r==2){
            system("cls");

            printf("Informe as coordenadas do segundo ponto\n");
            preencher(&ponto2);

            distancia = sqrt( pot(ponto2.x-ponto.x,2) + pot(ponto2.y - ponto.y,2) );

            printf("\nDistancia = %.1f\n\n",distancia);
            system("pause");
        }

        if(r==3){
            system("cls");
            preencher(&ponto);
        }

    }while(r<=3);

    return 0;
}