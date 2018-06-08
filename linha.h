#ifndef LINHA_H
#define LINHA_H
#include <iostream>
using std::ostream;
#include "bloco.h"

/** @details a herda todos os métodos e atributos do um bloco */
class Linha : public Bloco
{
public:
	Linha(int size);
	virtual ~Linha();
	virtual std::ostream& print(ostream& o);	
};

#endif