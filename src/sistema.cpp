#include "sistema.h"
#include "cache.h"
#include "memoria.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <memory>
using std::cout; using std::endl;
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
	this->tam_memoria = tamanhoDoBloco * NumeroBlocosMemoria;
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
	/* verificam qual é o tipo de mapeamento usando */
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
{	/*
	for(int i =0 ; i < num_blocos ; i++)
	{
		for(int j = 0; j < tam_bloco ; j++)
		{
			cout <<" i = " <<  i ;
			if(memoriaPrincipal->vetorBlocos[i]->palavra[j]->getEndereco() == endereco)
			{
				cout <<" j="<< j << endl;
				std::cout << "O bloco que possui o endereco " << endereco << " é " << memoriaPrincipal->vetorBlocos[i]->getNumeroBloco() << "\n";
				cache_l1->mapeamentoDireto(memoriaPrincipal->vetorBlocos[i]);
				std::cout << "Cout entrei ddddd\n"; 
				return ;
			}
		}
	}
	*/
	/*
	for(int i = 0 ; i < num_blocos ; i++)
	{
		int end_0 = memoriaPrincipal->vetorBlocos[i]->palavra[0]->getEndereco() ;
		if( (end_0 <= endereco) && (endereco <= (end_0 + tam_bloco -1 )) )
		{
			cache_l1->mapeamentoDireto(memoriaPrincipal->vetorBlocos[i]);
			return;
		}
	}*/
	
	std::shared_ptr<Bloco> aux = std::make_shared<Bloco>(tam_bloco, endereco);

	for(int i = 0 ; i < tam_memoria ; i++)
	{
		if((*aux) == (*(memoriaPrincipal->vetorBlocos[i])))
		{
			cache_l1->mapeamentoDireto(memoriaPrincipal->vetorBlocos[i]);
			return;
		}
	}
		std::cerr <<"Erro inesperado no mapeamentoDireto \n";
	exit(1);
}

void Sistema::mapeamentoTassociativo( int endereco )
{
	/*TODO*/
}

void Sistema::mapeamentoPorSet( int endereco)
{
	/*TODO*/
}

void Sistema::write (int content )
{
	/*TODO*/
}

void  Sistema::executar(char * comando, int endereco)
{
	if(strcmp(comando, "quit")==0)
		return;
	if(strcmp(comando, "read")==0){
		this->readFromMemory(endereco);
		return;
	}
	if(strcmp(comando, "write")==0){
		this->write(endereco);
		return;
	}
	if(strcmp(comando, "show")==0){
		this->show();
		return;
	}
	std::cout << " Comando não encontrado \n";
	return;

}

