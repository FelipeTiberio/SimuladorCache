#ifndef LINHA_H
#define LINHA_H
#include <iostream>
#include <memory>
using std::ostream;
#include "bloco.h"

/** @details a herda todos os métodos e atributos do um bloco */
class Linha : public Bloco
{
private:
	/**@details usando para verificar se uma linha da chache está 
	** vázia */
	bool vazia;	
public:
	Linha(int size);
	Linha(std::shared_ptr<Bloco>);
	virtual ~Linha();
	/**@details Método utilizado para imprimir uma linha utilizado o operador <<*/
	virtual std::ostream& print(ostream& o);
	/**@return retorna verdadeiro se a linha nunca foi gravada, retorna falso, caso contrário*/
	bool empty();	
};

#endif