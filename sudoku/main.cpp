#include"input.h"
#include<time.h>
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
	input in;
	in.incheck(argc, argv);
	cout << "Totle Time : " << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
	system("pause");
	return 0;

}

