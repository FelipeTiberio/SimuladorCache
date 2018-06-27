# IMD0041 -INTRODUÇÃO A ORGANIZAÇÃO E ARQUITETURA DE COMPUTADORES- T03 (2018.1) 
###### versão 1.0
###### O programa foi desenvolvido como uma atividade complementar 
da disciplina de IMD0041 - curso Tecnologia da informação  UFRN.
==================

## Autoroes :
	
	Felipe Tiberio Maciel Barbosa /  CLENILSON JOSE SILVA DE SOUSA / MARCELO NUNES FERREIRA COSTA 

## Simulador de memória cache 

		O program simula as políticas mapeamento e substituição de blocos da memória principal 
	para a memória cache a partir de uma arquivo de configuração config/config.txt em que cada 
	linha desse arquivo possui um número com as configurações para o sistema na seguinte regra:

	# Tamanho do bloco (em número de palavras)
	# Numero de linhas da cache
	# Numero de blocos da memória principal
	# Mapeamento (1 – Direto; 2 – Totalmente Associativo; 3 – Parcialmente Associativo)
	# Numero de conjuntos (caso não seja Parcialmente Associativo, ler o valor normalmente mas desconsidere-o)
	# Política de substituição (1 – Aleatório; 2 – FIFO; 3 – LFU; 4 – LRU)
	# Política de Escrita (1 – Write-back; 2 – Write-Through)
	

	# Exemplo de arquivo de configuração

	Arquivo config.txt: O que significa:
	4								Cada bloco contém 4 palavras
	4								A cache tem 4 linhas (ou seja, comportam até 4 blocos vindos da memória)
	6								A memória principal tem 6 blocos
	3								Mapeamento Parcialmente Associativo
	2								Dois conjuntos
	3								Política de substituição LFU
	1 								Política de escrita Write-back
	
	
	
	
	
	

==================

## sobre como funciona a memória cache :
	
	

## Como copilar e executar o programa :
	
	Para a copilação será o bastante ter o copilador g++ e o make 
	instalados.

	# Vá para o diretório em que o arquivo mekefile.
	# Para criar a documentação 
	$ make doxy
	# escreva para copilar:
	$ make
	# para executar :
	$ ./geometria
	
## Dificuldades encontradas:


