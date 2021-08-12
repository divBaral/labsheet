// Modify the stack class given in the previous lab to add the exception when a user tries to add an item while the stack is full and when the user tries to add the item while the stack is empty. Throw exceptions in both of the cases and handle these exceptions.

#include <iostream>

using namespace std;

class Full{};
class Empty{};

template <class T>

class Stack

{

private:
	static const int maxsize = 3;
    T st[maxsize];

    int top;

public:
	
	Stack();

    void push(T var);

    T pop();

};

template <class T>

Stack<T>::Stack()
{

    top=-1;

}

template <class T>

void Stack<T>::push(T var)
{
	if ( ++top == maxsize)
		throw Full();
	else
    	st[top]=var;

}

template <class T>

T Stack<T>::pop()
{

	if ( top < 0)
		throw Empty();
	else
    	return st[top--];

}

int main()

try{

    Stack<float> s1;

    s1.push(111.1F);

    s1.push(222.2F);

    s1.push(333.3F);

    cout<<"1 : "<<s1.pop()<<endl;

    cout<<"2 : "<<s1.pop()<<endl;

    cout<<"3 : "<<s1.pop()<<endl;
   

    Stack<long> s2;

    s2.push(123123123L);

    s2.push(234234234L);

    s2.push(345345345L);

    cout<<"1 : "<<s2.pop()<<endl;

    cout<<"2 : "<<s2.pop()<<endl;

    cout<<"3 : "<<s2.pop()<<endl;
    cout <<"4: " << s1.pop();

    return 0;

}

catch ( Full )
{
	std::cout <<"Stack is full\n";
}

catch( Empty)
{
	std::cout << "Stack is empty\n";
}
catch(...)
{
	cout << "Other error occured\n";
}