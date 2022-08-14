#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream fsOut;
	fsOut.open("LAB13_01.dat",ios::out|ios::binary);
	if(!fsOut)
	{
		cerr << "Output file open failure\a\n";
		exit(100);
	}
	for(int data=1;data<=30;data++)
		fsOut.write((char*)&data, sizeof(int));
	fsOut.close();

	ifstream fsIn("LAB13_01.dat",ios::in|ios::binary);
	if(!fsIn)
	{
		cerr << "Input file open failure\a\n";
		exit(100);
	}


	int tempInt[1];
	cout << "데이터를 항목 하나씩 읽은 경우: " << endl;
	while(fsIn.read((char *)& tempInt, 1 * sizeof(int)))
	{
		cout << tempInt[0] << endl;
	}
	cout << endl;
	fsIn.close();

	return 0;

}








/*
int main()
{
	int aInt = 768;
	char aChar = 'A';
	
	ofstream fsTextOut("data.txt");
	fsTextOut << aInt << aChar;
	fsTextOut.close();

	ofstream fsBinOut("data.bin",ios::out|ios::binary);
	fsBinOut.write((char*)&aInt, sizeof(int));
	fsBinOut.write(&aChar, sizeof(char));
	fsBinOut.close();

	return 0;

}
*/
