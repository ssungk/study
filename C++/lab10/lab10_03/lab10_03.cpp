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
	// 사전에 단어 입력
	//(1) operator [] 를 이용한 입력 : overwrite 가능
	dictionary["horse"] = "말";
	dictionary["apple"] = "사과";
	//(2) insert 메소드를 이용한 입력 : overwrite 불가
	dictionary.insert(pair<string,string>("grape","포도"));
	dictionary.insert(pair<string,string>("orange","오렌지"));
	// 영어 단어를 이용한 검색
	cout << "검색하고자 하는 영어 단어를 입력하세요 : ";
	cin >> searchWord;
	if(!dictionary[searchWord].empty())
	{
		cout <<"단어를 찾았습니다."<<endl;
		cout << searchWord << " : " << dictionary[searchWord] <<endl;
	}else
	{
		cout <<"검색된 단어가 없습니다."<<endl;
	}
	return 0;
}