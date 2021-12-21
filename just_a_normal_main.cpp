#include <stdio.h>
#include <string>

void this_is_a_normal_function(std::string* &s){
    *s = "hhhhhh";
}

class a_class{

	public:
		std::string *ptr_s;
};

class b_class{

    public:
        a_class a__a;
        b_class(){}

		void funct(){
			this_is_a_normal_function(a__a.ptr_s);
			
		}
};


int main(int argc, char const *argv[])
{
    b_class b;
	b.funct();
    //          "fjdsgjdhjdg"  "FGFGFG" "D GDFGFGGFD " " DFDGD"  ['DSF DF FD FD FF DF ] MAP[DHDFN] 
    return 0;
}
