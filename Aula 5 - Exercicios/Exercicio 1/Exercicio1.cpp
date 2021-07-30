#include <iostream>
#include <stdlib.h>
/* Faça um programa que leia todos os dados de um arquivo texto com o
formato abaixo:
49 44 34 55 69
40 33 11 23 56
Salve os mesmos dados em outro arquivo, todos os dados em uma
única linha, como mostrado abaixo.
49 44 34 55 69 40 33 11 23 56  */

int main(void) {
	
	
	FILE *file;
	file = fopen("jeito1.txt", "r");
	
	if(file == NULL){
		printf("Arquivo nao pode ser aberto!\n");
		system("pause");
		return 0;
	}
	
	int x, c, v, b, n,x2, c2, v2, b2, n2;
	
	fscanf(file, "%i %i %i %i %i\n", &x,&c,&v,&b,&n);
	fscanf(file, "%i %i %i %i %i\n", &x2,&c2,&v2,&b2,&n2);
	printf("%i %i %i %i %i\n",x, c, v,b,n);
	printf("%i %i %i %i %i\n",x2,c2,v2,b2,n2);
	
	file = fopen("outroarquivo.txt", "wt");
	if(file == NULL){
		printf("Arquivo nao pode ser aberto!\n");
		system("pause");
		return 0;
	}
	fprintf(file, "%i %i %i %i %i %i %i %i %i %i",x, c, v,b,n,x2,c2,v2,b2,n2);
	printf("\n%i %i %i %i %i %i %i %i %i %i",x, c, v,b,n,x2,c2,v2,b2,n2);
	
	
	fclose(file);
	return 0;
}
