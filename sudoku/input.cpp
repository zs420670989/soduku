#include "input.h"
#include"create.h"
#include"solve.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<string>
void input::incheck(int argc, char **argv)
{
	if (argc == 3)
	{
		string strorder = argv[1];
		if (strorder == "-c")
		{
			int num = innum(argv[2]);
			if (num <= 0 || num > 1000000)
			{
				cout << "输入不符合要求，1<=数量<=1000000" << endl;
				return;
			}
			else
			{
				create(num);
			}
		}
		else
			if (strorder == "-s")
			{
				soluation(argv[2]);
			}
			else
			{
				cout << "指令无效，-c 生成数独，-s 解决数独" << endl;
				return;
			}
	}
	else
	{
		cout << "无效的输入" << endl;
		return;
	}
}
int input::innum(const string &str)
{
	size_t size_str = str.size();
	if (size_str > 7)
		return 0;
	for (size_t i = 0; i < size_str; i++)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			continue;
		else
			return 0;
	}
	return stoi(str);
}