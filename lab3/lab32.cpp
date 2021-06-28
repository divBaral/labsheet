#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Prime {
public:
	bool isprime()
	{
		for (int i = 2; i <= n/2; ++i) {
			if ( n % i == 0)
				return false;
		}
		return true;

	}
	void get()
	{
		std::cout << "Enter number:";
		std::cin >> n;
	}
	void push()
	{
		v.push_back(n);
	}
	void print()
	{
		for ( auto x : v)
			std::cout << x << endl;
	}

	
private:
	int n;
	vector<int> v;
};


int main()
{
	Prime p;
	char res;
	do {
		p.get();
		if ( p.isprime() )
			p.push();
		cout << "Another(y/n)?:" ;
		cin >> res;


	} while ( res == 'y' );
	cout << "Primes are:" << endl;
	p.print();

}