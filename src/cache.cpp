#include "cache.h"
#include <vector>
#include <memory>
#include <random>
#include <iostream>
using std::cout;
using std::endl;

Cache::Cache(int num_linhas, int size_linha, int num_conjunto, int politica_sub)
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
	this->politica_sub = politica_sub;
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
	
	if(this->cacheFull() == false)
	{
	/*Na linha abaixo irei usar um construtor cópia */
	this->linhas[i] = std::make_shared<Linha>(NovaLinha);
	this->vazia = false;
	}
	else
	{
		cout << "cache cheia executar politica de sub \n";
		this->tipo_de_politica_sub( NovaLinha);
	}

	
}
void Cache::mapeamentoPorSet(shared_ptr<Bloco> NovaLinha)
{
	//int LinhasInSet = (num_linhas/num_conjunto); /* Quantidade de linhas em um conjunto */
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

void Cache::tipo_de_politica_sub(shared_ptr<Bloco> NovaLinha)
{
	switch(politica_sub)
	{
		case 1:
			cout << "executando sub_aleatorio\n";
			this->sub_aleatorio(NovaLinha);return;
		case 2:
			//this->sub_FIFO(endereco);return;	
		case 3:
			//this->sub_LFU(endereco);return;
		case 4:
			//this->sub_LRU(endereco);return;
		default:
			cout << "ERRO desoconhecido no método tipo_de_politica_sub\n";
			exit(1);
	}
}
void Cache::sub_aleatorio(shared_ptr<Bloco> NovaLinha)
{
	/*gerador de número aleatórios*/
	std::random_device rd;
	std::default_random_engine gen(rd());
	/*gera número no intervalo de 0 a (quantidade_linha_na_cache -1) */
	std::uniform_int_distribution<> dis(0,num_linhas-1);
	/*coloca o bloco em uma linha aleátoria */
	this->linhas[std::round(dis(gen))] = std::make_shared<Linha>(NovaLinha);

	return;
}
