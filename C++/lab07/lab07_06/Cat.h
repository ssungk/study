#include"Animal.h"

class Cat : public Animal
{
private:
public:
	Cat();
	void talkStaticBinding();
	virtual void talkDynamicBinding();
};