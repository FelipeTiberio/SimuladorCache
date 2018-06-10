#include "palavra.h"
#include <iostream>
#include <iomanip>
using std::setw;
Palavra::Palavra()
{
	id_bloco = 0;
	endereco = 0;
	conteudo = 0;
}

Palavra::Palavra(int id_bloco, int endereco, int conteudo)
{
	this->id_bloco = id_bloco;
	this->endereco = endereco;
	this->conteudo = conteudo;
}

void Palavra::setId_bloco(int id_bloco)
{
	this->id_bloco = id_bloco;

}

void Palavra::setEndereco(int endereco)
{
	this->endereco = endereco;
}

void Palavra::setConteudo(int conteudo)
{
	this->conteudo = conteudo;
}

int Palavra::getId_bloco()
{
	return id_bloco;
}

int Palavra::getEndereco()
{
	//std::cout << " o endereco é " << endereco << "\n";
	return endereco;
}

int Palavra::getConteudo()
{
	return conteudo;
}

std::ostringstream Palavra::printPalavra() const
{	
	std::ostringstream linha;
	linha << setw(3) << id_bloco  <<"-" <<  setw(3) << endereco << " - " << setw(3) << conteudo << std::endl;
	return linha;
}

std::ostream& operator<<(std::ostream &o, Palavra const &p)
{
	o  << p.id_bloco << " - " << setw(3) << p.endereco << " - " << setw(3) <<p.conteudo << std::endl;
	return o;
}

Palavra::~Palavra(){}
