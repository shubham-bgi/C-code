/**********************************
	   SOURCE CODE
**********************************/

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

char re_assign[31] = {'o', '1', '2', '3', '4', '5', '6'};
char square[31];
// horizontal                                                                                                                                                                                                               //diagonal                                                                              //opp diagonal                                                                             //for vetical
int check[39][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {7, 8, 9, 10}, {8, 9, 10, 11}, {9, 10, 11, 12}, {13, 14, 15, 16}, {14, 15, 16, 17}, {15, 16, 17, 18}, {19, 20, 21, 22}, {20, 21, 22, 23}, {21, 22, 23, 24}, {25, 26, 27, 28}, {26, 27, 28, 29}, {27, 28, 29, 30}, {1, 8, 15, 22}, {2, 9, 16, 23}, {3, 10, 17, 24}, {7, 14, 21, 28}, {8, 15, 22, 29}, {9, 16, 23, 30}, {4, 9, 13, 18}, {5, 10, 14, 19}, {6, 11, 15, 20}, {10, 15, 20, 25}, {11, 16, 21, 26}, {12, 17, 22, 27}, {1, 7, 13, 19}, {7, 13, 19, 25}, {2, 8, 14, 20}, {8, 14, 20, 26}, {3, 9, 15, 21}, {9, 15, 21, 26}, {4, 10, 16, 22}, {10, 16, 22, 28}, {5, 11, 17, 23}, {11, 17, 23, 29}, {6, 12, 18, 24}, {12, 18, 24, 30}};
char plr1[40], plr2[40];
int score1 = 0, score2 = 0, game = 0, games;
int choice_m, choice_vm;
int checkwin();
void input_name();
void show_name(int);
void new_game();
void new_match();
void new_series();
void show();
void board();

struct player
{
	char playername[50];
	int score;
	int game, games;
};
player pl1, pl2;

int main()
{
	do
	{
		show();
		cout << "\n\n                      1.Continue previous series.";
		cout << "\n                      2.Start a new game.";
		cout << "\n                      3.Quit Game.";
		cout << "\n\n                      Enter your choice.";
		cin >> choice_vm;
		switch (choice_vm)
		{
			case 1:
			{
				system("cls");
				show();
				fstream fin;
				fin.open("player_info.dat", ios::binary | ios::in);
				if (!fin)
				{
					cout << "\n\n                      NO! saved sereis found ???";
					getch();
					break;
				}
				fin.read((char *)&pl1, sizeof(pl1));
				strcpy(plr1, pl1.playername);
				score1 = pl1.score;
				game = pl1.game;
				games = pl1.games;
				fin.read((char *)&pl2, sizeof(pl1));
				strcpy(plr2, pl2.playername);
				score2 = pl2.score;
				fin.close();
				new_series();
				break;
			}

			case 2:
			{
				new_game();
				break;
			}

			case 3:
			{
				show();
				cout << "\n\n                      Bye...";
				getch();
				break;
			}

			default:
			{
				cout << "\n                      Wrong choice";
				getch();
			}
		}
	} while (choice_vm != 3);
}

/***************************************************/
// starting of a new game
/***************************************************/
void new_game()
{
	input_name();
	do
	{

		show();
		cout << "\n\n                      NEW GAME MENU";
		cout << "\n\n                      1.Start a match up game.";
		cout << "\n                      2.Start a series of this game.";
		cout << "\n                      3.To Quit.";
		cout << "\n\n                      Enter your choice";
		cin >> choice_m;
		switch (choice_m)
		{
		case 1:
			new_match();
			break;

		case 2:
			new_series();
			break;

		case 3:
			break;

		default:
			cout << "\n                      Wrong choice";
			getch();
		}
	} while (choice_m != 3);
}

/*********************************************/
// to start a new game
/*********************************************/
void new_match()
{

	int player = 1, i, s1 = 1, s2 = 2, s3 = 3, s4 = 4, s5 = 5, s6 = 6;
	char mark, choice_g;

	for (int z = 0; z <= 31; z++) // to reassign value
		square[z] = re_assign[z];
	if (choice_m == 2)
		player = (game % 2) ? 2 : 1;
	do
	{
		board();
		player = (player % 2) ? 1 : 2;
		cout << "\n                    It's your turn ";
		show_name(player);
		cout << ", enter a number:  ";
		cin >> choice_g;
		mark = (player == 1) ? 'X' : 'O';
		if (choice_g == '1' && s1 <= 25)
		{
			square[s1] = mark;
			s1 += 6;
			square[s1] = '1';
		}
		else if (choice_g == '2' && s2 <= 26)
		{
			square[s2] = mark;
			s2 += 6;
			square[s2] = '2';
		}
		else if (choice_g == '3' && s3 <= 27)
		{
			square[s3] = mark;
			s3 += 6;
			square[s3] = '3';
		}
		else if (choice_g == '4' && s4 <= 28)
		{
			square[s4] = mark;
			s4 += 6;
			square[s4] = '4';
		}
		else if (choice_g == '5' && s5 <= 29)
		{
			square[s5] = mark;
			s5 += 6;
			square[s5] = '5';
		}
		else if (choice_g == '6' && s6 <= 30)
		{
			square[s6] = mark;
			s6 += 6;
			square[s6] = '6';
		}
		else if (choice_g == 'q' || choice_g == 'Q')
		{
			show();
			cout << "\n\n\a                      ==>Game quited.";
			getch();
			if (choice_m == 2)
				game--;
			return;
		}
		else
		{
			cout << "\n                    Invalid move ";
			player--;
			getch();
		}
		i = checkwin();
		player++;
	} while (i == -1);
	board();
	if (i == 1)
	{
		--player;
		if (choice_m == 2)
		{
			if (player == 1)
				score1++;
			else
				score2++;
		}
		cout << "                    ==>\a";
		show_name(player);
		cout << " win !!! ";
	}
	else
	{
		cout << "                    ==>\aGame draw";
		if (choice_m == 2)
		{
			score1++;
			score2++;
		}
	}
	getch();
}
/*********************************************
start a new series
**********************************************/
void new_series()
{
	system("cls");
	int choice_s;
	if (choice_vm != 1)
	{
		score1 = score2 = 0;
		show();
		cout << "\n\n                      How many games you want to play.";
		cin >> games;
		if (games > 50)
		{
			cout << "\n                      Error!@!?!@!";
			getch();
			return;
		}
	}

	do
	{
		show();
		cout << "\n\n      	                 SERIES MENU";
		cout << "\n\n		       1.Start the new game.";
		cout << "\n                       2.Show the score.";
		cout << "\n                       3.Quit and save series.";
		cout << "\n\n                       Enter your choice";
		cin >> choice_s;

		switch (choice_s)
		{
		case 1:
		{
			system("cls");
			new_match();
			game++;
			if (game == games)
			{
				show();
				if (score1 > score2)
					cout << endl
						 << endl
						 << "\a                      ==>" << plr1 << " won the series !!";
				else if (score1 < score2)
					cout << endl
						 << endl
						 << "\a                      ==>" << plr2 << " won the series !!";
				else
					cout << "\n\n\a                      ==>Series Draw !!!";
				getch();
				return;
			}
			break;
		}

		case 2:
		{
			show();
			cout << "\n\n                      Total games - " << games;
			cout << "\n\n                      SCORES";
			cout << "\n\n                      " << plr1 << " - " << score1 << endl;
			cout << "                      " << plr2 << " - " << score2;
			getch();
			break;
		}

		case 3:
		{
			show();
			fstream fout;

			fout.open("player_info.dat", ios::binary | ios::out);
			if (fout)
			{
				char o;
				show();
				cout << "\n\n                      Do you want to overwrite previous series?(Y/N)";
				cin >> o;
				if (o == 'n' || o == 'n')
					break;
			}

			strcpy(pl1.playername, plr1);
			pl1.score = score1;
			strcpy(pl2.playername, plr2);
			pl2.score = score2;
			pl1.game = game;
			pl1.games = games;

			fout.write((char *)&pl1, sizeof(pl1));
			fout.write((char *)&pl2, sizeof(pl1));

			show();
			cout << "\n\n                      Series saved";
			getch();
			fout.close();
			break;
		}

		default:
		{
			cout << "\n                      Wrong choice";
			getch();
		}
		}
	} while (choice_s != 3);
}
/*********************************************
	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
	//*****************************//

	// to check if anybdy won the game...

	int l = 0;
	for (int m = 0; m <= 39; m++)
	{
		if (square[check[m][l]] == square[check[m][l + 1]] && square[check[m][l + 1]] == square[check[m][l + 2]] && square[check[m][l + 2]] == square[check[m][l + 3]] && ((square[check[m][l]] == 'X') || (square[check[m][l]] == 'O')))
		{
			square[check[m][l]] = square[check[m][l + 1]] = square[check[m][l + 2]] = square[check[m][l + 3]] = '';
			return 1;
		}
	}

	//*****************************//

	//*****************************//
	// for draw

	int count1 = 0;
	for (int draw1 = 1; draw1 <= 30; draw1++)
	{
		if (square[draw1] == 'X' || square[draw1] == 'O')
			count1++;
	}

	if (count1 == 30)
		return 0;

	/***********************************************/

	// nobody win till now

	else
		return -1;
}
/**************************************************/
// FUNCTION TO INSERT NAME
/**************************************************/
void input_name()
{
	system("cls");
	show();
	cout << "\n\n                      Enter the first player name.";
	gets(plr1);
	cout << "\n                      Enter the second player name.";
	gets(plr2);
}
/*******************************************************/
// FUNCTION TO SHOW NAME
/*******************************************************/
void show_name(int z)
{
	if (z == 1)
		cout << plr1;
	else
		cout << plr2;
}
/*******************************************************************
//FUNCTION YO SHOW GAME CONNECT FOUR
/*******************************************************************/
void show()
{
	system("cls");
	std::cout << "\n\n\n\n                      GAME CONNECT FOUR";
}
/*******************************************************************
	 FUNCTION TO DRAW BOARD OF SHAGGY's GAME WITH PLAYERS MARK
********************************************************************/

void board()
{
	system("cls");
	cout <<endl<<endl;
	cout <<"\n\n   		        "<< "    GAME CONNECT FOUR   \n\n";
	cout <<"                    "<< plr1<<" (X)";if(choice_m == 2) cout<<" - "<<score1;cout<<"   ::   "<<plr2<<" (O)";if( choice_m == 2) cout<<" - "<<score2; cout<< endl << endl;
	cout <<"\n                    "<< "Press q to quit from the game."<<endl<<endl;
	cout <<"                    "<< "     |     |     |     |     |     " << endl;
	cout <<"                    "<< "  ";cout<<square[25];cout <<"  |  "; cout<< square[26]; cout << "  |  " ; cout<< square[27]; cout <<"  |  "; cout<<square[28];cout<<"  |  "; cout<<square[29];cout<<"  |  "; cout<<square[30];cout<< endl;
	cout <<"                    "<< "_____|_____|_____|_____|_____|_____" << endl;
	cout <<"                    "<< "     |     |     |     |     |     " << endl;
	cout <<"                    "<< "  ";cout<<square[19];cout <<"  |  "; cout<< square[20]; cout << "  |  " ; cout<< square[21]; cout <<"  |  "; cout<<square[22];cout<<"  |  "; cout<<square[23];cout<<"  |  "; cout<<square[24];cout<< endl;
	cout <<"                    "<< "_____|_____|_____|_____|_____|_____" << endl;
	cout <<"                    "<< "     |     |     |     |     |     " << endl;
	cout <<"                    "<< "  ";cout<<square[13];cout <<"  |  ";  cout<< square[14]; cout << "  |  " ; cout<< square[15]; cout <<"  |  "; cout<<square[16];cout<<"  |  "; cout<<square[17];cout<<"  |  "; cout<<square[18];cout<< endl;
	cout <<"                    "<< "_____|_____|_____|_____|_____|_____" << endl;
	cout <<"                    "<< "     |     |     |     |     |     " << endl;
	cout <<"                    "<< "  ";cout<<square[7];cout <<"  |  "; cout<< square[8]; cout << "  |  " ; cout<< square[9]; cout <<"  |  "; cout<<square[10];cout<<"  |  "; cout<<square[11];cout<<"  |  "; cout<<square[12];cout<< endl;
	cout <<"                    "<< "_____|_____|_____|_____|_____|_____" << endl;
	cout <<"                    "<< "     |     |     |     |     |     " << endl;
	cout <<"                    "<< "  " << square[1] <<"  |  " << square[2] << "  |  " << square[3] <<"  |  "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<< endl;
	cout <<"                    "<< "     |     |     |     |     |     " << endl;

}


/*******************************************************************
				END OF CODE
********************************************************************/
