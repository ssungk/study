#include <iostream>
using namespace std;
#include"Animal.h"
#include"Dog.h"
#include"Cat.h"

int main()
{
	Animal* animalPtr1;
	Animal* animalPtr2;

	animalPtr1 = new Dog();
	animalPtr2 = new Cat();


	animalPtr1->talkStaticBinding();
	animalPtr1->talkDynamicBinding();
	animalPtr2->talkStaticBinding();
	animalPtr2->talkDynamicBinding();


	return 0;
}