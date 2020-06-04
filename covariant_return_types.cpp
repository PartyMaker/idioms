class Base 
{
  public:
    virtual Base * clone() const 
    {
      return new Base(*this); 
    }
};
class Derived : public Base 
{
  public:
    virtual Base * clone() const override
    {
      return new Derived(*this); 
    }
};

int main()
{
  Derived *d1 = new Derived();
  Base * b = d1->clone();
  Derived *d2 = dynamic_cast<Derived *>(b);
  if(d2) 
  {
   // Use d2 here.
  }
  return 0;
}
