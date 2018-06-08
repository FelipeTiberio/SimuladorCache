#ifndef BLOCO_h
#define BLOCO_h
#include "palavra.h"
#include <vector>
using std::vector;
#include <memory>
#include <iterator>
class Bloco
{
protected:
	/**@details o atributo id_bloco está declado como static porque os blocos serão listados
	* na memória de forma crescente conforme novos instanciamentos , de arcordo com a configuração do arquivo
	*, assim, comforme um novo bloco é criado id_bloco é inclementado em 1. */
	int id_bloco;/**@TODO corrigir isso depos e colocar o id bloco como static */
	int m_size;
	std::vector<Palavra> palavra;
public:
	Bloco();
	Bloco(int size);
	virtual ~Bloco();
	/**@brief o método write_bloco, é um método setter para uma da palavras do bloco */
	bool write( int endereco, int conteudo, int id_palavra);
	/**@brief retorna o tomando do bloco, i.e., a quantidade de palavras em um bloco */
	int  size();
	vector<Palavra>::iterator getPalavra();	

	//friend std::ostream& operator<<(std::ostream &o, Bloco const &d);
};
#endif