#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Lista.h"


 int main(int argc, char *argv[]) {	
	
	LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
	lista->fim=NULL;
	lista->inicio=NULL;
	char nome[30] = "opaaaaaaaaan";
	int matricula = 1;
	double nota = 1.7;
	//['','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','',]
	
	inserir(lista, nome, matricula, nota);
	inserir(lista, nome, 3, nota);
	//lerArquivo(listaPorNome, listaPorCodigo);
	exibir(lista);

	//int maxcod = 0, mincod=1000000;
	//lerArquivo(listaPorNome, listaPorCodigo, "entrada.txt");
	
	return 0;
}

    














