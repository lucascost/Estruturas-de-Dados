###  Estruturas de Dados
> Obs: O intuito deste material é resumir alguns assuntos importantes para a disciplina. É recomendado comparar as informações com outras fontes.

<h4> Sumário</h4>

* <h5>Antes de começar</h5>



<h4>Antes de começar</h4>
>Para relembrar alguns assuntos que serão utilizados, com exemplos.

* Escopo de variáveis
* Subprogramas com passagem de parâmetro
* Ponteiros



<h5> Escopo de variáveis </h5>

De forma resumida,o escopo é a visibilidade da variável dentro programa, que influencia na forma em que podemos manipulá-la. No geral, em C, variáveis declaradas dentro de um subprograma ou função (inclusive a `void main()`) são consideradas variáveis locais, e as demais, variáveis globais.

 Exemplos:

A variável global pode ser usada em qualquer lugar do programa (Por isso requer mais atenção ao usar, pois pode ser modificada num momento que não deveria, se a lógica não for bem aplicada).

```c
#include <stdio.h>

int A = 5; // global

void dobro(){
	A = A*2;
}
void main(){
	dobro();
	printf("%i", A);
}
----------------------------
Saída:
10
```



A variável local fica acessível de forma direta, apenas para o subprograma ou função que a declarou, mas seu valor pode ser passado à outras variáveis como parâmetro, ou modificado através de ponteiros.

```c
#include <stdio.h>

void dobro(){
	A = A*2; // não funciona
}
void main(){
    dobro();
	int A = 5; // local
	printf("%i", A);
}
----------------------------
Saída:
5
```



<h5>Subprogramas com passagem de parâmetro</h5>

O uso de subprogramas facilita a organização do código, uma vez que podemos distribuir o problema em partes que podem até ser reutilizadas, a depender do caso. E quando precisamos "compartilhar" uma variável com esse subprogramas, utilizamos a passagem como parâmetro.  

Exemplo:


```c
#include <stdio.h>

int dobro(int n){
	n = n*2;
    return n;
}
void main(){
    int A = 4;
    int d = dobro(A);
	printf("%i", d);
}
----------------------------
Saída:
8
```

Ao passar uma variável local como parâmetro, o subprograma copia o valor da variável(A) para a variável (n). Então, se passamos apenas o valor, não há como mexer na variável original (A), ainda que seja usado o mesmo nome.

E já que a variável  n também é local, utilizamos o return para compartilhar seu valor.  



<h5>Ponteiros</h5>

Quando precisamos manipular variáveis locais, fora da função que a criou, utilizamos ponteiros. Eles nada mais são do que um tipo de variável, que guarda endereços de outros tipos de variáveis. Para exemplificar, considere uma variável "idade" do tipo `int` , é sabido que toda variável criada ocupa um espaço na memória, então se pedimos para um usuário digitar sua idade e pegarmos com o `scanf("%i", &idade);`  utilizamos o ''&'' para informar que queremos passar o endereço dessa variável, para que a função possa salvar o valor nela. Veja um pequeno exemplo de possibilidade que ponteiro permite:

```c
#include <stdio.h>

void lerIdade(int *enderecoIdade){
    printf("Informe sua idade:");
    scanf("%i",enderecoIdade);
}

void main() {
    int idade;
    lerIdade(&idade);
    printf("Voce tem %i anos! \n", idade);
}
```

Note que o subprograma `lerIdade()` recebe um parâmetro com uma pequena diferença, acrescentamos o `*` para informar que essa variável é um ponteiro, nesse caso para inteiros. No `scanf()` não foi necessário utilizar o `&`, pois a variável já esta guardando um endereço. Esse endereço é passado na `main()`, na linha `lerIdade(&idade)`, perceba que aqui precisamos utilizar o `&`. 

Outro exemplo: 

```c
#include <stdio.h>

void lerIdade(int *enderecoIdade){
    printf("Informe sua idade:");
    scanf("%i",enderecoIdade);
}

void main() {
    int idade;
    int *p; //declaração de ponteiro para inteiro
    p = &idade;//ponteiro recebe o endereço de 'idade'
    lerIdade(p);//passa o ponteiro, contendo o endereço de 'idade'

    printf("Voce tem %i anos! \n", idade);//exibe o valor na variável
    printf("Voce tem %i anos! \n", *p);//exibe o valor na variável daquele endereço
}
```

Como podemos observar uma variável do tipo ponteiro pode assumir duas "formas" : 

*p : Valor na variável apontada.

p : Endereço da variável apontada. 

<center> Em desenvolvimento, mais informações em breve...</center>
