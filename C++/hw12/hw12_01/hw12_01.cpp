#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
using namespace std;

int main()
{
	srand(time(NULL));

	int randNum1,randNum2;
	list<int> lt1,lt2;
	list<int>::iterator iter1, iter2;

	for(int i=0;i<25;i++)
	{
		randNum1=(rand()%100);
		for(iter1=lt1.begin();iter1 != lt1.end();iter1++)
		{
			if(*iter1 == randNum1)
			{
				randNum1=(rand()%100);
				iter1=lt1.begin();
			}			
		}	
		lt1.push_back(randNum1);
		
		randNum2=(rand()%100);
		for(iter2=lt2.begin();iter2 != lt2.end();iter2++)
		{
			if(*iter2 == randNum2)
			{
				randNum2=(rand()%100);
				iter2=lt2.begin();
			}			
		}	
		lt2.push_back(randNum2);
	}

	lt1.sort();//lt1정렬
	lt2.sort();//lt2정렬

	
	
	fstream fs1;
	fs1.open("HW12_01.dat",ios::in|ios::out|ios::trunc|ios::binary);
	if(!fs1)
	{
		cerr << "Output file open failure\a\n";
		exit(100);
	}
	cout << "Sorted values in file HW12_01.dat" << endl;

	for(iter1=lt1.begin();iter1 != lt1.end();iter1++)
	{
		cout << *iter1 << " " ;
		fs1.write((char*)&*iter1, sizeof(int));
	}
	cout << endl << endl;

	fstream fs2;
	fs2.open("HW12_02.dat",ios::in|ios::out|ios::trunc|ios::binary);
	if(!fs2)
	{
		cerr << "Output file open failure\a\n";
		exit(100);
	}
	cout << "Sorted values in file HW12_02.dat" << endl;

	for(iter2=lt2.begin();iter2 != lt2.end();iter2++)
	{
		cout << *iter2 << " " ;
		fs2.write((char*)&*iter2, sizeof(int));
	}
	cout << endl << endl;
	
	fstream fs3;
	fs3.open("HW12_03.dat",ios::in|ios::out|ios::trunc|ios::binary);
	if(!fs3)
	{
		cerr << "Output file open failure\a\n";
		exit(100);
	}
	
	
	int fs1Data, fs2Data;
	
	fs1.seekg(ios::beg);
	fs2.seekg(ios::beg);

	fs1.read((char*)&fs1Data, sizeof(int));
	fs2.read((char*)&fs2Data, sizeof(int));

	while(!fs1.eof() || !fs2.eof())
	{
		if(fs1Data <= fs2Data)
		{
			fs3.write((char*)&fs1Data, sizeof(int));//
			fs1.read((char*)&fs1Data, sizeof(int));//
			if(fs1.eof()) fs1Data = 100;
		}
		else
		{
			fs3.write((char*)&fs2Data, sizeof(int));////
			fs2.read((char*)&fs2Data, sizeof(int));//
			if(fs2.eof()) fs2Data = 100;
		}
	}
	
	
	cout << "Values in file HW12_03.dat(merged)" << endl;
	
	fs3.seekg(ios::beg);//
	int data;
	while(fs3.read((char*)&data, sizeof(int)))
	{
		cout << setw(4) << data;
	}
	cout << endl;

	fs1.close();
	fs2.close();
	fs3.close();
	
	return 0;
}
