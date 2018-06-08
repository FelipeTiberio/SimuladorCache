#include "palavra.h"
#include "bloco.h"
#include <memory>
#include <vector>
#include <iterator>
using std::vector ;

Bloco::Bloco(int size)
{
	this->m_size = size;
	this->id_bloco = 0;
}

Bloco::Bloco(){}

Bloco::~Bloco(){}

bool Bloco::write( int endereco, int conteudo, int id_palavra)
{
	this->palavra[id_palavra].setId_bloco(id_bloco);
	this->palavra[id_palavra].setEndereco(endereco);
	this->palavra[id_palavra].setConteudo(conteudo);
}
int Bloco::size()
{
	return m_size;
}
vector<Palavra>::iterator Bloco::getPalavra()
{
	return this->palavra.begin();
}


