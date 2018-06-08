#include "linha.h"
#include "bloco.h"

Linha::Linha(int size):Bloco(size)
{
	this->vazia = true;
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
