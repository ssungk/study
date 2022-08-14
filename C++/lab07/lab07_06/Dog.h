#include"Animal.h"

class Dog : public Animal
{
private:
public:
	Dog();
	void talkStaticBinding();
	virtual void talkDynamicBinding();
};