#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ofstream fsOut;
	fsOut.open("LAB13_02.dat",ios::out|ios::binary);
	if(!fsOut)
	{
		cerr << "Output file open failure\a\n";
		exit(100);
	}
	for(int data=1;data<=30;data++)
		fsOut.write((char*)&data, sizeof(int));
	fsOut.close();

	ifstream fs("LAB13_02.dat",ios::in|ios::binary);
	if(!fs)
	{
		cerr << "Input file open failure\a\n";
		exit(100);
	}
	int intAry[10];
	cout << "데이터를 한번에 버퍼 크기만큼 읽은 경우: " << endl;
	while(fs.read((char *)& intAry, 10 * sizeof(int)))
	{
		int numRead;
		numRead = fs.gcount() / sizeof(int);
		
		for(int i=0; i<numRead;i++)
			cout << intAry[i] << " ";
		cout << endl;
	}
	
	fs.close();

	return 0;

}
