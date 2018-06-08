#ifndef CACHE_H
#define CACHE_H
#include "linha.h"
#include <vector>
using std::vector;

class Cache
{
private:
	int n_linhas
	vector<linha> m_linhas;
	/**@param o atributo diz se em algum momento a clache voi carregada  */
	bool vazia;
public:

	Cache(int n_linhas);
	~Cache();
	bool write(int content);

	
};


#endif