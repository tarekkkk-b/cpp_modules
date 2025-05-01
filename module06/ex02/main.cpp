#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	time_t rn;
	srand(time(&rn));

	int random;
	random = rand() % 3;
	switch (random)
	{
		case(0):
			return new A;
		case (1):
			return new B;
		case (2):
			return new C;
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer to A object\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer to B object\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer to C object\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "reference to A object\n";
	}
	catch(std::bad_cast)
	{
		;
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "reference to B object\n";
	}
	catch(std::bad_cast)
	{
		;
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "reference to C object\n";
	}
	catch(std::bad_cast)
	{
		;
	}
	
}

int main()
{
	Base *object = generate();

	identify(object);
	identify(*object);


	delete object;
}