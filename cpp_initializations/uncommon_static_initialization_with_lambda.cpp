#include<iostream>

/*
 * In this example I show how we can use lambda functions to initialize a non trivial static const 
 * member. It is un uncommon situation but it might arrive at any time.
 * NB: this is only valable if, the object we are initializing has a copy/move constructor.
 * */

class Object {
	public:
		void initialize() {
			i = 99;
		}
		int print_i() const {return i;}
	private:
		int i = 0;
};

class A {
	public:
		const static Object obj;
};

const Object A::obj { []() { Object temp; temp.initialize (); return temp; } () };

int main() {

	std::cout<<A::obj.print_i()<<"\n";
	return 0;
}
