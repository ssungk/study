#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream fsOut;
	fsOut.open("LAB13_03.txt",ios::out);
	if(!fsOut)
	{
		cerr << "Output file open failure\a\n";
		exit(100);
	}
	fsOut << "0123456789abcdefghijABCDEFGHIJ!@#$%^&*()"<< endl;
	fsOut.close();

	ifstream fsIn;
	fsIn.open("LAB13_03.txt",ios::in);
	if(!fsIn)
	{
		cerr << "Input file open failure\a\n";
		exit(100);
	}
	char charAry[10];

	while(fsIn.read((char *)& charAry, 10 * sizeof(char)))
	{
		int numRead;
		numRead = fsIn.gcount() / sizeof(char);
		
		for(int i=0; i<numRead;i++)
			cout << charAry[i];
		cout << endl;
	}
	
	fsIn.close();

	return 0;

}
