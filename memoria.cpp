#include "memoria.h"
#include <vector>
#include <random>
#include <memory>

Memoria::Memoria(int num_blocos, int tamanho_bloco)
{
	this->num_blocos = num_blocos;
	this->tamanho_bloco = tamanho_bloco;

	/* As próximas trés linhas geraram os números aleátorios */
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<> dis(1,999);
	/*-------------------------------------------------------*/
	/*Realoca o vetor de Blocos para que ele possua uma quandidade de 
	* num_blocos.*/
	this->vetorBlocos.resize(num_blocos, nullptr);	
	/*Criando dinamicamente todos os blocos*/
	for(int i = 0; i < num_blocos ; i++)
	{
		this->vetorBlocos[i] = std::make_shared<Bloco>(tamanho_bloco);
	}
}

Memoria::~Memoria(){}

void showMemoria()
{
	/*@TODO aqui vai a implementação para imprime todo a memória */
}