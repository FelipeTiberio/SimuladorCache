#ifndef MEMORIA_H
#define MEMORIA_H
#include "bloco.h"
#include <vector>
#include <memory>
using std::vector;
using std::shared_ptr;
class Memoria
{
private:
	int num_blocos;
	int tamanho_bloco;
	vector<shared_ptr<Bloco>> vetorBlocos;
public:
	/**@details Para construir uma memoria apenas é necessário passar o número de blocos 
	*  que ela terá. No momento que uma memória for construída todos os seus blocos 
	*  já estaram preechidos com valores no compo conteudo de forma aleátoria.*/
	Memoria(int n_blocos, int tamanho_bloco);
	~Memoria();
	/*@breif Impreme na tela a status atual da memória o */
	void showMemoria();
	
};


#endif