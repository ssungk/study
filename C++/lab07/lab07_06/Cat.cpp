#include <iostream>
using namespace std;

#include"Cat.h"

Cat::Cat()
{
	cout << "[Cat] 생성자 호출" << endl;
}

void Cat::talkStaticBinding()
{
	cout << "[Cat] Meow!" << endl;
}
void Cat::talkDynamicBinding()
{
	cout << "[Cat] Meow!" << endl;
}