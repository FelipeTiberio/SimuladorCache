#include <iostream>
#include <fstream>
#include "bloco.h"
#include "memoria.h"
#include "sistema.h"
#include "cache.h"
#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int Bloco::id_bloco = 0;
int Bloco::endereco = 0;
int main(int argc, char const *argv[])
{	
	/*
	vector<int> guardaConfig;  Cada um dos índice do vector será uma das linhas do arquivo 
	//////Criando o stream de leitura do arquivo 
	std::ifstream config("config/config.txt");
	if(!config)
	{
		std::cerr << " ** Erro na leitura do arquivo de configuração ** \n";
		exit(1);
	}
	/// Variáves que guardam as configurações do arquivo 
	std::string line; 
	std::string aux;
	///Lendo os dados do arquivo de comfiguração 
	while(getline(config,line))
	{
		std::stringstream str(line);
		std::getline(str, aux, '\n');
		guardaConfig.push_back(std::stod(aux)); 
	}
	int tamanhoDoBloco = guardaConfig[0];
	int NumeroLinhasCache = guardaConfig[1];
	int NumeroBlocosMemoria = guardaConfig[2];
	int mapeamento = guardaConfig[3];			
	int numeroConjunto = guardaConfig[4];
	int politicaSub = guardaConfig[5];		
	int politicaEscri = guardaConfig[6];
	
	Memoria MemoriaPrincipal(NumeroBlocosMemoria,tamanhoDoBloco);
	Cache cache_l1(NumeroLinhasCache,tamanhoDoBloco, numeroConjunto, politicaSub);

	cache_l1.showCache();
	MemoriaPrincipal.showMemoria();
	cache_l1.mapeamentoDireto(MemoriaPrincipal.vetorBlocos[0]);
	cache_l1.mapeamentoToAssociativo(MemoriaPrincipal.vetorBlocos[2]);
	cache_l1.mapeamentoPorSet(MemoriaPrincipal.vetorBlocos[3]);
	cache_l1.mapeamentoPorSet(MemoriaPrincipal.vetorBlocos[5]);
	cache_l1.showCache();
	MemoriaPrincipal.showMemoria();
	*/
	char argv2[20][20];
	string input;
	int endereco = -1;
	Sistema sistema;
	sistema.show();
	char * pedaco;
  	char * comando;
	sistema.readFromMemory(0);
	sistema.readFromMemory(23);
	sistema.show();
	/*
	do{
		int i = 0;
		//limpar o bunfer e recolhe os dados 
		char input[256];
		//Pegar toda a linha do usuário e coloca no cstring 
		std::cin.getline (input,256);
		//Será  o ponteiro que guadará as cstring separadas por um espaço em blanco
  		char * pedaco;
  		//Primeiro corte do cstring input, irá pegar tudo até o primeiro espaço em blanco 
  		pedaco = strtok (input," ");
  		//Continua cortando o cstring input até que ele acabe 
  		while (pedaco != NULL)
  		{
    	//Vai armazeno os pedaço de input em argv2
    	strcpy( argv2[i], pedaco);
    	pedaco = strtok (NULL, " ");
    	i++;
    	}
    	strcpy(comando, argv2[0]);
    	cout <<"Comando lindo foi(" << comando << ")\n";
    	endereco = atoi(argv2[1]);
    	cout <<"o endereco lido foi " << endereco << "\n";

    	cout << strcmp(comando, "quit") << endl;
	}while( !(strcmp(comando, "quit") == 0 ) );
	cout << "*******FIM********\n";
	exit(1); //@TODO remover isso deletar todos os ponteiros 
	return 0;*/
}