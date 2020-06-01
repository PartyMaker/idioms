/*
* Fast Pimpl 
* Main problems :
* not platform dependent
*/

#include "some_class.hpp"
#include "SomeExternalFile.hpp"

namespace details {
SomeClass::SomeClass() : m_data(20)
{

}
SomeClass::SomeClass(SomeClass&& other) = default;
SomeClass::SomeClass(const SomeClass & other) = default;
SomeClass& SomeClass::operator=(SomeClass&& other) = default;
SomeClass::~SomeClass() = default;

int SomeClass::Size() const
{
	return m_data->GetValue();
}

} // namespace details END
