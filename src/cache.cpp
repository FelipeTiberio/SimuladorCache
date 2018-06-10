#include "cache.h"
#include <vector>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;

Cache::Cache(int num_linhas, int size_linha, int num_conjunto)
{
	this->num_linhas = num_linhas;
	this->size_linha = size_linha;
	this->num_conjunto = num_conjunto;
	/*Agora o vetor de Linhas na cache terá um número  de linha iguais a n_linhas valor passado como parámetro */
	this->linhas.resize(num_linhas, nullptr);
	/*Criado dinamicamente todas as linhas */
	for(int i = 0; i < num_linhas ; i++)
	{
		linhas[i] = std::make_shared<Linha>(size_linha); 
	}
	this->id_circula = 0;
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
void Cache::mapeamentoDireto(std::shared_ptr<Bloco> NovaLinha)
{
	int possicao = (NovaLinha->palavra[0]->getId_bloco() % num_linhas); 
	/*Na linha abaixo irei usar um construtor cópia */
	this->linhas[possicao] = std::make_shared<Linha>(NovaLinha);
	this->vazia = false;
	id_circula++;
}
void Cache::mapeamentoToAssociativo(shared_ptr<Bloco> NovaLinha)
{
	int i = id_circula % num_linhas;
	id_circula++;
	/*Na linha abaixo irei usar um construtor cópia */
	this->linhas[i] = std::make_shared<Linha>(NovaLinha);
	this->vazia = false;

}

void Cache::mapeamentoPorSet(shared_ptr<Bloco> NovaLinha)
{

	int LinhasInSet = (num_linhas/num_conjunto); /* Quantidade de linhas em um conjunto */
	int colocarNoSet = (NovaLinha->palavra[0]->getId_bloco() % num_conjunto); /* Em que conjunto colocar */
	int colocarNalinha = colocarNoSet + colocarNoSet;

	for(int i = (colocarNalinha); i < num_linhas ; i++)
	{
		/*Sem usar política de substituíção, colocar o bloco na primeira linha do set que estiver vaga */
		if(this->linhas[i]->empty())
		{
			this->linhas[i] = std::make_shared<Linha>(NovaLinha);
			return;
		}
		/*Será verdade quando percorrer todo o set e não encontrar linhas vázias, então colocar na última linha */
		//else if( i == (colocarNoSet + LinhasInSet -1) )
		//{
		//	this->linhas[i] = std::make_shared<Linha>(NovaLinha);
		//}
	}
	
}

bool Cache::cacheFull()
{
	for(auto l : linhas)
	{
		if( l->empty()==true)
		{
			return false;
		}
	}
	return true;
}
