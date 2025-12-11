// Problem 955 
// Project Euler
// Jacob Milham

#include <iostream>

using namespace std;

bool is_triangle_number(unsigned long,unsigned long &);
void get_next_number(unsigned long &, unsigned long &, bool);

int main()
{
	int triangleCount = 0;
	unsigned long currentNumber = 3;
	unsigned long lastNumber = 1; // fun fact 1 is the first triangle number
	unsigned long count = 0;
	unsigned long last_i_value = 0; //this is to skip some redundant loops in checking for triangle numbers.

	while (triangleCount<70) {
		
		if (is_triangle_number(currentNumber,last_i_value)) {
			get_next_number(currentNumber,lastNumber,true);
			triangleCount++;
			cout << triangleCount << ":" << currentNumber<<"\n";

		} else {
			get_next_number(currentNumber,lastNumber,false);
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

void get_next_number(unsigned long &currentNumber, unsigned long &lastNumber, bool triangleNumber) {
	unsigned long temp;
	if (triangleNumber){
		lastNumber = currentNumber;
		currentNumber += 1;
	} else {
		temp = currentNumber;
		currentNumber = 2*temp - lastNumber + 1;
		lastNumber = temp;
	}
}	
