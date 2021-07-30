#include <iostream>
#include <locale.h>
#include <string.h>
#include <stdio.h>
#define TAM 10

/*  Foi realizada uma pesquisa entre 100 alunos de uma escola. De cada
habitante foram coletados os dados: idade, sexo (M ou F) e renda
familiar. Faça um programa que armazena os dados em arquivo e
depois executa as seguintes análises neste dados arquivados:
I. Determina quantas alunas do sexo feminino possuem mais de 18
anos.
II. Calcula a renda familiar média para os alunos pesquisados. */

struct registro {
		char sexo;
		int idade;
		int n_aluno=1;
		double renda;
	};

int main(void) {
	
	struct registro aluno;
	FILE *file;
	
// Criação do arquivo:	
	file = fopen("alunosEscola.txt", "wt");
	if(file == NULL){
		printf("Arquivo nao pode ser aberto!\n");
		system("pause");
		return 0;
	}
	do {
	printf("Digita a idade: ");
	scanf("%i", &aluno.idade);
	fscanf(file,"%i", &aluno.idade);
	
	printf("\nSexo(F/M): ");
	aluno.sexo = getchar();
	putc(aluno.sexo,file);
	
	printf("\nDigita sua renda: R$: ");
	scanf("%d", &aluno.renda);
	fscanf(file,"%d", &aluno.renda);
	
	aluno.n_aluno++;
	
	}while(aluno.n_aluno==100);
	system("pause");
	fclose(file)
	
	//Leitura do arquivo
	file = fopen("alunosEscola.txt", "r");
	
	if(file == NULL){
		printf("Arquivo nao pode ser aberto!\n");
		system("pause");
		return 0;
	}
	
	/*aluno.sexo = getc(file);
	while(c != EOF){
	printf("%c",aluno.sexo);
 	c = getc(arqtxt);*/
	
	
	return 0;
}
