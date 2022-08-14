#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string file1,file2;

	cout << "This program appends two files." << endl;
	cout << "Please enter file name of primary file : ";
	cin >> file1;
	
	ofstream fsAp;
	fsAp.open(file1,ios::out|ios::app|ios::binary);
	if(!fsAp)
	{
		cerr << "Can't open" << file1 << endl;
		exit(100);
	}

	fsAp.seekp(ios::end);

	cout << "Please enter file name of the second file: ";
	cin >> file2;

	ifstream fsIn;
	fsIn.open(file2,ios::in|ios::binary);
	if(!fsIn)
	{
		cerr << "Can't open" << file2 << endl;
		exit(100);
	}

	long apndCnt = 0;
	char inChar[1];
	while(fsIn.read((char *)& inChar, sizeof(char)))
	{
		fsAp.write(inChar,1);
		apndCnt++;
	}
	fsAp.close();
	fsIn.close();

	cout << "Append complete: " << apndCnt << "appended to file "<< endl;
	return 0;
	
}