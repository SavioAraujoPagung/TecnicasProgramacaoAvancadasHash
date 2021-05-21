#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void inserirHash(HASHABERTA **hash, ALUNO *aluno);
ALUNO* consultarMatricula(HASHABERTA **hash, int matricula);
void excluirHash(HASHABERTA **hash, int matricula);
void exibirHash(HASHABERTA **hash);
