#include <iostream>
using namespace std;

#include"Dog.h"

Dog::Dog()
{
	cout << "[Dog] ������ ȣ��" << endl;
}

void Dog::talkStaticBinding()
{
	cout << "[Dog] Woof! Woof!" << endl;
}
void Dog::talkDynamicBinding()
{
	cout << "[Dog] Woof! Woof!" << endl;
}