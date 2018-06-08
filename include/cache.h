#ifndef CACHE_H
#define CACHE_H
#include "linha.h"
#include <vector>
#include <memory>
using std::vector;

class Cache
{
private:
	/**@breif O dado diz quantas linhas existem na chace */
	int num_linhas;
	/**@breif Vector de ponteiros inteligentes para Linhas*/
	vector<std::shared_ptr<Linha>> linhas;
	/**@breif A quantidade de palavras que haverá em uma linha */
	int size_linha;
	/**@param o atributo diz se em algum momento a cache foi carregada */
	bool vazia;
public:
	/**@breif Na construção de um cache é necessário passar  a quanditade de linhas e quantidade de palavras por linha.*/
	Cache(int n_linhas, int size_linha);
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

	
};


#endif