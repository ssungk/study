#include <iostream>
using namespace std;

#include"Dog.h"

Dog::Dog()
{
	cout << "[Dog] 생성자 호출" << endl;
}

void Dog::talkStaticBinding()
{
	cout << "[Dog] Woof! Woof!" << endl;
}
void Dog::talkDynamicBinding()
{
	cout << "[Dog] Woof! Woof!" << endl;
}