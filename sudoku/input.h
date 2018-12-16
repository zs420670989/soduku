#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<string>
using namespace std;
class input
{
public:
	void incheck(int argc, char **argv);
private:
	int innum(const string &str);
};
