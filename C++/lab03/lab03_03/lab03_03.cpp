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
		
	CFraction fr1;//기본 생성자에 의한 fr1선언

	getData(nNumer, nDenom);
	fr1.store(nNumer, nDenom);

	cout << "fr1 contains: ";
	fr1.print();
	cout << endl;

	getData(nNumer);	
	
	CFraction fr2(nNumer);//분자를 매개변수로 입력 받은 생성자에 의한 fr2선언	
	
	cout << "fr2 contains: ";
	fr2.print();
	cout << endl;

	getData(nNumer,nDenom);
	CFraction fr3(nNumer, nDenom);//분자,분모를 매개변수로 입력 받는 생성자에 의한 fr3선언

	cout << "fr3 contains: ";
	fr3.print();
	cout << endl;

	CFraction fr4(fr3);
	//fr3를 복사하는 생성자에 의한 fr4선언

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
	//여기에  한 수(분자,)를 입력 받는 함수를 구현 한다.
}


