#include <iostream>
#include "Ch01/intcell.h"
using namespace std;

// test IntCell
void TestIntCell();

int main()
{
	TestIntCell();
	return 0;
}

void TestIntCell()
{
	IntCell intcell;
	intcell.Write(12);
	cout << intcell.Read() << endl;
}

