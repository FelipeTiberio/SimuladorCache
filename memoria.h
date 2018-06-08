#ifndef MEMORIA_H
#define MEMORIA_H
#include "bloco.h"
#include <vector>
using std::vecot;
class Memoria
{
private:
	int n_blocos;
	vecot<Bloco> m_blocos;
public:
	
	Memoria(int n_blocos);
	~Memoria();
	void showMemoria();
	
};


#endif