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
	this->tam_bloco = tamanhoDoBloco;
	int NumeroLinhasCache = guardaConfig[1];
	int NumeroBlocosMemoria = guardaConfig[2];
	this->num_blocos = NumeroBlocosMemoria;
	int mapeamento = guardaConfig[3];
	this->mapeamento = mapeamento;			
	int numeroConjunto = guardaConfig[4];
	int politicaSub = guardaConfig[5];
	this->politica_sub = politicaSub;		
	int politicaEscri = guardaConfig[6];
	this->politica_ins = politicaEscri;
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
	/*Verifica se o endereço passado existe */
	if(endereco < 0 || endereco >= ((num_blocos*tam_bloco)))
	{
		std::cout << "** Numero de endereço passado não existe na memoria principal **\n";
		exit(1);
	}
	if(this->mapeamento == 1)
	{
		mapeamentoDireto(endereco);
		return;
	}
	else if(this->mapeamento == 2)
	{
		mapeamentoTassociativo(endereco);
		return;
	}
	else if(this->mapeamento == 3)
	{
		mapeamentoPorSet(endereco);
		return;
	}
	std::cerr << " Erro muito inesperado, nunca deveria ter passado aqui, erro no readFromMemory  \n";
	exit(1);
}

void Sistema::mapeamentoDireto(int endereco)
{
	//int BlocoTocache ;
	for(int i =0 ; i < num_blocos ; i++)
	{
		for(int j = 0; j < tam_bloco ; j++)
		{
			if(memoriaPrincipal->vetorBlocos[i]->palavra[j]->getEndereco() == endereco)
			{
				std::cout << "O bloco que possui o endereco " << endereco << " é " << memoriaPrincipal->vetorBlocos[i]->getNumeroBloco() << "\n";
				cache_l1->mapeamentoDireto(memoriaPrincipal->vetorBlocos[i]);
				return ;
			}
		}
	}


	std::cerr <<"Erro inesperado no mapeamentoDireto \n";
	exit(1);
}

void Sistema::mapeamentoTassociativo( int endereco )
{

}

void Sistema::mapeamentoPorSet( int endereco)
{

}

void write (int content )
{

}

