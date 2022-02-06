/*
* N - Queen problem
* Developed by Vivek Vijayan
? Date: 2 Feb 2022
*/
// * INCLUDES
#include <iostream>

// ! Size of board - output will be displayed for matrix SIZE X SIZE
#define SIZE 20

static int totalQueen = SIZE;

int board[SIZE][SIZE];

void boardInitialize() // ! Board initialiser
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            // ? Board has been initialised
            board[row][col] = 0;
        }
    }
}

bool isSafeToBePlaced(int rowpos, int colpos) // ! Deep check - Consume time for best case.
{
    int row, col;
    bool checkReport = true;

    //? Checking whether any queen presented in the same column
    for (col = 0; col < colpos && checkReport; col++)
        (board[rowpos][col] == 1) ? checkReport = false : checkReport = true;

    // ? Checking whether any queen presented in the diagonals  -- point to LEFT TOP
    for (row = rowpos, col = colpos; row >= 0 && col >= 0 && checkReport; row--, col--)
        (board[row][col] == 1) ? checkReport = false : checkReport = true;

    // ? Checking whether any queen presented in the diagonals  -- point to LEFT BOTTOM
    for (row = rowpos, col = colpos; row < SIZE && col >= 0 && checkReport; row++, col--)
        (board[row][col] == 1) ? checkReport = false : checkReport = true;

    return checkReport;
}

bool placeQueen(int row, int col)
{
    if (board[row][col] == 0)
    {
        board[row][col] = 1; // * Queen has been placed here.
        return true;
    }
    return false;
}

bool removeQueen(int row, int col)
{
    if (board[row][col] == 1)
    {
        board[row][col] = 0; // ! Queen has been removed here.
        return true;
    }
    return false;
}

bool SolveQueenProblem(int col)
{
    if (col >= SIZE)
        return true;
    for (int row = 0; row < SIZE; row++)
    {
        if (isSafeToBePlaced(row, col))
        {
            placeQueen(row, col);
            if (SolveQueenProblem(col + 1))
                return true;
            removeQueen(row, col);
        }
    }
    return false;
}

int main()
{
    boardInitialize();
    if (SolveQueenProblem(0))
    {
        for (int row = 0; row < SIZE; row++)
        {
            for (int col = 0; col < SIZE; col++)
            {
                // ? Board has been initialised
                std::cout << board[row][col] << "  ";
            }
            std::cout << "\n";
        }
    }
    else
    {
        std::cout << "No Solution !!! \n";
    }
    return 0;
}
