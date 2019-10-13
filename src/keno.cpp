#include <iostream>
#include <random>
#include <limits>
#include <fstream>
#include <iterator>
#include <algorithm>
 

#include "keno.h"

//Board Functions

void Board::set_board( void )
{
	for(int i = 0; i < 80; i++) 
	board[i] = i+1;
}

void Board::set_hits( void )
{
	std::fstream file;
	file.open("data/hits.csv", std::ios::in);

	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			file >> hits[i][j];
		}
	}

	file.close();
}

void Board::print_hits(int tam)
{
  std::cout << "-------+---------\n"
            << "  Hits | Payout\n"
            << "-------+---------\n";

  for(int j = 0; j < tam + 1; j++)
	std::cout << j << "| " << hits[tam][j] << std::endl;

	std::cout << std::endl;
}

void Board::print_board( void )
{
	for(int i = 0; i < 80; i++)
	std::cout << board[i] << " ";
	std::cout << std::endl;
}

float Board::get_hits(int x, int y)
{
  return hits[x][y];
}

//Bankroll Functions

std::vector<int> Bankroll::get_bnumbers( void )
{
	return bnumbers;
}

void Bankroll::sort_bnumbers( void )
{
	int count;
	int new_number;
	bool valid;

	bnumbers.clear();

	for (int i = 0; i < 20; i++)
	{
		bnumbers.push_back(0);
	}

	for (int i = 0; i < 20; i++)
	{
		valid = false;

		while(valid == false)
		{
			count = 0;
			new_number = random(80);

			for (int j = 0; j < 20; j++)
			{
				if(new_number != bnumbers[j])
					count++;
			}

			if(count == 20)
				valid = true;
		}

		bnumbers[i] = new_number;
	}

	bnumbers = vector_sort(bnumbers);
}

void Bankroll::print_bnumbers( void )
{   
	std::cout << "[ ";
	for (auto it = bnumbers.begin(); it != bnumbers.end(); it++) 
  std::cout << *it << " ";
  std::cout << "]";
  std::cout << std::endl;
}

//Player Functions
std::vector<int> Player::get_pnumbers( void )
{
	return pnumbers;
}

void Player::set_acertos(std::vector<int> acertados)
{ 
  hitados = acertados;
}

float Player::get_pmoney( void )
{
  return money;
}

int Player::get_rounds( void )
{
  return rounds;
}

float Player::get_wage( void )
{
  return wage;
}

void Player::change_money(float multi)
{
  wage_return = Player::get_wage();
  wage_return *= multi;
  
  if (multi == 0.0)
  money = money - wage;

  if (multi < 1.0)
  money = money - wage_return; 

  else
  money = money + wage_return;

  std::cout << "Payout rate is " 
            <<  multi
            << " , thus you came out with: $"
            <<  wage * multi;

  std::cout << std::endl;
}

int Player::Sizeofbet(void)
{
  return pnumbers.size();
}


void Player::set_player(int argc, char** argv)
{
	  int x;

    std::string arquivo = ("data/");
    arquivo += argv[1];


    std::fstream file;
    file.open(arquivo, std::ios::in);

    file >> money;
    file >> rounds;

    while(file >> x)
    pnumbers.push_back(x);
    file.close();

    pnumbers = vector_sort(pnumbers);

    pnumbers = vector_unique(pnumbers);

    std::vector<int> aux;

    for(int i = 0; i < (int)pnumbers.size(); i++)
    {
      if(pnumbers[i] > 0 && pnumbers[i] < 81)
        aux.push_back(pnumbers[i]);
    }
    
    pnumbers = aux;
    

    while(pnumbers.size() > 15)
    pnumbers.pop_back();

}

void Player::display_initial_info()
{
  wage = money/rounds;

  std::cout << ">>>> Preparing to read bet file, please wait...\n";

  std::cout << ">>>> Bet sucessefully read!\n"
            << "You are going to wage a total of $ "
            << money
            << " dollars.\n";

  std::cout << "Going for a total of "
            << rounds
            <<" rounds, waving $ "
            << wage
            << " per round\n";

  std::cout << std::endl;

  std::cout << "Your Bet has "
            << pnumbers.size()
            << " number(s)."
            << "They are: "; print_pnumbers();
  std::cout << std::endl;
}

void Player::display_round(int i, Bankroll a)
{ 
  std::cout << "This is round #"
            << i + 1
            << " of "
            << rounds
            << " your wage is $"
            << wage
            << ". Good luck!";
  std::cout << std::endl;

  std::cout << "The sorted numbers are: "; a.print_bnumbers();

  std::cout << "Your numbers are: "; print_pnumbers();
}

void Player::display_acertos()
{
  int vezes = hitados.size();

  std::cout << "You hit "; 
  if (hitados.size() == 0)
  std::cout << "0";
  else 
  std::cout << hitados.size();
    std::cout << " number(s).\n";

  if(vezes > 0)
  {
    std::cout << "They are: [";
    for (int i = 0; i < vezes; ++i)
    std::cout << hitados[i] << " ";
    std::cout << "]";
    std::cout << std::endl;
  }
}


void Player::show_income()
{
  std::cout <<"Your net balance so far is: $"
            << money
            << " dollars.";
  std::cout << std::endl;

  std::cout << "------------------------------------------------------------------------\n";
}

void Player::print_pnumbers( void )
{   
	std::cout << "[ ";
	for (auto it = pnumbers.begin(); it != pnumbers.end(); it++) 
  std::cout << *it << " ";
  std::cout << "]";
  std::cout << std::endl;
}

void Player::att_money(Bankroll a,Player b, Board c)
{
  int second = get_hits(a);

  int tam = Player::Sizeofbet();

  float multi = c.get_hits(tam, second);

  Player::change_money(multi);
}

int Player::size_pnumbers()
{
  return pnumbers.size();
}

int Player::get_hits(Bankroll a)
{   
  std::vector<int> bankroll = a.get_bnumbers();
  std::vector<int> player = Player::get_pnumbers();
  std::vector<int> acertos;
  
  int valid = 0;

  for (auto it = player.begin(); it != player.end(); it++)
  {
    for(int i = 0; i < 15; i++)
    {
      if(*it == bankroll[i])
      {
        valid++;
        acertos.push_back(*it);
      }
    }
  }

  Player::set_acertos(acertos);
  
  return valid;
}

//Other Functions

int random(int x)
{
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<unsigned long long> dis;
  return (dis(gen)%x)+1;
}

int check_file(std::string arquivo)
{
  std::ifstream verify;
  verify.open(arquivo);

  if (!verify.is_open())
  {
  std::cerr << "Arquivo não existe\n";
  return -1;
  }

  else 
    return 0;
}

std::vector <int> vector_sort(std::vector <int> ord)
{
  int aux = 0;

  for (int i = 0; i < (int) ord.size(); i++)
  {
    for (int j = (i+1); j < (int) ord.size(); j++)
    {
      if (ord[j] < ord[i])
      {
        aux = ord[i];
        ord[i] = ord[j];
        ord[j] = aux;
      }
    }
  }

  return ord;
}

std::vector <int> vector_unique(std::vector <int> ord)
{
  for (int i = 0; i < (int) ord.size(); i++)
  {
    for (int j = (i+1); j < (int) ord.size(); j++)
    {
      if (ord[j] == ord[i])
      {
        ord.erase(ord.begin() + i);
      }
    }
  }

  return ord;
}


void show_sumary(float money_inicial, float money_final)
{
  std::cout << ">>> End of rounds\n";
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "==== SUMMARY =====\n";
  
  std::cout << ">>> You spent in this game a total of $"
            << money_inicial
            << " dollars.\n";

  std::cout << ">>> Hooray, you won $"
            << money_final
            << " dollars.See you next time! ;-)\n";


  std::cout << ">>> You are leaving the Keno table with $"
            << money_final 
            <<  " dollars.\n";
}