/*
Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.
*/
#include <iostream>
#include <cstdlib>
#include <cstring>

class myString {
public:
	myString(const char *p_s = " " )
	{  
		size = strlen(p_s);
		val = new char[size+1];
		strcpy(val, p_s);
	}
	~myString()
	{
			delete[] val;
	}
	void join( const myString& s1, const myString& s2)
	{
		size = strlen(s1.val) + strlen(s2.val);
		if( !(realloc(val, (size+1) * sizeof(char))) )
			perror("Reallocation of memory failed.");
		strcpy(val, s1.val);
		strcat(val, s2.val);
	
	}
	void print()
	{
		for (int i = 0; i < size; ++i)
			std::cout << val[i];
	}
	
private:
	char *val;
	int size;
	


};

int main()
{
	myString s1("Engineers are");
	myString s2(" creatures of logic");
	myString s3;
	s3.join(s1, s2);
	s3.print();

	

}
