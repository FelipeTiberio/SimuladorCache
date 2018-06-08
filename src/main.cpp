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
	
	int tamanhoDoBloco; 
	int NumeroLinhasCache;
	int NumeroBlocosMemoria; 
	int mapeamento;			
	int numeroConjunto;		
	int politicaSub;		
	int politicaEscri;
	std::string line; 
	std::string aux;
	/*Lendo os dados do arquivo de comfiguração */
	while(getline(config,line))
	{
		std::stringstream str(line);
		std::getline(str, aux, '\n');
		guardaConfig.push_back(std::stod(aux));
		std::cout << aux << "\n";
	}
	

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