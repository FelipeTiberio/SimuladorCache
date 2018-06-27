# IMD0041 -INTRODUÇÃO A ORGANIZAÇÃO E ARQUITETURA DE COMPUTADORES- T03 (2018.1) 
###### versão 1.0
###### O programa foi desenvolvido como uma atividade complementar para a disciplina  IMD0041 
curso: Tecnologia da informação  UFRN.
==========================================================================================
## Autoroes :
	
	Felipe Tiberio Maciel Barbosa /  CLENILSON JOSE SILVA DE SOUSA / MARCELO NUNES FERREIRA COSTA 

## Simulador de memória cache 

	O programa simula as políticas mapeamento e substituição de blocos da memória principal 
	para a memória cache a partir de uma arquivo de configuração config/config.txt em que cada 
	linha desse arquivo possui um número com as configurações para o sistema na seguinte regra:

	Nº linha | Descrição da configuração 
	1 Tamanho do bloco (em número de palavras)
	2 Numero de linhas da cache
	3 Numero de blocos da memória principal
	4 Mapeamento (1 – Direto; 2 – Totalmente Associativo; 3 – Parcialmente Associativo)
	5 Numero de conjuntos (caso não seja Parcialmente Associativo, ler o valor normalmente mas desconsidere-o)
	6 Política de substituição (1 – Aleatório; 2 – FIFO; 3 – LFU; 4 – LRU)
	7 Política de Escrita (1 – Write-back; 2 – Write-Through)
	
	# Exemplo de arquivo de configuração

	Arquivo config.txt: O que significa:
	4						Cada bloco contém 4 palavras
	4						A cache tem 4 linhas (ou seja, comportam até 4 blocos vindos da memória)
	6						A memória principal tem 6 blocos
	3						Mapeamento Parcialmente Associativo
	2						Dois conjuntos
	3						Política de substituição LFU
	1 						Política de escrita Write-back
	
==========================================================================================

## Como copilar e executar o programa :
	
	Para a copilação será o bastante ter o copilador g++ e o make 
	instalados.

	# Vá para o diretório em que o arquivo mekefile.
	# escreva para copilar:
	$ make
	# para executar :
	$ ./simulador
==========================================================================================
	
## Como usar ( comando suportados ):

	Inicialmente quando o programa é executado é exibido o status atual de como está
	a memória cache e a memória principal. A cache estará vazia, e a memória principal 
	estará completa com valores aleatórios.

		CACHE L1 
	Linha-Bloco-Endereço-Conteudo 
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	x - x - x
	MEMÓRIA PRINCIPAL
	0 -   0 - 380
	0 -   1 -  62
	0 -   2 - 992
	0 -   3 - 618
	1 -   4 - 496
	1 -   5 - 607
	1 -   6 - 894
	1 -   7 -  38
	2 -   8 - 815
	2 -   9 - 806
	2 -  10 - 541
	2 -  11 - 810
	3 -  12 - 713
	3 -  13 - 891
	3 -  14 - 320
	3 -  15 - 358
	4 -  16 -  15
	4 -  17 - 934
	4 -  18 - 168
	4 -  19 - 718
	5 -  20 - 182
	5 -  21 - 183
	5 -  22 - 847
	5 -  23 - 228

	Há três comandos usando na execução do programa são eles o show, read e write.
	O comando read < endereço da memória > carrega um bloco da memória principal para
	uma das linhas da cache a partir de um dos endereços de alguma das palavras que estão 
	na memória principal.
	Já o comando show, imprime na tela o status atual da cache e memória principal. O último 
	comando o write ( não foi implementado até o momento da edição deste arquivo), mas com ele
	seria escrever novos conteúdos para a memória cache e memória principal.
==========================================================================================

