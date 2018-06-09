#include <iostream>
#include <fstream>
#include "bloco.h"
#include "memoria.h"
#include "cache.h"
#include <string>
#include <vector>
using std::vector;

int Bloco::id_bloco = 0;
int Bloco::endereco = 0;
int main(int argc, char const *argv[])
{	
	vector<int> guardaConfig; /* Cada um dos índice do vector será uma das linhas do arquivo */
	/* Criando o stream de leitura do arquivo */
	std::ifstream config("config/config.txt");
	if(!config)
	{
		std::cerr << " ** Erro na leitura do arquivo de configuração ** \n";
		exit(1);
	}
	/* Variáves que guardam as configurações do arquivo */
	std::string line; 
	std::string aux;
	/*Lendo os dados do arquivo de comfiguração */
	while(getline(config,line))
	{
		std::stringstream str(line);
		std::getline(str, aux, '\n');
		/* Está linha converte de string para inteiro cada umas das linhas do arquivo.
		*  cada uma das linhas lidas são um índice do vector.*/
		guardaConfig.push_back(std::stod(aux)); 
	}
	int tamanhoDoBloco = guardaConfig[0];
	int NumeroLinhasCache = guardaConfig[1];
	int NumeroBlocosMemoria = guardaConfig[2];
	int mapeamento = guardaConfig[3];			
	int numeroConjunto = guardaConfig[4];
	int politicaSub = guardaConfig[5];		
	int politicaEscri = guardaConfig[6];
	/*Teste da memória, passando como parâmetro a quantidade de blocos 
	e o número de palvras por bloco*/
	Memoria MemoriaPrincipal(NumeroBlocosMemoria,tamanhoDoBloco);
	/*Teste da memória cache, passando como parâmetro 
	número de linha na cache e o tamanho de cada linha*/
	Cache cache_l1(NumeroLinhasCache,tamanhoDoBloco, numeroConjunto);
	cache_l1.showCache();
	MemoriaPrincipal.showMemoria();
	cache_l1.mapeamentoDireto(MemoriaPrincipal.vetorBlocos[0]);
	cache_l1.mapeamentoToAssociativo(MemoriaPrincipal.vetorBlocos[2]);
	cache_l1.showCache();
	MemoriaPrincipal.showMemoria();

	return 0;
}