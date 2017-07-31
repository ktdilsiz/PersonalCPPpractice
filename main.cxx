#include <iostream>

using namespace std;

void changeValue(int &val){

	val = 2*val;
	cout << "inside function with reference" << val << endl;
}

void changeValueNR(int val){

	val = 2*val;
	cout << "inside function without reference" << val << endl;
}


int main(){

	std::cout << "Hello Worlds!" << std::endl;

	int var = 20;
	int *ip;

  int firstvalue = 5, secondvalue = 15;
  int * p1, * p2;

  p1 = &firstvalue;  // p1 = address of firstvalue
  p2 = &secondvalue; // p2 = address of secondvalue
  *p1 = 10;          // value pointed to by p1 = 10
  cout << "p1 is " << p1 << '\n';
  *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
  cout << "p1 is " << p1 << '\n';
  p1 = p2;           // p1 = p2 (value of pointer is copied)
  cout << "p1 is " << p1 << '\n';
  *p1 = 20;          // value pointed to by p1 = 20
  cout << "p1 is " << p1 << '\n';
  
  cout << "firstvalue is " << firstvalue << '\n';
  cout << "secondvalue is " << secondvalue << '\n';

   return 0;

}