#pragma once
typedef struct Plane
{
	int nose[2];

	int left[2];
	int left_1[2];

	int right[2];
	int right_1[2];

	int down[2];

	void Setleft(int x, int y)
	{
		left[0] = x + 1;
		left[1] = y - 1;
	}

	void Setleft_1(int x, int y)
	{
		left_1[0] = x + 2;
		left_1[1] = y - 2;
	}

	void Setright(int x, int y)
	{
		right[0] = x + 1;
		right[1] = y + 1;
	}

	void Setright_1(int x, int y)
	{
		right_1[0] = x + 2;
		right_1[1] = y + 2;
	}

	void Settail(int x, int y)
	{
		down[0] = x + 1;
		down[1] = y;
	}


	void nose_point(int row, int col)
	{
		nose[0] = row;
		nose[1] = col;

		Setleft(nose[0], nose[1]);
		Setright(nose[0], nose[1]);
		Setleft_1(nose[0], nose[1]);
		Setright_1(nose[0], nose[1]);
		Settail(nose[0], nose[1]);
	}


	bool plane_point(int coord_i, int coord_j)
	{
		bool flag = false;

		if (nose[0] == coord_i and nose[1] == coord_j)
		{
			flag = true;
		}
		else if (left[0] == coord_i and left[1] == coord_j)
		{
			flag = true;
		}
		else if (right[0] == coord_i and right[1] == coord_j)
		{
			flag = true;
		}
		else if (left_1[0] == coord_i and left_1[1] == coord_j)
		{
			flag = true;
		}
		else if (right_1[0] == coord_i and right_1[1] == coord_j)
		{
			flag = true;
		}
		else if (down[0] == coord_i and down[1] == coord_j)
		{
			flag = true;
		}

		return flag;
	}


}plane;

struct Blaster
{
	int x;
	int y;

	void blast_from_ship_nose(int nose_x, int nose_y)
	{
		x = nose_x;
		y = nose_y;
	}

	bool blast_show(int coord_i, int coord_j)
	{

		bool flag = false;
		if (coord_i == x and coord_j == y)
		{
			flag = true;
		}

		return flag;


	}

};

struct Asteroid
{

	Blaster shot;

	Plane ship;

	int cometh_1[2];
	int cometh_2[2];
	int cometh_3[2];

	void Setcometh_two(int x, int y)
	{
		cometh_2[0] = x - 1;
		cometh_2[1] = y - 1;
	}

	void Setcometh_three(int x, int y)
	{
		cometh_3[0] = x - 1;
		cometh_3[1] = y + 1;
	}

	void Setcometh_point(int x, int y)
	{
		cometh_1[0] = x;
		cometh_1[1] = y;

		Setcometh_two(cometh_1[0], cometh_1[1]);
		Setcometh_three(cometh_1[0], cometh_1[1]);
	}


	bool cometh_point(int coord_i, int coord_j)
	{
		bool flag = false;


		if (cometh_2[0] == coord_i and cometh_2[1] == coord_j)
		{
			flag = true;
		}
		else if (cometh_3[0] == coord_i and cometh_3[1] == coord_j)
		{
			flag = true;
		}
		else if (cometh_1[0] == coord_i and cometh_1[1] == coord_j)
		{
			flag = true;
		}

		return flag;
	}


	bool collision_plane(int xy, int yx, int plane_x, int plane_y, ...)
	{


		bool flag = false;

		Setcometh_point(xy, yx);

		ship.nose_point(plane_x, plane_y);

		if (ship.plane_point(cometh_1[0], cometh_1[1]) || ship.plane_point(cometh_2[0], cometh_2[1]) || ship.plane_point(cometh_3[0], cometh_3[1]))
		{
			//PlaySound(TEXT("intimacy.wav"), NULL, SND_ASYNC | SND_LOOP);
			cout << "####\n";
			cout << "####\n";
			cout << "####\n";
			cout << "####\n";
			cout << "####\n";
			cout << "####\n";
			cout << "... The mission failed general\n";
			cout << "They probably didnt get though Saturn circles\n";
			system("pause");
			exit(2);

		}

		return flag;
	}

	bool collision_blast(int xy, int yx, int blast_x, int blast_y, ...)
	{

		bool flag = false;

		Setcometh_point(xy, yx);

		shot.blast_from_ship_nose(blast_x, blast_y);

		if (shot.blast_show(cometh_1[0], cometh_1[1]) || shot.blast_show(cometh_2[0], cometh_2[1]) || shot.blast_show(cometh_3[0], cometh_3[1]))
		{
			flag = true;

		}

		return flag;
	}

};



class Field
{
public:

	plane airplane;

	Asteroid cometh;

	Asteroid cometh_1;

	Asteroid cometh_2;

	Blaster shot;

	int size = 25;

	int writefield(int blast_x, int blast_y, int coord_nose_row, int coord_nose_col, int cometh_nose_row, int cometh_nose_col, int cometh_nose_row_2, int cometh_nose_col_2, ...)
	{
		int flag_of_col_with_cometh = false;//check if blaster hit the cometh


		va_list third_cometh;

		va_start(third_cometh, cometh_nose_col_2);

		int cometh_nose_row_3, cometh_nose_col_3;

		cometh_nose_row_3 = va_arg(third_cometh, int);

		cometh_nose_col_3 = va_arg(third_cometh, int);


		airplane.nose_point(coord_nose_row, coord_nose_col);

		cometh.Setcometh_point(cometh_nose_row, cometh_nose_col);

		cometh_1.Setcometh_point(cometh_nose_row_2, cometh_nose_col_2);

		cometh_2.Setcometh_point(cometh_nose_row_3, cometh_nose_col_3);

		shot.blast_from_ship_nose(blast_x, blast_y);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size * 2; j++)
			{
				if (j == (size * 2) - 1)
				{
					cout << " |";
				}

				if (cometh.cometh_point(i, j))
				{
					cout << "*";
				}
				else if (cometh_1.cometh_point(i, j))
				{
					cout << "*";
				}
				else if (cometh_2.cometh_point(i, j))
				{
					cout << "*";
				}
				else if (airplane.plane_point(i, j))
				{
					cout << "^";
				}
				else if (shot.blast_show(i, j))
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}


				//for plane collison check
				cometh.collision_plane(cometh_nose_row, cometh_nose_col, coord_nose_row, coord_nose_col);

				cometh_1.collision_plane(cometh_nose_row_2, cometh_nose_col_2, coord_nose_row, coord_nose_col);

				cometh_2.collision_plane(cometh_nose_row_3, cometh_nose_col_3, coord_nose_row, coord_nose_col);

				//for blaster collison check

				if (cometh.collision_blast(cometh_nose_row, cometh_nose_col, blast_x, blast_y))
				{
					flag_of_col_with_cometh = 1;
				}

				if (cometh_1.collision_blast(cometh_nose_row_2, cometh_nose_col_2, blast_x, blast_y))
				{
					flag_of_col_with_cometh = 2;
				}

				if (cometh_2.collision_blast(cometh_nose_row_3, cometh_nose_col_3, blast_x, blast_y))
				{
					flag_of_col_with_cometh = 3;
				}

			}

			cout << endl;
		}

		cout << "--------------------------------------------------\n";

		va_end(third_cometh);

		return flag_of_col_with_cometh;
	}

};

void no_cursor(void);