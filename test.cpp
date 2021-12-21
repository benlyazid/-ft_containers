#include <iostream>
#include <memory>
#include <stdio.h>

struct A{

	A() {
		k = new long();
		std::cout << &k << std::endl;
		std::cout << k << std::endl;
	}

	int  h;
	long *k;
	long getAddr()
	{
		long adr = (long) &k;
		return adr;
	}

	long *addr()
	{
		return k;
	}


	void *set(long h)
	{
		*k = h;
	}
};


class F{size_t a;std::allocator<char> g; char *u;};

int main()
{
	A j;


	long a = (long)&j + 8;
	long **u = (long **)a;

/*
	printf("%x\n", j.addr());
	j.set(23);
	printf("done\n");
	*u = (long *)0x7ffee7e16f08;
	printf("%x\n", j.addr());
	j.set(23);*/


	std::cout << sizeof(F) << std::endl;


}
