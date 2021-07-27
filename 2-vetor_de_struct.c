#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria uma lista(vetor) com struct aluno, contendo as notas, média e situação.
// A média e situação são adicionadas automaticamente.


#define quant_alunos 3
#define quant_notas 3

typedef struct struct_aluno{
    char nome[50];
    float nota[quant_notas];
    float media;
    char situacao[12];
}t_aluno;

float calc_media(t_aluno a){
    float total=0;
    int i;
    for(i=0;i<quant_notas;i++){
        total+=a.nota[i];
    }
    return total/quant_notas;
}


int main() {
    int r,i,j;
    t_aluno aluno[quant_alunos];

    do{
        system("cls");
        printf("\n> 1- Adicionar alunos\n> 2- Exibir Lista\n\n:");
        scanf("%i",&r);

        if(r==1){
            system("cls");
            for(i=0;i<quant_alunos;i++){
                system("cls");
                printf("\nDigite o nome do aluno %i:\n",i+1);
                fflush(stdin);
                scanf("%[^\n]s",aluno[i].nome);

                for(j=0;j<quant_notas;j++){
                    printf("\nDigite a nota %i:\n",j+1);
                    scanf("%f[^\n]",&aluno[i].nota[j]);
                }

                aluno[i].media = calc_media(aluno[i]);

                if(aluno[i].media>=7)
                    strcpy(aluno[i].situacao,"aprovado");
                else
                    strcpy(aluno[i].situacao,"reprovado");
            }
        }
        if(r==2){
            system("cls");
            printf("   Nome         ");

            for(i=0;i<quant_notas;i++)
                printf("Nota%i  ",i+1);

            printf("Media   Situacao\n\n");

            for (i=0;i<quant_alunos;i++) {
                printf("%i: %-11s",i+1,aluno[i].nome);
                for(j=0;j<quant_notas;j++)
                    printf("|  %2.1f ",aluno[i].nota[j]);

                printf("|  %2.1f  | %s \n",aluno[i].media, aluno[i].situacao);
            }
            printf("\n");
            system("pause");
        }
    }while(r<3);
}