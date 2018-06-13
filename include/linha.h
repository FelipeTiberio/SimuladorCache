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
	/**@details usando para verificar se uma linha da chache está vázia */
	bool vazia;	
	/**@detials usando para verificar o uso de um determinado bloco na cache, é incrementado em um sempre que o bloco é acessado */
	int referenciaTemporal;
	/**@details usando para armazenar na linha aque set, determinada linha pertence, apenas é usado na pólitca de sub por set */
	int set;
public:
	Linha(int size);
	Linha(std::shared_ptr<Bloco>);
	virtual ~Linha();
	/**@details Método utilizado para imprimir uma linha utilizado o operador <<*/
	virtual std::ostream& print(ostream& o);
	/**@return retorna verdadeiro se a linha nunca foi gravada, retorna falso, caso contrário*/
	bool empty();	
	void setEmpty(bool emp);
	/**@return retorna  o referenciador temporal de um bloco */
	int getReferencia();
	/**@breif decrementa  em um o referenciador temporal de linha*/
	void lessReferencial();
	/**@breif incrementa em um o referenciador temporal de linha */
	void plusReferencial();
};

#endif