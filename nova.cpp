#include <iostream>

using namespace std;

const unsigned long long TARGET = 70;

int main(){
	unsigned long long number = 3;
	unsigned long long prev_number = 0;
	unsigned long long temp = 0;
	unsigned long long index = 0;
	unsigned long long num_of_triangles = 0;
	unsigned long long next_triangle = 0;
	unsigned long long m = 0;

	while(num_of_triangles<TARGET){
		//get next triangle number
		while(next_triangle<number){
			m++;
			next_triangle = (m*(m+1)/2);
		}
		//cout << number << ":" << next_triangle<<"\n";
		if(number==next_triangle){
			num_of_triangles++;
			cout << num_of_triangles << ": " <<number << "\n";
			prev_number = number;
			number++;
			index++;
		} else{
			
			temp = (2*number-prev_number+1);
			prev_number=number;
			number=temp;
			index++;
		}
	}
	cout << "death";

	return 0;
}