#ifndef CACHE_H
#define CACHE_H
#include "linha.h"
#include "memoria.h"
#include <vector>
#include <memory>
using std::vector;
using std::make_shared;

class Cache
{
public:
	/**@breif Vector de ponteiros inteligentes para Linhas*/
	vector<std::shared_ptr<Linha>> linhas;
private:
	/**@breif O dado diz quantas linhas existem na chace */
	int num_linhas;
	/**@breif A quantidade de palavras que haverá em uma linha */
	int size_linha;
	/**@breif o atributo diz se em algum momento a cache foi carregada */
	bool vazia;
	/**@breif id_cirular é usando para preenche a cache no mapeamento associativo */
	int id_circula;
	/**@breif Quantidade de conjuntos na cache, apenas é usando no mapeamento por conjunto */
	int num_conjunto;
	/**@breif o atributo será verdadeiro quando a cache estiver cheia, caso contrário, será vázia */
	bool cheia;
	/**@breif Tipo de política de substituição*/
	int politica_sub;
	/**@breif politica de mapeamento */
	int politica_map;
public:
	/**@breif Na construção de um cache é necessário passar  a quanditade de linhas e quantidade de palavras por linha.
	*  quantidade de conjunto e a política de substituíção */
	Cache(int n_linhas, int size_linha, int num_conjunto, int politica_sub, int politica_map);

	~Cache();
	/**@details O método recebe o id da linha/bloco que guardará o conteudo
	*  Esse método funciona de forma circular, i.e, uma linha tem n palavras
	*  o método insere o conteudo em uma das n palvras de um bloco. Para, isso 
	*  Utiliza uma inserção do tipo FIFO, primeiro entra será o primeiro a ser substituido 
	*  Quando as n palavras forem preenchidas.*/

	bool writeInCache(int id_linha, int content);
	/**@details imprime na tela o status atual da memória chache */

	void showCache();
	/**@return retorna verdadeiro se a memória estiver vazia, caso contrário, retorna falso */
	bool empty();

	/**@return apenas retorna verdadeiro quando a cache estiver cheia, caso contrário, será false  */
	bool cacheFull();


	/**@details O k-ésimo bloco será armazenado na posição (k % |qunatidade_linha|) no vector de Linha */
	void mapeamentoDireto(shared_ptr<Bloco>);

	/**@details Sempre armazena o bloco na próxima linha disponivel. no cenário em que a memória
	* estiver cheia será utilizado alguma das políticas de substituição.*/
	void mapeamentoToAssociativo(shared_ptr<Bloco>);

	/**@details Divide a cache em conjuntos, cada bloco ca memória é associado a um único 
	* conjunto. A quantidade de linhas por conjunto é dado por: 
	* (|quantidade_linha|)/(|nun_conjunto|) = quantidade de linha por conjunto */
	void mapeamentoPorSet(shared_ptr<Bloco>);

	/*@breif recebe o novo bloco a ser colocado na memória, só é chamado quando a cache ou set estiver cheio, usanda uma das polítas de sub*/
	void tipo_de_politica_sub(shared_ptr<Bloco> NovaLinha);

	/**@brief usando para substituir os blocos no mapeamento associativo e por conjunto, substitui de maneira aleátorio */
	void sub_aleatorio(shared_ptr<Bloco> NovaLinha);

	/**@brief usando para substituir os blocos no mapeamento associativo e por conjunto, substitui de maneira aleátorio */
	void sub_FIFO(shared_ptr<Bloco> NovaLinha);
	void sub_LFU(int end);
	void sub_LRU(int end);
	
};
#endif