#include <stdio.h>

/*Faça um programa capaz criar um arquivo binário e de receber os seguintes dados o nome, código e curso de alunos*/

struct alunoData{
	int cod;
	char nome[51], curso[51];
};  

int main(){
	
	int i;
	struct alunoData alunoCad = {0,"",""};
	FILE *arqbin;
	
	//Criação arquivo
	if ((arqbin = fopen("cadAluno.bin","wb+")) == NULL) {
		printf("Arquivo não pode ser aberto!");
		return(1);
	}
	else{
		for(i=1;i<=100;i++)	{
			fwrite(&alunoCad, sizeof(struct alunoData),1,arqbin);
		}
		fclose(arqbin);
	}
	
	//Inserir dados no arquivo
	if ((arqbin = fopen("cadAluno.bin", "rb+")) == NULL) {
		printf("Arquivo não pode ser aberto!");
		return(1);
	}
	else {
		puts("Digite nro de conta: 1 - 100 (0 para encerrar)");
		scanf("%d",&alunoCad.cod);
		
		while(alunoCad.cod != 0){
			puts("Digite o nome do aluno e o curso correspondente: ");
			scanf("%s %s", &alunoCad.nome, &alunoCad.curso);
			fseek(arqbin, (alunoCad.cod-1)*sizeof(struct alunoData),alunoCad.cod);
			fwrite(&alunoCad,sizeof(struct alunoData),1,arqbin);
			
			puts("Digite nro de conta: 1 - 100 (0 para encerrar)");
			scanf("%d",&alunoCad.cod);

		}

	}
	return 0;	
}

