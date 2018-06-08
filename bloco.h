#ifndef BLOCO_h
#define BLOCO_h
#include "palavra.h"
#include <vector>
using std::vector;
#include <memory>
#include <iterator>

/**@details A classe bloco é uma abstração de  um bloco de momória de uma computador,
* cada bloco possui uma tag id_bloco, um endereco e uma vecto<Palavra>*/
class Bloco
{
	/*A classe Linha, não hedará o atributo endereço,pois ela também hedará  */
private:
	/**@details O Atributo estático endereço inicia-se a sua contagem de 0 e irá até ((n*k)-1),
	* em que n é igual a: numero de blocos ná memoria, e k é igual a: número de palavras por bloco*/
	static int endereco;
protected:
	/**@details o atributo id_bloco está declado como static porque os blocos serão listados
	* na memória de forma crescente conforme novos instanciamentos , de arcordo com a configuração do arquivo
	*, assim, comforme um novo bloco é criado id_bloco é inclementado em 1. */
	static int id_bloco;
	int m_size ;
	vector<std::shared_ptr<Palavra>> palavra;
	/*@details O atributo id circular é usado quando usa-se o método write(int), assim 
	* os dodos são inseridos de forma circular no vetor palavra , i.e., palavra[id_circula % m_size]  */
	int id_circular;

public:
	Bloco();
	Bloco(int size);
	virtual ~Bloco();
	/**@brief o método write escreve uma palavra em um bloco,@param é necessário passar um id para o vector<Palavra> do Bloco,
	* e o conteudo que será armazenado. */
	bool write( int id_palavra, int content);
	/**@details Uma sobrecarga para o método write,@param recebe apenas o conteudo, armazena o dado de forma circula no vector<Palavra>*/
	bool write(int content);
	/**@brief retorna o tomando do bloco, i.e., a quantidade de palavras em um bloco */
	int  size();
	vector<std::shared_ptr<Palavra>>::iterator getPalavra();	

	//friend std::ostream& operator<<(std::ostream &o, Bloco const &d);
};
#endif