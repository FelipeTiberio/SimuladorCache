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
Bloco::Bloco(int size, int end)
{
	this->m_size = size;
	this->palavra.resize(size, nullptr);
	this->id_circular = 0;

	for(int i = 0 ; i < size ; i++)
	{
		palavra[i] = std::make_shared<Palavra>(this->id_bloco, this->endereco, 0);
		palavra[i]->setEndereco(end);
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


std::ostream& operator<<(std::ostream &o, Bloco  &b)
{
	return b.print(o);
}

std::ostream& Bloco::print(std::ostream& o)
{
	for(auto index : palavra)
		o << (*index);
	return o;
}

int Bloco::getNumeroBloco()
{
	return this->palavra[0]->getId_bloco();
}
int Bloco::getM_size()
{
	return this->m_size;
}
int Bloco::getEndereco()
{
	return this->endereco;
}

bool Bloco::operator==( int i)
{
	if(this->endereco == i){
		return true;
	}
	return false;
}

bool Bloco::operator==( Bloco &b)
{
	int n = this->palavra.size();
	for( int i = 0; i < n ; i++)
	{
		//	std::cout << (*(b.palavra[i]));
		if( this->palavra[0]->getEndereco() == b.palavra[i]->getEndereco())
			return true;
	}
	return false;
}


