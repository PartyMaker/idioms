#pragma once

namespace externalLib
{
	class SomeExternalClass
	{
	public:
		SomeExternalClass() = default;
		SomeExternalClass(SomeExternalClass&& other) = default;
		SomeExternalClass& operator=(SomeExternalClass&& other) = default;
		~SomeExternalClass() = default;

		int GetValue() const { return m_nValue; }

	private:
		int m_nValue = 0;
	};
}
