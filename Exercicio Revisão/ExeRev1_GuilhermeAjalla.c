#include <stdio.h>
#include <locale.h>
#include <conio.h>
#define TAM 10

/* Exercício de revisão: Guilherme Ajalla

Faça um programa para gerenciar um cadastro de um consultório médico. Seu programa deverá ter uma estrutura que armazene, para cada cliente, as seguintes informações: ? Nome; ? Sexo; ? Data de nascimento; ? Idade; ? Doenças importantes; Seu programa deve gerenciar estas informações através das seguintes opções do menu: 

1. CADASTRAR CLIENTE: Seu programa deverá ter uma função responsável pelo cadastro de clientes. A cada seleção desta opção seu programa deverá cadastrar um novo cliente, cuidando para não exceder o tamanho de sua estrutura. Esta função deverá receber as informações de cada cliente do usuário, com exceção da idade, que deverá ser calculada dentro da função. 

 2. BUSCAR CLIENTE: Esta opção do menu deve chamar uma função que consulta se um determinado nome, informado pelo usuário, consta no cadastro. Se o nome não for encontrado, uma mensagem deve ser repassada ao usuário, caso o cliente seja encontrado, deve ser informado o nome, sexo e idade deste paciente. 

3. LISTAR CLIENTES: O programa deverá apresentar TODAS as informações dos clientes cadastrados, através de uma função. Não deverão ser apresentadas informações vazias. 

4. EXCLUIR CLIENTE: Esta opção deverá chamar uma função responsável por excluir um cliente, cujo nome foi informado pelo usuário. Caso o nome do cliente não seja encontrado, uma mensagem deverá ser informada. 

Para desenvolver seu programa você deve seguir as orientações abaixo: ? 

Não devem ser utilizadas variáveis globais. ? 

Todas as informações necessárias pelas funções devem ser passadas como parâmetro. ?

 O usuário deverá poder utilizar seu programa, solicitando as opções tantas vezes quanto ele deseje e em qualquer ordem. ? 

Limite o número de cadastro de pacientes a 10. Após ocupados os 10 espaços para cadastro, seu programa não deve aceitar novas inserções, a menos que algum cadastro seja excluído
*/

struct cliente {
	char nome[50];
	char sexo[10];
	int dia;
	int mes;
	int ano;
	int idade;
	char doencas_imp[250];
	int livre;
};
// Prototipos das Funcoes
void inicializa_cliente (struct cliente dados[]);
int posicao_livre (struct cliente p_livre[]);
void cad_cliente (struct cliente cad[]);
void buscar_cliente (struct cliente buscar[]);
void list_cliente (struct cliente list[]);
void excluir_cliente (struct cliente exl[]);
void excluir_cliente (struct cliente exl[]);

//Programa Principal
int main() {
	setlocale(LC_ALL, "portuguese");
	struct cliente cadastro[TAM];
	int op, p;
	
	do {
		printf("\n---------- Escolha uma opção ----------");
		printf("\n1 - Cadastrar Cliente");
		printf("\n2 - Buscar Cliente");
		printf("\n3 - Listar Clientes");
		printf("\n4 - Excluir Clientes");
		printf("\n5 - Sair");
		printf("\n---------------------------------------");
		printf("\nDigite a opção desejada: \n");
		scanf("%i", &op);
		
		switch (op)
		case 1: //Cadastrar Cliente
			cad_cliente();
		break;
		
		case 2: //Buscar Cliente
			buscar_cliente();
		break;
		
		case 3: //Listar Cliente
			list_cliente();
		break;
		
		case 4: //Excluir Cliente
			excluir_cliente();
		break;
		
		case 5: //Sair
			printf("você encerrou o programa!");
		break;
		
		default://Default
			printf("Você digitou uma opção inválida!\nDigite novamente!\n");
			scanf("%i", &op);
		break;
		
	}while(op!=5);
	
	return 0;
}
// Funções
void inicializa_cliente (struct cliente dados[]){
	int i;
	for(i=0;i<TAM;i++){
		dados[i].livre=1;
	}
	
int posicao_livre (struct cliente p_livre[]){
	int i;
	for(i=0;i<TAM;i++){
		if (!p_livre[i].livre){
			return i;
		}
	return -1;
	}
}

void cad_cliente (struct cliente cad[]){
	int p;
	
	p = posicao_livre(cliente());
			if (p==-1){
				printf("Não há posições livres!\nPara cadastrar outro cliente será necessário excluir outro antes do novo cadastro.");
			}
			else {
					printf("\nDigite o nome: ");
					gets(cad[p].nome);
					fflush(stdin);
					printf("\nDigite o seu sexo: ");
					gets(cad[p].sexo);
					printf("\nDigite a sua idade: (DD/MM/AAAA)");
					scanf("%i, %i, %i", &cad[p].dia, &cad[p].mes, &cad[p].ano);
					printf("\nSe tiver alguma doença importante para informar escreva elas aqui, caso não haja escreva 'nao'");
					gets(cad[p].doencas_imp);
					cad[p].livre = 0;
			}
		}
void buscar_cliente (struct cliente buscar[]){
	char buscaNome[50];
	
	printf("\nDigite o nome que deseja buscar: ");
	fflush(stdin);
	gets(buscaNome);
	
	for (i=0;i<10;i++){
		if (strcomp(buscar[i].nome, buscaNome){
			printf("\nNome:%s,\nSexo: %s,\nNascimento: %i/%i/%i,\nIdade: %i,\nDoenças: %s.",buscar[i].nome, buscar[i].sexo, buscar[i].dia,
			buscar[i].mes, buscar[i].ano, buscar[i].idade, buscar[i].doencas_imp);
		}
		else {
			printf("O nome informado não consta no cadastro!");
		}
	}
}
void list_cliente (struct cliente list[]){
	for (i=0;i<10;i++){
		if(list[i].livre==0){
			printf("\nNome:%s",list[i].nome);
			printf("\nSexo:%s", list[i].sexo);
			printf("\nData Nascimento: %i/%i/%i",list[i].dia, list[i].mes, list[i].ano);
			printf("\nIdade: %i", list[i].idade);
			printf("\nDoenças: %s", list[i].doencas_imp);
			printf("\n\n");
		}
	}
}
void excluir_cliente (struct cliente exl[]){
	char buscaNome[50];
	int op;
	
	printf("\nDigite o nome que deseja buscar para efetuar exclusão: ");
	fflush(stdin);
	gets(buscaNome);
	
	for (i=0;i<10;i++){
		if (strcomp(buscar[i].nome, buscaNome){
			printf("Deseja excluir o cadastro de %s ?\n[1]Sim \n[2]Não",exl[i].nome);
			scanf("%i",&op);
			if(op==1){
				exl[i].livre=1;
			else {
				printf("Escolha outra opção!");
			}
			}
		
		else{
			printf("\nEsse nome não consta no nosso cadastro!");
		}
}
}
}
}
