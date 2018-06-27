#include "cache.h"
#include <vector>
#include <memory>
#include <random>
#include <iostream>
using std::cout;
using std::endl;

Cache::Cache(int num_linhas, int size_linha, int num_conjunto, int politica_sub, int politica_map)
{
	this->num_linhas = num_linhas;
	this->size_linha = size_linha;
	this->num_conjunto = num_conjunto;
	this->politica_map = politica_map;
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
	/* remove em um os referenciais de todas as linhas que estão na cache */
	if(id_circula != 0){
		this->lessAllReferencial();
	}

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
				linhas[i]->plusReferencial();
				return;
			}
		}
	if(this->cacheFull() == false){
		/*Na linha abaixo irei usar um construtor cópia */
		this->linhas[i] = std::make_shared<Linha>(NovaLinha);
		this->id_circula++;
		this->vazia = false;
		/* remove em um os referenciais de todas as linhas que estão na cache */
		if(id_circula != 0){
			this->lessAllReferencial();
		}
	}else{ 
		this->tipo_de_politica_sub(NovaLinha);
		/* remove em um os referenciais de todas as linhas que estão na cache */
		if(id_circula != 0){
			this->lessAllReferencial();
		}return;
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
				linhas[i]->plusReferencial();
				return;
			}
		}
	/*Verifica se o conjunto conrespondente ao bloco já está se cheio, utiliza um contador para verificar */
	for(unsigned int i = (colocarNoSet + colocarNoSet); i < linhas.size() ; i++) /**O ERRO ESTÀ AQUI **/
	{
		if(linhas[i]->getSet() == colocarNoSet)
		{
			if(this->linhas[i]->empty()){
				break;
			}else{
				contaSe_set_esta_cheio++;
			}	
		}
	}
	/*Se o conjunto correspondente estiver cheio utiliza a politica de sub*/
	if(contaSe_set_esta_cheio == LinhasInSet )
	{	
			this->tipo_de_politica_sub(NovaLinha);
			/* remove em um os referenciais de todas as linhas que estão na cache */
			if(id_circula != 0){
				this->lessAllReferencial();
			} return;
	}else /* se não está cheio coloca o bloco nomalmente no set*/ 
	{
		for(int i = (colocarNalinha); i < num_linhas ; i++)
		{
			/* Sem usar política de substituíção, colocar o bloco na primeira linha do set que estiver vaga */
			if(this->linhas[i]->empty())
			{
				this->linhas[i] = std::make_shared<Linha>(NovaLinha); 
				this->linhas[i]->Set((NovaLinha->palavra[0]->getId_bloco() % num_conjunto));/* settar em que set determinada linha pertence*/
				/* remove em um os referenciais de todas as linhas que estão na cache */
				if(id_circula != 0){
					this->lessAllReferencial();
				}
				this->id_circula++; return;
			}
		
		}
	}
	cout << "O código não deveria vim até aqui em mapeamentoPorSet()\n";
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
			this->sub_aleatorio(NovaLinha);return;
		case 2:
			this->sub_FIFO(NovaLinha);return;	
		case 3:
			this->sub_LRU(NovaLinha);return;
		case 4:
			this->sub_LRU(NovaLinha);return;
		default:
			cout << "ERRO desoconhecido no método tipo_de_politica_sub\n";exit(1);
	}
}
void Cache::sub_aleatorio(shared_ptr<Bloco> NovaLinha)
{
	/*gerador de número aleatórios*/
	std::random_device rd;
	std::default_random_engine gen(rd());
	/*gera número no intervalo de 0 a (quantidade_linha_na_cache -1) */
	std::uniform_int_distribution<> dis(0,num_linhas-1);
	/*coloca o bloco em uma linha aleátoria  na política tatalmente associativa */
	if(politica_map == 2){
			this->linhas[std::round(dis(gen))] = std::make_shared<Linha>(NovaLinha);this->id_circula++; return;
	}
	/*coloca o bloco em uma linha aleátoria  na política por set */
	if(politica_map == 3){
			int LinhasInSet = (num_linhas/num_conjunto); /* Quantidade de linhas em um conjunto */
			int colocarNoSet = (NovaLinha->palavra[0]->getId_bloco() % num_conjunto); /* Em que conjunto colocar */
			int colocarNalinha = colocarNoSet + colocarNoSet;
			std::random_device rd;
			std::default_random_engine gen(rd());
			std::uniform_int_distribution<> dis(colocarNalinha, colocarNalinha + LinhasInSet-1 );
			this->linhas[std::round(dis(gen))] = std::make_shared<Linha>(NovaLinha);
			this->id_circula++;
			return;
	}
	cout << "ERRO desoconhecido no método sub_aleatorio\n"; exit(1);
	return;
}

void Cache::sub_FIFO(shared_ptr<Bloco> NovaLinha)
{
	/*coloca o novo bloco na memória usando FIFO */
	if(politica_map == 2)
	{
		int i = id_circula % num_linhas;
		id_circula++;
		this->linhas[i] = std::make_shared<Linha>(NovaLinha); return;
	}
	if(politica_map == 3)
	{
		int LinhasInSet = (num_linhas/num_conjunto); /* Quantidade de linhas em um conjunto */
		int colocarNoSet = (NovaLinha->palavra[0]->getId_bloco() % num_conjunto); /* Em que conjunto colocar */
		int i = id_circula % LinhasInSet;
		id_circula++;
		int colocarNalinha = (colocarNoSet + colocarNoSet) + i ;
		this->linhas[colocarNalinha] = std::make_shared<Linha>(NovaLinha);
		this->linhas[colocarNalinha]->Set((NovaLinha->palavra[0]->getId_bloco() % num_conjunto));/* settar em que set determinada linha pertence*/
	}

}

void Cache::sub_LFU(shared_ptr<Bloco> NovaLinha)
{
	/**/
}

void Cache::sub_LRU(shared_ptr<Bloco> NovaLinha)
{
	int menorIndice = 0; 
	/*Para a política de associativa total*/
	if(politica_map == 2){
		int aux = this->linhas[0]->getReferencia(); // Guarda o menor referencial da primeira linha da cache 
		for(int i=0; i < num_linhas; i++) // percorre todas as linhas da cache
		{
			if(this->linhas[i]->getReferencia() < aux) // verifica se há um referencial menor o referencial que está na primeira linha 
			{
				menorIndice = i;
				aux = this->linhas[0]->getReferencia();
			}
		}
		this->linhas[menorIndice] = std::make_shared<Linha>(NovaLinha); // substitui linha com o menor referencial pela nova linha 
		this->id_circula++;
		this->linhas[menorIndice]->plusReferencial(); // incrementa em um o referencial da novalinha 
		return;

	}else if( politica_map == 3){

		int colocarNoSet = (NovaLinha->palavra[0]->getId_bloco() % num_conjunto); /* Em que conjunto colocar */
		id_circula++;
		int colocarNalinha = (colocarNoSet + colocarNoSet)  ;
		int aux = this->linhas[colocarNalinha]->getReferencia(); // Guarda o referencial o referencia da primeira linha no conjunto 

		for(unsigned int j = (colocarNoSet + colocarNoSet); j < linhas.size(); j++  ){
			if(this->linhas[j]->getReferencia() < aux) // verifica se há um referencial menor o referencial que está na primeira linha 
			{
				menorIndice = j;
				aux = this->linhas[0]->getReferencia();
			}
			this->linhas[menorIndice] = std::make_shared<Linha>(NovaLinha); // substitui linha com o menor referencial pela nova linha 
			this->linhas[colocarNalinha]->Set((NovaLinha->palavra[0]->getId_bloco() % num_conjunto));/* settar em que set determinada linha pertence*/
			this->id_circula++;
			this->linhas[menorIndice]->plusReferencial(); // incrementa em um o referencial da novalinha 
			return;
		}
	}
}
void Cache::lessAllReferencial()
{
	for(int i = 0 ; i <= id_circula % num_linhas; i++)
	{
		linhas[i]->lessReferencial();
	}
}

int Cache::menorReferencial()
{
	int menor = linhas[0]->getReferencia();
	int possicaoMenor = 0;

	for( int i = 0 ; i < (num_linhas); i++ )
	{
		if(menor > linhas[i]->getReferencia())
		{
			menor = linhas[i]->getReferencia();
			possicaoMenor = i;
		}
	}
	return possicaoMenor;
}