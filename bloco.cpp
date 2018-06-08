#include "palavra.h"
#include "bloco.h"
#include <memory>
#include <vector>
#include <iterator>
using std::vector ;

Bloco::Bloco(int size)
{
	this->m_size = size;
	/*Realocando o tamanho do vector<Palavra> para o tamanho de um bloco*/
	this->palavra.resize(size, nullptr);
	this->id_circular = 0;
	/*Já preechendo o bloco com os id_bloco, id_endereco, e um conteudo padrão 0 
	* 0 - 0 - 0 */
	for(int i = 0 ; i < size ; i++)
	{
		palavra[i] = std::make_shared<Palavra>(this->id_bloco, this->endereco, 0);
		this->endereco++;
	}
	this->id_bloco++;
}

Bloco::Bloco(){}

Bloco::~Bloco(){}

bool Bloco::write(int id_palavra, int content)
{
	this->palavra[id_palavra]->setConteudo(content);
	return true;
}
bool Bloco::write(int content)
{
	int i = id_circular % m_size;
	this->palavra[i]->setConteudo(content);
	id_circular++;
	return true;
}

int Bloco::size()
{
	return m_size;
}
vector<std::shared_ptr<Palavra>>::iterator Bloco::getPalavra()
{
	return this->palavra.begin();
}


