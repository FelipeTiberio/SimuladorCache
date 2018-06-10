#include "sistema.h"
#include "cache.h"
#include "memoria.h"
#include <iostream>
#include <fstream>

Sistema::Sistema() 
{
	vector<int> guardaConfig; /* Cada um dos índice do vector será uma das linhas do arquivo */
	std::ifstream config("config/config.txt"); /*Criando o stream para a leitura do arquivo*/
	if(!config)
	{
		std::cerr << " ** Erro na leitura do arquivo de configuração ** \n";
		exit(1);
	}
	/* Variáves que guardam as configurações do arquivo */
	std::string line; 
	std::string aux;
		while(getline(config,line))
	{
		std::stringstream str(line);
		std::getline(str, aux, '\n');
		guardaConfig.push_back(std::stod(aux));  /* Está linha converte de string para inteiro cada umas das linhas do arquivo*/
	}
	/*Variáveis usada para guarda a configução */
	int tamanhoDoBloco = guardaConfig[0];
	int NumeroLinhasCache = guardaConfig[1];
	int NumeroBlocosMemoria = guardaConfig[2];
	int mapeamento = guardaConfig[3];			
	int numeroConjunto = guardaConfig[4];
	int politicaSub = guardaConfig[5];		
	int politicaEscri = guardaConfig[6];
	/*instanciando a Memória principal */
	memoriaPrincipal = std::make_unique<Memoria>(NumeroBlocosMemoria,tamanhoDoBloco);
	/*instanciando a cache*/
	cache_l1 = std::make_unique<Cache>(NumeroLinhasCache,tamanhoDoBloco, numeroConjunto, politicaSub);

}
Sistema::~Sistema() {}

void Sistema::show() 
{
	cache_l1->showCache();
	memoriaPrincipal->showMemoria();
}
void Sistema::readFromMemory( int endereco)
{

}
void write (int content )
{

}

