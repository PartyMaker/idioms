#pragma once
#include <memory>
#include "fast_pimpl.h"

/* forward declaration */
namespace externalLib
{
	class SomeExternalClass;
}

namespace details {

class SomeClass 
{
	using LibClass = externalLib::SomeExternalClass;

public:
	SomeClass();
	SomeClass(SomeClass&& other);
	SomeClass(const SomeClass& other);
	SomeClass& operator=(SomeClass&& other);
	~SomeClass();

	int Size() const; 

	static constexpr size_t nImplSize = 4;
	static constexpr size_t nImplAlign = 4;

	utils::FastPimpl<LibClass, nImplSize, nImplAlign> m_data;
};
} // namespace details END
