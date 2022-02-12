#include<iostream>
#include<string>
class Add
{
	public: std::string username; int num1, num2, output;
		int set(int _num1, int _num2) {
			num1 = _num1;
			num2 = _num2;
			return 0;
		}
		int sum(){
			return num1 + num2;
		}
		
};
