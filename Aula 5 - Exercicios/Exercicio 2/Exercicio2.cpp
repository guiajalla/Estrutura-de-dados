#include <iostream>
#include <stdlib.h>
/* Faça um programa que leia todos os dados de um arquivo texto com o
formato abaixo:
49 44 34 55 69
40 33 11 23 56
Salve os mesmos dados enumerados, em outro arquivo, como abaixo:
1 - 49
2 - 44
3 - 34
...
10 - 56  */

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
	fprintf(file, "1-  %i",x);
	fprintf(file, "\n2-  %i",c);
	fprintf(file, "\n3-  %i",v);
	fprintf(file, "\n4-  %i",b);
	fprintf(file, "\n5-  %i",n);
	fprintf(file, "\n6-  %i",x2);
	fprintf(file, "\n7-  %i",c2);
	fprintf(file, "\n8-  %i",v2);
	fprintf(file, "\n9-  %i",b2);
	fprintf(file, "\n10- %i",n2);
	
	
	
	fclose(file);
	return 0;
}
