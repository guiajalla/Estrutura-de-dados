#include <iostream>


int main() {
	FILE *arquivo;
	fopen("teste.txt","wt"); //wt = gravação
	if (arquivo==NULL) {
		printf("Não foi possível abrir o arquivo");
		exit(0);
	}
	fclose(arquivo);
	system("pause");
	return 0;
}
