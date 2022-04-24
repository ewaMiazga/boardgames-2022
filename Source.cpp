#include "Sudoku.h"
#include "TicTacToe.h"

int main()
{
    std::cout << "Hello World!\n";

    //Sudoku s1(50);
    //int mat[9][9] =
    //{
    //    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    //    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    //    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    //    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    //    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    //    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    //    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    //    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    //    {0, 0, 0, 0, 8, 0, 0, 7, 9}
    //};
    //s1.displaySudoku();
    //s1.fillBoard(mat);
    //std::cout << std::endl;
    //s1.displaySudoku();
    //std::cout << std::endl;
    //s1.generateStartBoard();
    //s1.displaySudoku();

    //if (1 == 0 == 0)
    //   std::cout << "ewa" << std::endl;
    TicTacToe t1;
    t1.display();
    //t1.insert(0, 1, 'X');
    //t1.insert(1, 1, 'O');
    //t1.insert(2, 1, 'X');
    //t1.display();
    //t1.gameOver();
    //t1.insert(0, 0, 'X');
    //t1.insert(0, 2, 'X');
    //t1.insert(1, 0, 'X');
    //t1.insert(1, 2, 'X');
    //t1.insert(2, 0, 'X');
    //t1.insert(2, 2, 'X');
    t1.insert(0, 1, 'O');
    t1.insert(1, 1, 'O');
    //t1.insert(1, 1, 'O');
    //t1.insert(2, 1, 'X');
    t1.display();
    t1.moveAI('X', 'O');
    t1.insert(0, 0, 'O');
    t1.moveAI('X', 'O');
    t1.moveAI('X', 'O');
    t1.display();
    t1.gameOver();
    system("pause 0");
    return 0;
}