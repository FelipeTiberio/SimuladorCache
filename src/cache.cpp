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
	int i = this->id_circula % num_linhas;
	/*Verifica se o endereço passado já está na cache*/
	for(int i = 0 ; i < num_linhas ; i++)
		{
			if((*NovaLinha) == (*(linhas[i])))
			{

				return;
			}
		}

	this->id_circula++;
	
	if(this->cacheFull() == false)
	{
	/*Na linha abaixo irei usar um construtor cópia */
	this->linhas[i] = std::make_shared<Linha>(NovaLinha);
	this->vazia = false;
	}
	else
	{
		this->tipo_de_politica_sub( NovaLinha);
	}
}
void Cache::mapeamentoPorSet(shared_ptr<Bloco> NovaLinha)
{
	int LinhasInSet = (num_linhas/num_conjunto); /* Quantidade de linhas em um conjunto */
	int colocarNoSet = (NovaLinha->palavra[0]->getId_bloco() % num_conjunto); /* Em que conjunto colocar */
	int colocarNalinha = colocarNoSet + colocarNoSet;
	int contaSe_set_esta_cheio = 0;	/*verifica se o set está cheio*/

	/*Verifica se o endereço passado já está na cache, caso esteja finaliza*/
	for(int i = 0 ; i < num_linhas ; i++)
		{
			if((*NovaLinha) == (*(linhas[i])))
			{

				return;
			}
		}

	/*Verifica se o conjunto conrespondente ao bloco já está se cheio, utiliza um contador para verificar */
	for(int i = (colocarNalinha); i < num_linhas ; i++)
	{
		if(this->linhas[i]->empty())
		{
			
			break;
		}
		else
		{
			contaSe_set_esta_cheio++;
		}	
	}
	/*Se o conjunto correspondente estiver cheio utiliza a politica de sub*/
	if(contaSe_set_esta_cheio == LinhasInSet)
	{
			std::random_device rd;
			std::default_random_engine gen(rd());
			std::uniform_int_distribution<> dis(colocarNalinha, colocarNalinha + LinhasInSet-1 );
			this->linhas[std::round(dis(gen))] = std::make_shared<Linha>(NovaLinha);
			return;
	}
	else /*se não está cheio coloca o bloco nomalmente no set*/
	{
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
