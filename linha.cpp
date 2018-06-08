#include "linha.h"
#include "bloco.h"

Linha::Linha(int size):Bloco(size)
{}
Linha::~Linha(){};

std::ostream& Linha::print(ostream& o)
{
	for(auto index : this->palavra)
		o << (*index);
	return o;
}

