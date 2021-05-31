#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<conio.h>
#include<iso646.h>
#include<ctime>
#include<Windows.h>
#include<stdarg.h>



using namespace std;

#include "Header.h"

int main()
{
	srand(time(0));

	no_cursor();

	Field field;

	Asteroid cometh;

	int row = 12;
	int col = 25;

	int indicator = 0;// thats for renewing second commeth

	int cometh_x = 2;
	int cometh_y = rand() % field.size*2;

	int cometh_x_2 = -2;
	int cometh_y_2 = -2;

	int cometh_x_3 = -2;
	int cometh_y_3 = -2;

	char direction = 0;

	int cometh_avoided = 0;

	int blast_x=-10, blast_y=-10;
	bool blast = false;

	bool init_of_cometh_2 = false;
	bool init_of_cometh_3 = false;

	int comeths_destroyed = 0;

	cout << "Sergant!.\n";
	cout << "You were apointed to be a pilot on a very import comsic mission\n";
	cout << "You must reach Zion 646, without damaging your ship\n";
	cout << "Good luck!\n";
	cout << "\n\n\t\t\tPress enter to start the game\n\n";

	_getch();
	
	

	//PlaySound(TEXT("mountains.wav"), NULL, SND_LOOP | SND_ASYNC);

	while (true)
	{

		system("CLS");

		if (_kbhit())
		{
			direction = _getch();
			if(direction == 'x')
			{

				blast = true;
				blast_x = row - 1;
				blast_y = col;

					//break;
			}
		}
			switch (direction)
			{
			case 'a':
			{
				col--;
				break;
			}
			case 'd':
			{
				col++;
				break;
			}
			case 'w':
			{
				row--;
				break;
			}
			case 's':
			{
				row++;
				break;
			}
			}
		

			if (blast == true)
			{
				blast_x--;
			}
			
			if (blast_x == field.size)
			{
				blast = false;
				blast_x = -256;
				blast_y = -256;
			}

			if (indicator == 0)
			{
				int destroyed_cometh_index = field.writefield(blast_x, blast_y, row, col, cometh_x++, cometh_y, -2, -3);
				
				if (destroyed_cometh_index == 1 and blast == true)
				{
					cometh_x = 20;
					cometh_y = -10;

					blast_x = -1;
					blast_y = -1;
					blast = false;
					comeths_destroyed++;
				}

			}
			else if (indicator == 1)
			{
				int destroyed_cometh_index = field.writefield(blast_x, blast_y, row, col, cometh_x++, cometh_y, cometh_x_2+=2, cometh_y_2);
				
				if (destroyed_cometh_index == 1 and blast == true)
				{
					cometh_x = 15;
					cometh_y = -10;

					blast_x = -1;
					blast_y = -1;
					blast = false;
					comeths_destroyed++;
				}
				else if (destroyed_cometh_index == 2 and blast == true)
				{
					cometh_x_2 = 20;
					cometh_y_2 = -20;

					blast_x = -1;
					blast_y = -1;
					blast = false;
					comeths_destroyed++;
				}

			}
			else if (indicator == 2)
			{
				int destroyed_cometh_index = field.writefield(blast_x, blast_y,row, col, cometh_x++, cometh_y, cometh_x_2+=2, cometh_y_2, cometh_x_3+=3, cometh_y_3);
				
				if (destroyed_cometh_index == 1 and blast == true)
				{
					cometh_x = 15;
					cometh_y = -10;

					blast_x = -1;
					blast_y = -1;
					blast = false;
					comeths_destroyed++;
				}
				else if (destroyed_cometh_index == 2 and blast == true)
				{
					cometh_x_2 = 20;
					cometh_y_2 = -20;

					blast_x = -1;
					blast_y = -1;
					blast = false;
					comeths_destroyed++;
				}
				else if (destroyed_cometh_index == 3 and blast == true)
				{
					cometh_x_3 = 15;
					cometh_y_3 = -30;

					blast_x = -1;
					blast_y = -1;
					blast = false;
					comeths_destroyed++;
				}

			}

			

			if (cometh_x == field.size)
			{
			
				cometh_x = 1;
				cometh_y = rand() % field.size * 2;

				

				if (cometh_avoided == 10)
				{
					//cometh_x_2 = 2;
					//cometh_y_2 = rand() % field.size * 2;
					//while(cometh_y_2 == cometh_y) //|| cometh_y_2 == cometh_y-1 || cometh_y_2 == cometh_y + 1)
					//{
					//	cometh_y_2 = rand() % field.size * 2;
					//}
					indicator++;
				}
				else if (cometh_avoided == 20)
				{
					//cometh_x_3 = 2;
					//cometh_y_3 = rand() % field.size * 2;

					//while (cometh_y_3 == cometh_y) //|| cometh_y_2 == cometh_y-1 || cometh_y_2 == cometh_y + 1)
					//{
					//	cometh_y_3 = rand() % field.size * 2;
					//}
					indicator++;

				}

				if (indicator == 0)
				{
					cometh_avoided++;
				}
				else if (indicator == 1 and init_of_cometh_2 == false)
				{
					cometh_x_2 = 1;
					cometh_y_2 = rand() % field.size * 2;
					while (cometh_y_2 == cometh_y) //|| cometh_y_2 == cometh_y-1 || cometh_y_2 == cometh_y + 1)
					{
						cometh_y_2 = rand() % field.size * 2;
					}
					cometh_avoided++;
					init_of_cometh_2 = true;
				}
				else if (indicator == 2 and init_of_cometh_3==false)
				{
					cometh_x_3 = 1;
					cometh_y_3 = rand() % field.size * 2;
					while (cometh_y_3 == cometh_y || cometh_y_3 == cometh_y_2) //|| cometh_y_2 == cometh_y-1 || cometh_y_2 == cometh_y + 1)
					{
						cometh_y_3 = rand() % field.size * 2;
					}
					cometh_avoided++;
					init_of_cometh_3 = true;
				}
			}

			if (cometh_x_2 == field.size)
			{
				cometh_x_2 = 1;
				cometh_y_2 = rand() % field.size * 2;
				while (cometh_y_2 == cometh_y) //|| cometh_y_2 == cometh_y-1 || cometh_y_2 == cometh_y + 1)
				{
					cometh_y_2 = rand() % field.size * 2;
				}
				cometh_avoided++;
			}
				
			if (cometh_x_3 == field.size)
			{
				cometh_x_3 = 1;
				cometh_y_3 = rand() % field.size * 2;
				while (cometh_y_3 == cometh_y || cometh_y_3 == cometh_y_2) //|| cometh_y_2 == cometh_y-1 || cometh_y_2 == cometh_y + 1)
				{
					cometh_y_3 = rand() % field.size * 2;
				}
				cometh_avoided++;
			}
		
		cout << "Comeths avoided  "<< cometh_avoided << endl;
		cout << "Destroyed comeths -> " << comeths_destroyed << endl;
		/*cout << "Speed -> "<< 50 - row*1/2<<" warps/years" << endl;
		cout << "Distortion of space -> " << col * 2 << endl;*/
		
	}



	return EXIT_SUCCESS;
}