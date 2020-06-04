/*
* The idiom depends on the following C++ rule:
* the constructor (and destructor) of a virtually 
* inherited class is called directly by the 
* derived-most class. If access to the constructor 
* or destructor of such a virtually inherited class 
* is prevented, the class can not be subclassed further.
*/

class MakeFinal
{
  ~MakeFinal() {}  // private by default.
  friend class Sealed;
};

class Sealed : virtual MakeFinal
{ };

class Test : public Sealed
{ };

int main()
{
  Sealed ex; // ok
  Test t; // Compilation error here.
  return 0;
}
