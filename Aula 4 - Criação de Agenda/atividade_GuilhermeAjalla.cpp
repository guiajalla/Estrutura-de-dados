#include <iostream>
#include <locale.h>
#include <string.h>
#define TAM 10
/* Crie uma agenda em C++, capaz de apresentar e executar o seguinte menu de op��o:

- cadastrar;

-Listar;

-Sair

Dados a serem cadastrados no arquivo: nome, telefone, email, endere�o e c�digo (utilize uma struct)
O programa dever� ser capaz de criar uma arquivo (caso n�o existe) e adicionar dados (voc� dever� utilizar wt, rt e a;*/
	struct agenda {
		char nome[50];
		char endereco[250];
		char email[100];
		int cod;
		int telefone;
		int livre;
	};
void inicializa (struct agenda dados[]);

int main() {
	setlocale(LC_ALL, "portuguese");
	FILE *arq;
	struct agenda cadastro[TAM];
	int op, p, cont=1;
	
	do {
		printf("\n---------- Escolha uma opc�o ----------");
		printf("\n1 - Cadastrar");
		printf("\n2 - Listar");
		printf("\n3 - Sair");
		printf("\n---------------------------------------");
		printf("\nDigite a op��o desejada: \n");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				if (cont==1){
					fopen("agenda.txt", "wt"); //Criar arquivo
					cont++;
					if (arq==NULL){
						printf("N�o foi poss�vel abrir o arquivo!!");
						exit(0);						
					}
				}
				p = posicao_livre(cadastro);
				if else(p==-1){
					printf("\nN�o h� posi��es livres!");
				}
				else{
					arq = fopen ("agenda.txt", "a");
					
				}
		}
	}while(op!=3);
	
	
	return 0;
}
void inicializa (struct agenda dados[]){
	int i;
	for (i=0; i<TAM; i++){
		dados[i].livre=1;
		}
		return;
}
int posicao_livre (struct agenda p_livre[]){
	int i;
	for(i=0;i<TAM;i++){
		if (!p_livre[i].livre){
			return i;
		}
	return -1;
	}
}
void listar(){
	FILE *arquivo;
	struct agenda listar_agenda[TAM];
	
}
