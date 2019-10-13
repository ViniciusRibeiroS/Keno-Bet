# Keno Bet

O **Keno Bet** é um jogo de azar, em uma partida o jogador escolhe de 1 a 15 números e a banca sorteia 20 números no intervalo 1-80. Baseado na quantidade de acertos, o valor da aposta no round recebe um multiplicador, podendo gerar lucro ou prejuízo.

## Compilação

Para gerar o executável e poder jogar o **Keno Bet** utilize o seguinte comando na pasta raíz.

	$ g++ -Wall -std=c++11 src/main.cpp src/keno.cpp -I include/ -o bin/main

## Uso

Para iniciar o **Keno Bet**, ainda na pasta raíz utilize o seguinte comando.

	$ ./bin/main <nome-do-arquivo-e-sua-extensao>

### Informações contidas no arquivo

O arquivo utilizado na execução precisa ter as seguintes informações:

 - Valor total a ser apostado;
 - Número de rounds;
 - Números a serem apostados, sendo sempre valores inteiros.
 
 Caso o aqrquivo não exista, o valor apostado ou a quantidade de rounds seja menor ou igual a zero ou não exista nenhum número valido na aposta a execução é interrompida.
 Não é necessário se preocupar em colocar valores correspondentes a faixa predefinida, o **Keno Bet** se encarrega da filtragem.
 
 **O arquivo precisa ter o seguinte formato e ESTAR NA PASTA DATA**.

	2000
	4
	1 2 3 5 12 14 28 59 73 80
 


	
## Informações na tela

Durante o jogo as seguintes informações serão mostradas:
 - Tabela referente aos acertos por quantidade de números apostados de forma válida;
 - Números sorteados pela banca;
 - Números escolhidos pelo jogador;
 - Quantidade de acertos;
 - Valor apostado na rodada;
 - Valor ganhou ou perdido;
 - Total acumulado na rodada.

## Programadores

 - André Luiz Cordeiro Silva (Turma 02)
 - Vinícius Ribeiro da Silva (Turma 01)

	

