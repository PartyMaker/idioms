#pragma once
#include <memory>

/* forward declaration */
namespace externalLib
{
	class SomeExternalClass;
}

namespace details {

class SomeClass 
{
	using libClass = externalLib::SomeExternalClass;

public:
	SomeClass();
	SomeClass(SomeClass&& other) = default;
	SomeClass& operator=(SomeClass&& other) = default;
	~SomeClass();

	int Size() const; 

private:
	std::unique_ptr<libClass> m_data;
};
} // namespace details END
