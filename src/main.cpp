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
	
	char argv2[20][20];
	string input;
	Sistema sistema;
	sistema.show();

	do{

	char argv2[10][10];
	int i =0;
	char input[256];
	std::cin.getline (input,256);
	char * pedaco;
	
	pedaco = strtok (input," ");
	while (pedaco != NULL)
	{
	   	strcpy( argv2[i], pedaco);
    	pedaco = strtok (NULL, " ");
    	i++;
	}
	sistema.executar(argv2[0],atoi(argv2[1]));

	}while( !(strcmp(argv2[0], "q") == 0 ) );

	cout << "*******FIM DA SIMULAÇÃO********\n";
	//exit(1); //@TODO remover isso deletar todos os ponteiros 
	return 0;
}