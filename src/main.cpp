#include <iostream>
#include <fstream>
#include "bloco.h"
#include "memoria.h"
#include "sistema.h"
#include "cache.h"
#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int Bloco::id_bloco = 0;
int Bloco::endereco = 0;
int main(int argc, char const *argv[])
{	
	
	char comandosTerminal[20][20];
	string linha;
	Sistema sistema; 
	sistema.show(); /*Impressão inicial do memória e cache */

	do{ /*Irá ler o terminal por comandos separaados por espaço*/

	int i = 0;
	char linha[256 ];
	std::cin.getline (linha,256);
	char * pedaco; 
	pedaco = strtok (linha," "); /*Quebra a linha de cstring em espaço */

	while (pedaco != NULL)
	{
	   	strcpy( comandosTerminal[i], pedaco); /*copia cada um dos pedaço da string para  a matriz de chars*/
    	pedaco = strtok (NULL, " ");
    	i++;
	}
	sistema.executar(comandosTerminal[0],atoi(comandosTerminal[1]));

	}while( !(strcmp(comandosTerminal[0], "q") == 0 ) );

	cout << "*******FIM DA SIMULAÇÃO********\n";
	//exit(1); //@TODO remover isso deletar todos os ponteiros 
	return 0;
}