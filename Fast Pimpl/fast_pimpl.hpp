#pragma once
#include <cstddef>
#include <utility>
#include <type_traits>

namespace utils
{
template<typename T, size_t Size, size_t Alignment>
class FastPimpl
{
public:
	template<typename... Args>
	explicit FastPimpl(Args&&... args)
	{
		new (Ptr()) T(std::forward<Args>(args)...);
	}
	explicit FastPimpl(const FastPimpl<T, Size, Alignment>& rhs)
	{
		new (Ptr()) T(*rhs);
	}
	explicit FastPimpl(FastPimpl<T, Size, Alignment>&& rhs)
	{
		new (Ptr()) T(std::move(*rhs));
	}
	~FastPimpl() noexcept
	{
		validate<sizeof(T), alignof(T)>();
		Ptr()->~T();
	}
	FastPimpl& operator=(FastPimpl&& rhs)
	{
		*Ptr() = std::move(*rhs);
		return *this;
	}

	const T* Ptr() const noexcept 
	{ 
		return reinterpret_cast<const T*>(&m_data); 
	}
	T* Ptr() noexcept 
	{ 
		return reinterpret_cast<T*>(&m_data); 
	}
	T* operator->() noexcept 
	{
		return Ptr(); 
	}
	const T* operator->() const noexcept {
		return Ptr(); 
	}
	T& operator*() noexcept
	{ 
		return  *Ptr(); 
	}
	const T& operator*() const noexcept 
	{ 
		return *Ptr(); 
	}

private:
	template<size_t ActualSize, size_t ActualAlignment>
	static void validate() noexcept
	{
		static_assert(Size == ActualSize, "Size and sizeof(T) mismatch");
		static_assert(Alignment == ActualAlignment, "Alignment and alignof(T) mismatch");
	}

private:
	typename std::aligned_storage<Size, Alignment>::type m_data;
};

} // namespace utils END
