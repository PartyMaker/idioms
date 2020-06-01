/*
* Pimpl 
* Main problems :
* dynamic allocation
* non cache friendly
*/

#include "some_class.h"
#include "SomeExternalFile.h"

namespace details {

SomeClass::SomeClass() : m_data{std::make_unique<externalLib::SomeExternalClass>()} // slowly
{

}

int SomeClass::Size() const
{
	return m_data->GetValue();
}

SomeClass::~SomeClass()
{

}
} // namespace details END
