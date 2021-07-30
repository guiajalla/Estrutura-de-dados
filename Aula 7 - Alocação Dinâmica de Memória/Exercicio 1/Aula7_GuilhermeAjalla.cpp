#include <iostream>
#include <stdio.h> //Função gets()
#include <stdlib.h> //Para função malloc()
#include <string.h>

/*Considere uma struct que armazene o nome de um
aluno, suas 3 notas e a média final. Faça um programa
que aloque um vetor desta struct de acordo com o
número de alunos informados pelo usuário, leia o
nome, as 3 notas, e calcule a média. Após exiba o
nome de todos os alunos seguido de sua média. */

struct alunos{
	char nome[50];
	float nota1, nota2, nota3, media;
	
};

int main() {
	int *p; //Criando ponteiro para o vetor.
	int i, qtd_alunos;
	
	struct alunos *cadastro;
	
	//Recebendo a quantidade de alunos
	printf("Digite a quantidade de alunos: ");
	scanf("%d", &qtd_alunos);
	
	//Alocando memória para o vetor de acordo com a
	//qtd de elementos.
	p = (int *)(malloc(qtd_alunos * sizeof(int)));
	
	//Caso não tenho memória suficiente exit(1);
	if(cadastro == NULL){
		printf("\nErro de alocação de memoria");
		system("pause");
		exit(1);
	}
	
	//Recebendo dados
	for(i=0;i<qtd_alunos;i++){

		
		printf("Digite o nome do aluno: ");
		gets(cadastro[i].nome);


		printf("\nDigite a primeira nota de '%s'': ", cadastro[i].nome);
		scanf("%f", &cadastro[i].nota1);
		
		printf("\nDigite a segunda nota de '%s'': ", cadastro[i].nome);
		scanf("%f", &cadastro[i].nota2);
		
		printf("\nDigite a segunda nota de ''%s': ", cadastro[i].nome);
		scanf("%f", &cadastro[i].nota3);
		
		cadastro[i].media = (cadastro[i].nota1 + cadastro[i].nota2 + cadastro[i].nota3)/3;
	}
	
	//Mostrando as informações da Struct
	for(i=0;i<qtd_alunos;i++){
		printf("\nO aluno: '%s' tem a média '%.2f'",cadastro[i].nome, cadastro[i].media);
	}
	
	//Liberando memória
	free(p);
	system("pause");
	return 0;
}