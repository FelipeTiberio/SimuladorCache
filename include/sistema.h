#ifndef SISTEMA_H
#define SISTEMA_H
#include "memoria.h"
#include "cache.h"
#include <memory>
using std::unique_ptr;
/*@details A classe sistema será o intermediário entre a memória cache e memória principal*/
class Sistema
{
private:	
	unique_ptr<Memoria> memoriaPrincipal;
	unique_ptr<Cache>   cache_l1;
public:

	Sistema();
	~Sistema();
	/*@breif impreme na tela o status atula da Memória príncipal de cache*/
	void show();
	/*@breif ler da memória um endereço e carrega na memória o bloco correspondente ao endereço */
	void readFromMemory(int endereco);
	/**@breif escreve na memória um conteúdo  passado como parâmetro */
	void write();
};


#endif