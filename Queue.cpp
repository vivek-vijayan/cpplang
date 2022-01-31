#include <iostream>
#include <queue>

int main()
{
    int a, i = 0;
    std::queue<int> q;
    while (i < 5)
    {
        std::cout << " Enter the number : ";
        std::cin >> a;
        q.push(a);
        i++;
    }
    while (i > 0)
    {
        std::cout << "Front in the queue is : " << q.front() << std::endl;
        std::cout << "Popping...." << q.front() << std::endl;
        q.pop();
        i--;
    }
    return 0;
}