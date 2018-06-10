#include "memoria.h"
#include <vector>
#include <random>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;

Memoria::Memoria(int num_blocos, int tamanho_bloco)
{
	this->num_blocos = num_blocos;
	this->tamanho_bloco = tamanho_bloco;

	/* As próximas trés linhas geraram os números aleátorios
	*  o intervalo dos números gerados é [1,999] */
	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_int_distribution<> dis(1,999);
	/*-------------------------------------------------------*/
	/* Realoca o vetor de Blocos para que ele possua uma quandidade de 
	 * num_blocos.*/
	this->vetorBlocos.resize(num_blocos, nullptr);	
	/* Criando dinamicamente todos os blocos*/
	for(int i = 0; i < num_blocos ; i++)
	{
		this->vetorBlocos[i] = std::make_shared<Bloco>(tamanho_bloco);
		/* Preenchedo os blocos criados com valores aleátorios
		*  Usando o método de inserção circular. */
		for(int j = 0; j < tamanho_bloco ; j++)
		{
			this->vetorBlocos[i]->write(std::round(dis(gen)));
		}
	}
}

Memoria::~Memoria(){}

void Memoria::showMemoria()
{
		cout << "MEMÓRIA PRINCIPAL\n";
		for(auto bloco : vetorBlocos)
			cout << (*bloco);
		cout << endl;
}