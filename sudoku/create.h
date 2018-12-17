#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<string>
using namespace std;
char result[200000000];
int index = 0;
int countnum = 0;
int shudu[9][9];
int record[9][9];
void colexchange(int c1, int c2)
{
	for (int i = 0; i < 9; i++)
	{
		int colex = record[i][c1];
		record[i][c1] = record[i][c2];
		record[i][c2] = colex;
	}
}
void rowexchange(int r1, int r2)
{
	for (int i = 0; i < 9; i++)
	{
		int rowex = record[r1][i];
		record[r1][i] = record[r2][i];
		record[r2][i] = rowex;
	}
}
void save()
{
	countnum++;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			result[index++] = record[i][j] + '0';
			if (j != 8)
				result[index++] = ' ';
			else
				result[index++] = '\n';
		}

	}
	result[index++] = '\n';

}
void exchange(int x1, int x2, int x3, int y1, int y2, int y3)
{
	memcpy(record, shudu, sizeof(shudu));
	if (x1 == 1) colexchange(1, 2);
	switch (x2)
	{
	case 1:
		colexchange(4, 5);
		break;
	case 2:
		colexchange(3, 4);
		break;
	case 3:
		colexchange(3, 4);
		colexchange(4, 5);
		break;
	case 4:
		colexchange(3, 5);
		colexchange(4, 5);
		break;
	case 5:
		colexchange(3, 5);
		break;
	}
	switch (x3)
	{
	case 1:
		colexchange(7, 8);
		break;
	case 2:
		colexchange(6, 7);
		break;
	case 3:
		colexchange(6, 7);
		colexchange(7, 8);
		break;
	case 4:
		colexchange(6, 8);
		colexchange(7, 8);
		break;
	case 5:
		colexchange(6, 8);
		break;
	}
	if (y1 == 1) rowexchange(1, 2);
	switch (y2)
	{
	case 1:
		rowexchange(4, 5);
		break;
	case 2:
		rowexchange(3, 4);
		break;
	case 3:
		rowexchange(3, 4);
		rowexchange(4, 5);
		break;
	case 4:
		rowexchange(3, 5);
		rowexchange(4, 5);
		break;
	case 5:
		rowexchange(3, 5);
		break;
	}
	switch (y3)
	{
	case 1:
		rowexchange(7, 8);
		break;
	case 2:
		rowexchange(6, 7);
		break;
	case 3:
		rowexchange(6, 7);
		rowexchange(7, 8);
		break;
	case 4:
		rowexchange(6, 8);
		rowexchange(7, 8);
		break;
	case 5:
		rowexchange(6, 8);
		break;
	}
	save();
}
void create(int n)
{
	int a[9] = { 1,2,9,4,5,6,7,8,3 };
	while (1)
	{
		shudu[0][0] = shudu[1][6] = shudu[2][3] = shudu[3][2] = shudu[4][8] = shudu[5][5] = shudu[6][1] = shudu[7][7] = shudu[8][4] = 3;
		shudu[0][1] = shudu[1][7] = shudu[2][4] = shudu[3][0] = shudu[4][6] = shudu[5][3] = shudu[6][2] = shudu[7][8] = shudu[8][5] = a[1];
		shudu[0][2] = shudu[1][8] = shudu[2][5] = shudu[3][1] = shudu[4][7] = shudu[5][4] = shudu[6][0] = shudu[7][6] = shudu[8][3] = a[0];
		shudu[0][3] = shudu[1][0] = shudu[2][6] = shudu[3][5] = shudu[4][2] = shudu[5][8] = shudu[6][4] = shudu[7][1] = shudu[8][7] = a[5];
		shudu[0][4] = shudu[1][1] = shudu[2][7] = shudu[3][3] = shudu[4][0] = shudu[5][6] = shudu[6][5] = shudu[7][2] = shudu[8][8] = a[4];
		shudu[0][5] = shudu[1][2] = shudu[2][8] = shudu[3][4] = shudu[4][1] = shudu[5][7] = shudu[6][3] = shudu[7][0] = shudu[8][6] = a[3];
		shudu[0][6] = shudu[1][3] = shudu[2][0] = shudu[3][8] = shudu[4][5] = shudu[5][2] = shudu[6][7] = shudu[7][4] = shudu[8][1] = a[2];
		shudu[0][7] = shudu[1][4] = shudu[2][1] = shudu[3][6] = shudu[4][3] = shudu[5][0] = shudu[6][8] = shudu[7][5] = shudu[8][2] = a[7];
		shudu[0][8] = shudu[1][5] = shudu[2][2] = shudu[3][7] = shudu[4][4] = shudu[5][1] = shudu[6][6] = shudu[7][3] = shudu[8][0] = a[6];
		memcpy(record, shudu, sizeof(shudu));
		for (int i1 = 0; i1 < 2; i1++)
			for (int i2 = 0; i2 < 6; i2++)
				for (int i3 = 0; i3 < 6; i3++)
					for (int j1 = 0; j1 < 2; j1++)
						for (int j2 = 0; j2 < 6; j2++)
							for (int j3 = 0; j3 < 6; j3++)
							{
								exchange(i1, i2, i3, j1, j2, j3);
								if (countnum == n)
								{
									FILE* out;
									fopen_s(&out, "sudoku.txt", "wt");
									fputs(result, out);
									fclose(out);
									return;
								}
							}
		next_permutation(a, a + 8);
	}

}


