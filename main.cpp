// Problem 955 
// Project Euler
// Jacob Milham

#include <iostream>
#include <vector>
#include <string>
#include <vector>

using namespace std;

bool is_triangle_number(unsigned long);
void add_next_number(vector<unsigned long> *,bool,unsigned long);


int main()
{
	vector<unsigned long> *numbers = new vector<unsigned long>(1,3);
	int triangleCount = 0;
	unsigned long currentNumber = 3;
	unsigned long count = 1;
	while (triangleCount<4) {
		currentNumber = numbers->back();
		cout << currentNumber << "\n";
		if (is_triangle_number(currentNumber)) {
			add_next_number(numbers,true,count);
			triangleCount++;
		} else {
			add_next_number(numbers,false,count);
		}
		count++;
	}
	
	return EXIT_SUCCESS;
}

bool is_triangle_number(unsigned long number) {
	bool found = false;
	for(unsigned long i=0;i<number;i++) {
		if (number == i*(i+1)/2) {
			found = true;
			break;
		}
	}
	return found;
}
void add_next_number(vector<unsigned long> *numbers,bool triangle,unsigned long count) {
	unsigned long current = numbers->back();
	unsigned long last;
	
	if (triangle) {
		numbers->push_back(current + 1);
	} else {
		last = numbers->at(count-2);
		numbers->push_back(2*current - last + 1);
	}
}