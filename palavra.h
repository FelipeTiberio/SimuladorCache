#ifndef PALAVRA_H
#define PALAVRA_H
#include <vector>
#include <iostream>
#include <sstream>
/*@details Neste arquivo está a implementação do classe palavra
* Para o simulador a palavra será uma "linha" ou "endereço",
* não sei se esse é o termo correto,  na memória cache e memória principal.
*/
class Palavra
{
private:
	int id_bloco;
	int endereco;
	int conteudo;
public:
	Palavra();
	Palavra(int id_bloco, int endereco, int conteudo );
	~Palavra();
	
	bool setId_bloco(int id_bloco);
	bool setEndereco(int endereco);
	bool setConteudo(int conteudo);

	int getId_bloco();
	int getEndereco();
	int getConteudo();
	/**@return O método retorna a formatação padrão de impressão de uma palvra */
	std::ostringstream printPalavra() const;

	friend std::ostream& operator<<(std::ostream &o, Palavra const &d);
};


#endif

