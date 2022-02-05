
typedef struct arvore{
    int valor, altura;
    struct arvore *esq;
    struct arvore *dir;
}t_no;

void format(int n){
    if(n<100){
        (n<10)?printf(" 0%i",n) : printf(" %i",n);
    } else {
        while(n>99){
            n=n/10;
        }
        printf("%i  ",n);
    }
}

int checkFilhos(t_no *no){
    if(no->esq!=NULL && no->dir!=NULL)
        return 1;
    else if(no->esq!=NULL)
        return 2;
    else if(no->dir!=NULL)
        return 3;
    else
        return 4;
}

int busca(t_no *r, int n,int modo){  //modo: exibicao=1  confirmacao=0
    t_no *no=r;
    int i,j;
    int aux=n,c=0;
    if(n==1) {
        if(modo==1)
            format(r->valor);
        return checkFilhos(r);
    }
    for(i=0;n>9;i++){ //acha o tamanho do numero-1 ex. 10011 = 4
        n/=10;
        c++;
    }
    n=aux;
    for(i=0;i<c;i++){//para cada digito
        for(j=0;j<c-i;j++){//quantidade de divisoes para achar o digito
            n=n/10;
        }
        if(i!=0) {
            n = n - pow(10, i); // compensação
        }
        n=n%10;//digito atual //1
        if(i!=0){ //  a primeira iteração é sempre 1, a raiz, logo não ir pra direita ou esquerda
            if(n==0) {
                if (no->esq != NULL) {
                    no = no->esq;
                } else {
                    return 0;
                }
            }
            else {
                if (no->dir != NULL) {
                    no = no->dir;
                } else {
                    return 0;
                }
            }
        }
        n=aux;
    }
    n=n%10;//ultimo digito
    if(n==0) {
        if (no->esq != NULL) {
            no = no->esq;
        } else {
            return 0;
        }
    }
    else {
        if (no->dir != NULL) {
            no = no->dir;
        } else {
            return 0;
        }
    }
    if(modo==1)
        format(no->valor);

    return checkFilhos(no);
}

int binario(int n){
    if(n == 0 || n==1)
        return n;
    else{
        if(n%2==0)
            return 10*binario(n/2);
        return 10*binario(n/2)+1;
    }
}



void mostrarV(t_no *r)
{
    int i,e,j,nos=1;
    int cont=1;
    int nivel=r->altura;
    if(r!= NULL){
        for(i=0;i < r->altura+1;i++){ //exibe cada nivel
            int espac = pow(2,nivel)-1;
            if(cont>1){
                int aux=pow(2,i);
                for(j=0;j<nos;j++){
                    int exist=busca(r,binario(aux),0)>0;
                    for(e=0;e<espac;e++){
                        printf("   ");
                    }
                    (exist==1)?printf(" | "):printf("   ");
                    for(e=0;e<espac;e++){
                        printf("   ");
                    }
                    printf("   ");
                    aux++;
                }
                printf("\n");
            }//Exibe |
            for(j=0;j<nos;j++){
                for(e=0;e<espac;e++){ //aplica o espacamento para cada nó
                    printf("   ");
                }
                if(busca(r,binario(cont),1));
                else
                    printf("   ");
                cont++;
                for(e=0;e<espac;e++){ //aplica o espacamento para cada nó
                    printf("   ");
                }
                printf("   ");

            }  //Exibe o numero
            printf("\n");
            if(nivel>1){
                int diff = pow(2,nivel-1)-1;
                int vazio = espac-diff;
                int aux=pow(2,i);
                for(j=0;j<nos;j++){
                    int exist=busca(r, binario(aux),0);
                    for(e=0;e<vazio;e++){
                        printf("   ");
                    }
                    for(e=0;e<diff;e++){
                        (exist==1||exist==2)? printf("___"):printf("   ");
                    }
                    (exist==1||exist==2)? printf("_|"):printf("  ");
                    (exist==1||exist==3)? printf("|"):printf(" ");
                    for(e=0;e<diff;e++){
                        (exist==1||exist==3)? printf("___"):printf("   ");
                    }
                    for(e=0;e<vazio;e++){ //aplica o espacamento para cada nó
                        printf("   ");
                    }
                    printf("   ");
                    aux++;
                }
            }
            else if(nivel==1){
                int aux=pow(2,i);
                for(j=0;j<nos;j++){
                    if(busca(r, binario(aux),0)==1){
                        printf("  __|");
                        printf("|_  ");
                    }else if(busca(r, binario(aux),0)==2){
                        printf("  __|");
                        printf("    ");
                    }else if(busca(r, binario(aux),0)==3){
                        printf("     ");
                        printf("|_  ");
                    }else{
                        printf("         ");
                    }

                    printf("   ");
                    aux++;
                }
            }
            nivel--;
            nos*=2;
            printf("\n");
        }
    }
}