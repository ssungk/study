#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main( void )
{
	string s1, s2;
	//���ڿ� �˻�
	s1 = "01234560123456";
	int index = s1.find("23"); //0��° ��ġ���� �˻��Ͽ� ��23���� substring�� ��ġ�� ã�ƶ�.
	cout<< setw(10) << "find : " << s1 << " -> " << index << " : " << s1[index] << endl;
	
	//���ڿ� ����
	s1 = "0123456";
	s2 = s1.substr(0,3/*�Ķ���� ä���*/);//0��°���� 3���� ���ڸ� �߶� �Ҵ��϶�.
	cout << setw(10) << " substr : " << s1 << " (0~2) -> " << s2 << endl ;
	
	//���ڿ� ����
	s1 = "0123456";
	s2 = s1;
	s1.insert(0,"add");//"add" ���ڿ��� 0��°�� ���� �־��.
	cout << setw(10) << " insert : \"add\" + " << s2 << " = " << s1 << endl ;

	//���ڿ� �߰�
	s1 = "0123456";
	s2 = "abcdef";
	cout << setw(10) << " append : " << s1 << " append " << s2 << " = ";
	s1.append(s2);//s2�� 0~s2.npos ��ġ�� ���ڿ��� s1�� �ǵڿ� �߰��϶�.
	cout << s1 << endl;

	//���ڿ� ��ü
	s1 = "abcdef";
	s2 = "0123456";
	s1.replace(0,1,"5555"); //s1�� 0��° ��ġ���� 1���� ���ڸ� "5555"�� ��ü �϶�.
	cout << setw(10) << "replace : " << s1 << endl;

	//���ڿ� ����
	s1 = "0123456";
	cout << setw(10) << "erase : " << s1 ;
	s1.erase(1,1); //s1�� 1��° ��ġ���� 1���� ���ڸ� �����϶�.
	cout << " -> " << s1 << endl;

	//���ڿ� ��
	int nCmp;
	s1 = "1234567";
	s2 = "1234999";
	nCmp = s1.compare(s2);//s1�� s2�� �� �϶�.
	cout << setw(10) << "compare : " << ( (nCmp==0) ? "equal" : ( (nCmp<0) ? "less" : "greater" ) ) << endl;
	nCmp = s1.compare(0,4,s2,0,4);//s1�� 0~4�� ���ڿ��� s2�� 0~4�� ���� ���� �� �϶�.
	cout << setw(10) << "compare : " << ( (nCmp==0) ? "equal" : ( (nCmp<0) ? "less" : "greater" ) ) << endl;

}