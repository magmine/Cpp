#include <iostream>
#include <vector>
#include <bitset>
#define sz 6

/*
 * - In this example I can chech when a vector gets destructed since I know that it will be called directly after the ~my_vector destructor.
 * - In this exmple, trying to move a bitset from one position to another give unexpected non correct results since on of those bits gets destructed even if we try to keep a reference to it to add it later.
 * */

template <typename T>
struct my_vector : std::vector<T> {
	using std::vector<T>::vector;
	virtual ~my_vector() { std::cout << "vector destructor called!\n"; }
};

template <uint32_t T=sz>
struct my_bitset : std::bitset<T> {
	    my_bitset(const char *str, int ind) : std::bitset<T>(str) {index = ind;}
	        virtual ~my_bitset() { std::cout << "bitset destructor called! original index: " <<index<<" \n"; }
		    int index = 99;
};

int main ()
{
	my_vector<my_bitset<sz> > myvector;

	myvector.push_back(std::move(my_bitset<sz>("010101", 0)));
	myvector.push_back(std::move(my_bitset<sz>("101010", 1)));
	myvector.push_back(std::move(my_bitset<sz>("000000", 2)));
	
	my_bitset<sz> &bits = myvector[1];
	myvector.erase (myvector.begin() + 1);
	myvector.insert(myvector.begin() + 1, std::move(bits));

	return 0;
}

