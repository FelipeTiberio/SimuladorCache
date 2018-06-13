#include "linha.h"
#include "bloco.h"
#include <memory>
#include <random>

Linha::Linha(int size):Bloco(size)
{
	this->vazia = true;
	this->referenciaTemporal = 1;
}
Linha::Linha(std::shared_ptr<Bloco> b):Bloco( b->getM_size())
{
	int size = b->getM_size();
	for(int i = 0; i < size; i++ )
	{
		this->palavra[i] = b->palavra[i];
		this->referenciaTemporal = 1;
	}
	this->vazia = false;
}
Linha::~Linha(){}

std::ostream& Linha::print(ostream& o)
{
	/* Entrará nesse laço caso a cache seja gravada pelomenos uma vez*/
	//int i = 0;
	if(vazia == false)
	{
		for(auto index : this->palavra)
		{
			
			o << (*index);
			
		}
		return o;
	}
	/* Cache  virgem entra aqui */
	for(auto index : this->palavra)
	{
		o << "x - x - x\n";
	}
		return o;
}

bool Linha::empty()
{
	return this->vazia;
}

void Linha::setEmpty(bool emp)
{
	this->vazia = false;
}

int Linha::getReferencia()
{
	return this->referenciaTemporal;
}

void Linha::lessReferencial()
{
	this->referenciaTemporal--;
}
void Linha::plusReferencial()
{
	this->referenciaTemporal++;
}
int Linha::getSet()
{
	return this->set;
}
void Linha::Set(int set)
{
	this->set = set;
}