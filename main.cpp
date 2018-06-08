#include <iostream>
#include "bloco.h"
#include "memoria.h"
#include "cache.h"

int Bloco::id_bloco = 0;
int Bloco::endereco = 0;

int main(int argc, char const *argv[])
{
	/*Teste da memória, passando como parâmetro a quantidade de blocos 
	e o número de palvras por bloco*/
	Memoria MemoriaPrincipal(6,4);
	/*Teste da memória cache, passando como parâmetro 
	número de linha na cache e o tamanho de cada linha*/
	Cache cache_l1(4,4);

	cache_l1.showCache();
	MemoriaPrincipal.showMemoria();

	return 0;
}