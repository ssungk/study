#include<iostream>
using namespace std;

#include "Fraction.h"


void getData(int& nNumer,int& nDenom);
void getData(int& nNumer);


int main()
{

	cout << "This program creates a fraction " << endl;

	int nNumer =0;
	int nDenom =0;
		
	CFraction fr1;//�⺻ �����ڿ� ���� fr1����

	getData(nNumer, nDenom);
	fr1.store(nNumer, nDenom);

	cout << "fr1 contains: ";
	fr1.print();
	cout << endl;

	getData(nNumer);	
	
	CFraction fr2(nNumer);//���ڸ� �Ű������� �Է� ���� �����ڿ� ���� fr2����	
	
	cout << "fr2 contains: ";
	fr2.print();
	cout << endl;

	getData(nNumer,nDenom);
	CFraction fr3(nNumer, nDenom);//����,�и� �Ű������� �Է� �޴� �����ڿ� ���� fr3����

	cout << "fr3 contains: ";
	fr3.print();
	cout << endl;

	CFraction fr4(fr3);
	//fr3�� �����ϴ� �����ڿ� ���� fr4����

	cout << "fr4 contains: ";	
	fr4.print();
	cout << endl;
	
	cout<< "Thank you for using fraction." << endl;
			
	return 0;
}

void getData( int& nNumer, int& nDenom ) 
{
	cout << "Please enter the numerator : ";
	cin >> nNumer;

	cout << "Please enter the denominator : ";
	cin >> nDenom;

	return;
}

void getData(int& nNumer ) 
{
	cout << "Please enter the numerator : ";
	cin >> nNumer;
	//���⿡  �� ��(����,)�� �Է� �޴� �Լ��� ���� �Ѵ�.
}


