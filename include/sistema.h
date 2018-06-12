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
	/**@breif Tipo de política de substituíção */	
	int politica_sub;
	/**@breif Tipo de política de inscrição */
	int politica_ins;
	/**#brief tipo de mapeamento */
	int mapeamento;
	int num_blocos;
	int tam_bloco;
	/**@breif tamanho da memoria em endeços */
	int tam_memoria;
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
	void write(int content);
	/**@breif Recebe os comando passado pelo o usuário durante o programa */
	void executar(char * comando, int endereco);

private:
	void mapeamentoDireto(int endrec);
	void mapeamentoTassociativo(int endrec);
	void mapeamentoPorSet(int endrec);

	

};


#endif