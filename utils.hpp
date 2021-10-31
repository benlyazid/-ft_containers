#ifndef __UTILS__
#define __UTILS__
#include "Vector.hpp"

namespace ft
{

	template<class T, class U=void>
	struct is_integral
	{
		static const bool value = false;
	};

	template<class T>
	struct is_integral<int, T>
	{
		static const bool value = true;
	};
	
	template<class T>
	struct is_integral< long long, T>
	{
		static const bool value = true;
	};
	
	template<class T>
	struct is_integral<short, T>
	{
		static const bool value = true;
	};
	
	
	template<class T>
	struct is_integral<long, T>
	{
		static const bool value = true;
	};
	
	template<class T>
	struct is_integral<char, T>
	{
		static const bool value = true;
	};
	
	/*
	############################################################
	*/
	template<class T, class U=void>
	struct is_iterator
	{
		static const bool value = false;
	};

	template<class T>
	struct is_iterator<Iterator<std::random_access_iterator_tag, T>, T>
	{
		static const bool value = true;
	};

};
#endif
