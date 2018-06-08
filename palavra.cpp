#include "palavra.h"
#include <iostream>
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

bool Palavra::setId_bloco(int id_bloco)
{
	this->id_bloco = id_bloco;
}

bool Palavra::setEndereco(int endereco)
{
	this->endereco = endereco;
}

bool Palavra::setConteudo(int conteudo)
{
	this->conteudo = conteudo;
}

int Palavra::getId_bloco()
{
	return id_bloco;
}

int Palavra::getEndereco()
{
	return endereco;
}

int Palavra::getConteudo()
{
	return conteudo;
}

std::ostringstream Palavra::printPalavra() const
{	
	std::ostringstream linha;
	linha << id_bloco << " - " << endereco << " - " << conteudo << std::endl;
	return linha;
}

Palavra::~Palavra(){}
