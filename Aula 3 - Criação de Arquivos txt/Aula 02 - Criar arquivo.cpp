#include <iostream>


int main() {
	FILE *arquivo;
	fopen("teste.txt","wt"); //wt = grava��o
	if (arquivo==NULL) {
		printf("N�o foi poss�vel abrir o arquivo");
		exit(0);
	}
	fclose(arquivo);
	system("pause");
	return 0;
}
