#ifndef KENO_H
#define KENO_H

class Board
{
	private:
		int board[80];                             //Gera inteiros Inteiros de 1-80
		float hits[16][15];                       //Tabela multiplicadora
	public:
		void set_board( void );                 /*! Cria um Array de 1-80 para teste.*/
		void set_hits( void );                 /*! Seta um Array bidimensional com os valores multiplicadores de acertos.*/
		void print_board( void );             /*! Printa no terminal a tabela de 1-80 .*/	
		void print_hits( int tam );          /*! Printa no terminal a tabela de acertos ate a quantidade de numeros apostados.*/
		float get_hits(int x, int y);       /* ! Retorna o valor exato do multiplicador baseado na quantiade de numeros apostados e de acertos.
                                               @param x = linha da tabela de acertos.
                                               @param y = coluna da tabela de acertos.
                                               @return O valor da tabela na posição [x][y]. */
};

class Bankroll
{
	private:
		int money;                                     //Variavel dinheiro
		std::vector<int> bnumbers;                    //Vector de inteiro com os numeros sorteados pelo banco
	public:                                          
		int get_bmoney( void );                     //Vamos utilizar ainda?
		std::vector<int> get_bnumbers( void );      /* ! Retorna os elementos do vector dos numeros sorteados pelo banco.
                                                       @return std::vector <int> bnumbers. */
		void sort_bnumbers( void );                 /* ! Armazeno os elementos do vector dos numeros sorteados pelo banco.*/
		void print_bnumbers( void );                /* !Printo os 15 números sorteados pelo banco.*/
};

class Player
{
	private:
		float money;                      //Variavel do dinheiro
		int rounds;                      //Variavel da quantidade de rounds
		float wage;                     //Variavel da aposta por round 
		float wage_return;             //Variavel para não alterar wage mas poder utilizar seu valor
		std::vector<int> pnumbers;    //Numeros que o Player apostou
		std::vector<int> hitados;    //Numeros que o Player acertou
	public:
		float get_pmoney( void );                  			/* !Retorna o dinheiro do jogador.
                                                               @return o inteiro referente a dinheiro */
		int get_rounds( void );                    			/* !Retorna a quantidade de rounds do jogador.
                                                               @return o inteiro referente a quantidade de rounds */
		float get_wage( void );                     		/* !Retorna o dinheiro do de aposta por cada round.
                                                               @return o inteiro referente a aposta por round */
		std::vector<int> get_pnumbers( void );      		/* !Retorna o os numeros jogados pelo Player.
                                                               @return std::vector <int> pnumbers */
		void display_initial_info();                 		/* !Print das informações iniciais como dinheiro, round e aposta por round.*/
		void display_round(int i, Bankroll a);              /* !Printo das informações do round e os numeros sorteados pelo banco.
		                                                       @paran int i = round atual
		                                                       @Bankroll a, a informação dos numeros sorteados pela classe do Banco */
		int Sizeofbet(void);                                /* !Retorna um Inteiro com a quantiade de numeros apostados pelo Player
		                                                       @return int com o size of player bet.*/
		void show_income();                       		    /* !Print das informações referentes as financas totais do player.*/
		void set_player(int argc, char** argv);      		/* !Setagem das informações do player
                                                               @paran argc a quantidade de elementos.
                                                               @paran argv a entrada do user para abrir o arquivo de entrada pelo terminal.*/
		void print_pnumbers( void );                		/* !Print dos numeros apostados pelo Player já filtrados e ordenados.*/
		void change_money(float multi);                     /* !Altera o Valor do multiplicador de acertos
                                                               @paran o multiplicador de acertos.*/
		void returnbet(float multi);                        /* !Retorna a quantidade de inteiros acertados pelo player
                                                               @paran o multiplicador de acertos.*/
        void att_money(Bankroll a, Player b ,Board c);      /* !Atualização finnanceira do Player.
		                                                       @paran Bankroll a = Para receber o Vector dos sorteados pelo banco
		                                                       @paran Player b = Para atualizad o dinheiro do jogador
		                                                       @paran Board c  = Para setar o multiplicador de acertos daquela aposta*/
        void display_tabela(Board c);                       /* !Print da tabela de acertos do Player.*/
        int size_pnumbers();                                /* !Função que gera um inteiro para limitar a tabela de acertos a quantidade de numeros apostados.*/
        void set_acertos(std::vector<int> acertados);       /* !Cria um std::vector com apenas os numeros que o player acertou.*/
        void display_acertos();                             /* !Print da quantidade de acertos e dos numeros acertados pelo player.*/
        int get_hits(Bankroll a);					        /* !Retorna a quantidade de inteiros acertados pelo player
                                                               @return o inteiro referente aos acertos.*/
};
 
void show_sumary(float money_inicial, float money_final);   /* !Print das informações do saldo final do Player
                                                               @paran o inteiro referente aos acertos.*/
int random(int x);                                          /* !Retorna um valor de 1 - x
                                                               @paran int x
                                                               @return int x.*/
int check_file(std::string arquivo);                        /* !Checa se o arquivo existe
                                                               @paran std::sting arquivo para receber o arquivo
                                                               @return -1 se não existir e 1 se existir.*/
std::vector <int> vector_sort(std::vector <int> ord);       /* !Organiza o vector de numeros em ordem crescente
                                                               @paran std::vector <int> a ser ordenado
                                                               @return std::vector <int> ordenado*/
std::vector <int> vector_unique(std::vector <int> ord);     /* !Organiza o vector retirando elementos repetidos
                                                               @paran std::vector <int> a ser checado
                                                               @return std::vector <int> checado*/

#endif