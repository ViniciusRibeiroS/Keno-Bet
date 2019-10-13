#include <iostream>
#include <fstream>
#include <vector>
#include "keno.h"

int main(int argc, char** argv)
{
	Bankroll a;
	Player b;
	Board c;
    
    //Checagem se o arquivo existe
    std::string arquivo = ("data/");
    arquivo += argv[1];
    if(check_file(arquivo) == -1)   
    return -1;
    //Fim da Checagem
    
	b.set_player(argc, argv);                       //Setagem dos dados do player
    float money_inicial = b.get_pmoney();          //Setagem do Dinheiro inicial
    int tam = b.size_pnumbers();                  //Adaptando para printar a tabela da quantidade numeros apostados
    int vezes = b.get_rounds();                  //Variavel que vai rodar os rounds 'x' vezes
    
    //Inicio da Segunda Checagem
    if( (tam <= 0))
    {
      std::cout << "Números apostados invalidos, por favor, atualize seu arquivo de apostas para uma versão válida\n";
      return -1;
    }

    if((money_inicial <= 0))
    {
      std::cout << "Dinheiro apostados invalido, por favor, atualize seu arquivo de apostas para uma versão válida\n";
      return -1;
    }

    if((vezes <= 0))
    {
      std::cout << "Números de Rounds apostados invalidos, por favor, atualize seu arquivo de apostas para uma versão válida\n";
      return -1;
    }
    //Fim da Segunda Checagem


    b.display_initial_info();                   //Mostrando as informações iniciais
    c.set_hits();                              //Preparando a tabela dos multipicadores de acertos
    c.print_hits(tam);                        //Print da tabela Multiplicadora
    
    //Entrada no Loop                                      
	for (int i = 0; i < vezes; ++i)        
	{
    a.sort_bnumbers();                   //Sorteio dos numeros do banco
    b.display_round(i, a);              //Informação sobre o round
    b.get_hits(a);                     //Setagem de acertos
    b.display_acertos();              //Print da informação dos acertos
    b.att_money(a, b ,c);            //Atualização do dinheiro do player
    b.show_income();                //Print das suas finanças
    }
    //Fim do Loop
    
    float money_final = b.get_pmoney();            //Setagem do dinheiro final
    show_sumary(money_inicial, money_final);      //Print do Sumario
	return 0;
}