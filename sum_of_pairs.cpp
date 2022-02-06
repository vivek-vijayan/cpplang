#include<iostream>
#include<vector>

int main()
{
	std::vector<int> a{1,2,4,6,8,9,3,5,2,4,8,7,20};
	int sum = 27;
	std::cout << "Enter the sum : "; //std::cin >> sum;

	// sorting the data in the ascending order
	for(int x = 0; x < a.size(); x++)
	{
		for(int y = x; y < a.size(); y++)
		{
			if(a[x]>a[y])
			{
				int temp = a[x];
				a[x] = a[y];
				a[y] = temp;
			}
		}
	}
	for(int i = 0; i < a.size(); i++) 
	std::cout << a[i] << std::endl;

	int pointer_l = 0, pointer_r = a.size()-1;
	while(pointer_l <= pointer_r)
	{
		if(a[pointer_l] + a[pointer_r] == sum)
		{
		//	std::cout << "Sum : " << sum << " can be generated by " << a[pointer_r] << " + " << a[pointer_l] << std::endl;
			pointer_l ++;
		}
		else if(a[pointer_r] + a[pointer_l] > sum) pointer_r --; else pointer_l ++;
	}
	//std::cout << "No possible answers \n";
	return 0;
}
	
