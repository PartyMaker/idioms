#include <iostream>

class Base
{
public:
	friend std::ostream& operator<<(std::ostream& o, const Base& b);
protected:
	virtual void SomeFunction() const { }
};

class Derived: public Base
{
protected:
	virtual void SomeFunction() const override { }
};

std::ostream& operator<<(std::ostream& os, const Base& baseClass)
{
	baseClass.SomeFunction(); // delegate the work to a polymorphic member function.
	return os;
}

int main()
{
  Base* exampleBase = new Derived();
  std::cout << exampleBase << std::endl;
  delete exampleBase;
  return 0;
}
