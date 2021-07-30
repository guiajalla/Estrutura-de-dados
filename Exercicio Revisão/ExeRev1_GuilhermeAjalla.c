#include <stdio.h>
#include <locale.h>
#include <conio.h>
#define TAM 10

/* Exerc�cio de revis�o: Guilherme Ajalla

Fa�a um programa para gerenciar um cadastro de um consult�rio m�dico. Seu programa dever� ter uma estrutura que armazene, para cada cliente, as seguintes informa��es: ? Nome; ? Sexo; ? Data de nascimento; ? Idade; ? Doen�as importantes; Seu programa deve gerenciar estas informa��es atrav�s das seguintes op��es do menu: 

1. CADASTRAR CLIENTE: Seu programa dever� ter uma fun��o respons�vel pelo cadastro de clientes. A cada sele��o desta op��o seu programa dever� cadastrar um novo cliente, cuidando para n�o exceder o tamanho de sua estrutura. Esta fun��o dever� receber as informa��es de cada cliente do usu�rio, com exce��o da idade, que dever� ser calculada dentro da fun��o. 

 2. BUSCAR CLIENTE: Esta op��o do menu deve chamar uma fun��o que consulta se um determinado nome, informado pelo usu�rio, consta no cadastro. Se o nome n�o for encontrado, uma mensagem deve ser repassada ao usu�rio, caso o cliente seja encontrado, deve ser informado o nome, sexo e idade deste paciente. 

3. LISTAR CLIENTES: O programa dever� apresentar TODAS as informa��es dos clientes cadastrados, atrav�s de uma fun��o. N�o dever�o ser apresentadas informa��es vazias. 

4. EXCLUIR CLIENTE: Esta op��o dever� chamar uma fun��o respons�vel por excluir um cliente, cujo nome foi informado pelo usu�rio. Caso o nome do cliente n�o seja encontrado, uma mensagem dever� ser informada. 

Para desenvolver seu programa voc� deve seguir as orienta��es abaixo: ? 

N�o devem ser utilizadas vari�veis globais. ? 

Todas as informa��es necess�rias pelas fun��es devem ser passadas como par�metro. ?

 O usu�rio dever� poder utilizar seu programa, solicitando as op��es tantas vezes quanto ele deseje e em qualquer ordem. ? 

Limite o n�mero de cadastro de pacientes a 10. Ap�s ocupados os 10 espa�os para cadastro, seu programa n�o deve aceitar novas inser��es, a menos que algum cadastro seja exclu�do
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
		printf("\n---------- Escolha uma op��o ----------");
		printf("\n1 - Cadastrar Cliente");
		printf("\n2 - Buscar Cliente");
		printf("\n3 - Listar Clientes");
		printf("\n4 - Excluir Clientes");
		printf("\n5 - Sair");
		printf("\n---------------------------------------");
		printf("\nDigite a op��o desejada: \n");
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
			printf("voc� encerrou o programa!");
		break;
		
		default://Default
			printf("Voc� digitou uma op��o inv�lida!\nDigite novamente!\n");
			scanf("%i", &op);
		break;
		
	}while(op!=5);
	
	return 0;
}
// Fun��es
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
				printf("N�o h� posi��es livres!\nPara cadastrar outro cliente ser� necess�rio excluir outro antes do novo cadastro.");
			}
			else {
					printf("\nDigite o nome: ");
					gets(cad[p].nome);
					fflush(stdin);
					printf("\nDigite o seu sexo: ");
					gets(cad[p].sexo);
					printf("\nDigite a sua idade: (DD/MM/AAAA)");
					scanf("%i, %i, %i", &cad[p].dia, &cad[p].mes, &cad[p].ano);
					printf("\nSe tiver alguma doen�a importante para informar escreva elas aqui, caso n�o haja escreva 'nao'");
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
			printf("\nNome:%s,\nSexo: %s,\nNascimento: %i/%i/%i,\nIdade: %i,\nDoen�as: %s.",buscar[i].nome, buscar[i].sexo, buscar[i].dia,
			buscar[i].mes, buscar[i].ano, buscar[i].idade, buscar[i].doencas_imp);
		}
		else {
			printf("O nome informado n�o consta no cadastro!");
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
			printf("\nDoen�as: %s", list[i].doencas_imp);
			printf("\n\n");
		}
	}
}
void excluir_cliente (struct cliente exl[]){
	char buscaNome[50];
	int op;
	
	printf("\nDigite o nome que deseja buscar para efetuar exclus�o: ");
	fflush(stdin);
	gets(buscaNome);
	
	for (i=0;i<10;i++){
		if (strcomp(buscar[i].nome, buscaNome){
			printf("Deseja excluir o cadastro de %s ?\n[1]Sim \n[2]N�o",exl[i].nome);
			scanf("%i",&op);
			if(op==1){
				exl[i].livre=1;
			else {
				printf("Escolha outra op��o!");
			}
			}
		
		else{
			printf("\nEsse nome n�o consta no nosso cadastro!");
		}
}
}
}
}
