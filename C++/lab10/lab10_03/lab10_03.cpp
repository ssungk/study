#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <map>
using namespace std;

int main ()
{
	map<string, string> dictionary;
	string searchWord;
	// ������ �ܾ� �Է�
	//(1) operator [] �� �̿��� �Է� : overwrite ����
	dictionary["horse"] = "��";
	dictionary["apple"] = "���";
	//(2) insert �޼ҵ带 �̿��� �Է� : overwrite �Ұ�
	dictionary.insert(pair<string,string>("grape","����"));
	dictionary.insert(pair<string,string>("orange","������"));
	// ���� �ܾ �̿��� �˻�
	cout << "�˻��ϰ��� �ϴ� ���� �ܾ �Է��ϼ��� : ";
	cin >> searchWord;
	if(!dictionary[searchWord].empty())
	{
		cout <<"�ܾ ã�ҽ��ϴ�."<<endl;
		cout << searchWord << " : " << dictionary[searchWord] <<endl;
	}else
	{
		cout <<"�˻��� �ܾ �����ϴ�."<<endl;
	}
	return 0;
}