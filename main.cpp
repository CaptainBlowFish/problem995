// Problem 955 
// Project Euler
// Jacob Milham

#include <iostream>
#include <vector>

using namespace std;

bool is_triangle_number(unsigned long,unsigned long &);
void add_next_number(vector<unsigned long> *,bool,unsigned long);

int main()
{
	vector<unsigned long> *numbers = new vector<unsigned long>(1,3);
	int triangleCount = 0;
	unsigned long currentNumber = 3;
	unsigned long count = 1;
	unsigned long last_i_value = 0; //this is to skip some redundant loops in checking for triangle numbers.

	while (triangleCount<70) {
		currentNumber = numbers->back();
		if (is_triangle_number(currentNumber,last_i_value)) {
			add_next_number(numbers,true,count);
			triangleCount++;
			cout << triangleCount << ":" << currentNumber<<"\n";

		} else {
			add_next_number(numbers,false,count);
		}
		count++;
	}
	
	return EXIT_SUCCESS;
}

bool is_triangle_number(unsigned long number,unsigned long &last_i_value) {
	bool found = false;
	unsigned long test_number = 0; 
	for(unsigned long i=last_i_value;test_number <= number;i++) {
		test_number = ((i*i) + i) / 2.0;
		if (number == test_number) {
			last_i_value = i;
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