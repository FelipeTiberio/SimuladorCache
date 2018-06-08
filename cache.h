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

	Cache(int n_linhas, int size_linha);
	~Cache();
	bool writeInCache(int id_linha, int content);
	void showCache();
	bool empty();

	
};


#endif