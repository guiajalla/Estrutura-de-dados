#include <iostream>
#include <stdio.h> //Função gets()
#include <stdlib.h> //Para função malloc()
#include <string.h>
/*- Considere um cadastro de componentes com os campos:
nNome //nome do componente
nTipo //tipo do componente
nQuantidade //quantidade em estoque
nValor //valor unitário da peça
Faça um programa que apresente as seguintes opções ao usuário:

Cadastrar; Listar; Consultar.

O opção cadastrar deve inserir um novo elemento no final do  vetor utilizando o realloc.
 Listar deve apresentar todas as  informações do cadastro e Consultar deve informar todas 
 as  informações de um componente, pesquisando-o pelo nome, ou  uma mensagem caso ele não 
 esteja presente. Utilize struct para  agrupar os campos do cadastro.*/

 struct cadastro
 {
     char nNome;
     char nTipo;
     int nQuantidade;
     float nValor;
 };
 
int main() {
    int i, op;
    float *p;

    struct cadastro *cad;
    //Inicializa o ponteiro.
    p = (float*)calloc(1, sizeof(float));

    //Finalizar se ponteiro == Null
    if (p == NULL){
        system("pause");
        exit(1);
    }
    
    do
    {
        printf("\n---------- Escolha uma opção ----------");
		printf("\n1 - Cadastrar Cliente");
		printf("\n2 - Listar Clientes");
		printf("\n3 - Buscar Cliente");
		printf("\n4 - Sair");
		printf("\n---------------------------------------");
		printf("\nDigite a opção desejada: \n");
		scanf("%i", &op);
		
		switch (op)
        {
        case 1://Cadastrar
            cadastrar();
            break;
        case 2://Listar
            list_cad();
            break;
        case 3://Buscar
            buscar_cad();
            break;
        default://Erro
            printf("\nVocê digitou algo inválido!\nDigite novamente a opção desejada: ")
            scanf("%i", op);
            break;
        }
    } while (op!=4);
    
}

void cadastrar (struct cadastro cad()){
    int qtd_componente;
    printf("Digite quantos componentes deseja incluir: ");
    scanf("%d", &qtd_componente);
    qtd_componente += 1;
    p=(float*)realloc(p,qtd_componente*sizeof(float));
    for(int i=0;i<qtd_componente;i++){
    printf("\nDigite o nome: ");
	gets(cad[i]->nNome);
	fflush(stdin);
	printf("\nDigite o seu tipo: ");
	gets(cad[i]->nTipo);
	printf("\nDigite a quantidade: ");
    scanf("%i", &cad[i]->nQuantidade);
    printf("\nDigite o valor: ");
    scanf("%f", cad[i]->nValor);	
    }
}

void list_cad (struct cadastro list()){
	for (int i=0;i<qtd_componente;i++){
		if(list[i].livre==0){
			printf("\nNome:%s", list[i].nNome);
			printf("\nTipo:%s", list[i].nTipo);
			printf("\nQuantidade: %i",list[i].nQuantidade);
			printf("\nValor: %i", list[i].nValor);
			printf("\n\n");
		}
	}

void buscar_cad (struct cadastro buscar[]){
	char buscaNome[50];
	
	printf("\nDigite o nome que deseja buscar: ");
	fflush(stdin);
	gets(buscaNome);
	
	for (i=0;i<10;i++){
		if (strcomp(buscar[i].nome, buscaNome){
			printf("\nNome:%s,\nTipo: %s,\nQuantidade: %i, \nValor: %.2f.", buscar[i].nNome, buscar[i].nTipo, buscar[i].nQuantidade, buscar[i].nValor);
		}
		else {
			printf("O nome informado não consta no cadastro!");
		}
	}
}