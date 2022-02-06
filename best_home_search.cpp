#include <iostream>
#include <vector>
#define MAX_BLOCK 5
#define MAX_REQ 3
using namespace std;

int display()
{
    cout << "Welcome";
    return 0;
}

int main()
{
    int block_index = 0;
    vector<vector<int> > blocks{
        {0, 1, 0}, // ! Block 1
        {1, 0, 0}, // ! Block 2
        {1, 1, 0}, // ! Block 3
        {0, 1, 0}, // ! Block 4
        {0, 1, 1}, // ! Block 5
    };

    vector<vector<int> > distance_vector;

    while (block_index <= MAX_BLOCK)
    {
        if (block_index == 0)
        {
            for (int i = 0; i < MAX_REQ; i++)
            {
                int distance = 0, check = 0, q_pos = block_index + 1;
                vector<int> temp;
                if (!blocks[block_index][i])
                {
                    while (!check && q_pos < MAX_BLOCK)
                    {
                        check = blocks[block_index][q_pos];
                        if(!check) distance++;
                        q_pos++;
                    }
                    temp.push_back(distance);
                    distance_vector.push_back(temp);
                }
                else
                {
                    temp.push_back(0);
                    distance_vector.push_back(temp);
                }
            }
        }
        block_index++;
    }

    for (int i = 0; i < MAX_REQ; i++)
        cout << distance_vector[0][i] << " ";
}






