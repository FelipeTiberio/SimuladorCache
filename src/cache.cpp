#include "cache.h"
#include <vector>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;

Cache::Cache(int num_linhas, int size_linha)
{
	this->num_linhas = num_linhas;
	this->size_linha = size_linha;

	/*Agora o vetor de Linhas na cache terá um número  de linha iguais a n_linhas valor passado como parámetro */
	this->linhas.resize(num_linhas, nullptr);
	/*Criado dinamicamente todas as linhas */
	for(int i = 0; i < num_linhas ; i++)
	{
		linhas[i] = std::make_shared<Linha>(size_linha); 
	}
	this->vazia = true;
}

Cache::~Cache(){}

bool Cache::writeInCache(int id_linha, int content)
{
	this->linhas[id_linha]->write( content);
	this->vazia = false;
	return true;
}

void Cache::showCache()
{	
	cout << "CACHE L1 \n";
	cout << "Linha-Bloco-Endereço-Conteudo \n";
	for(auto bloco : linhas)
		cout << (*bloco);
}	
