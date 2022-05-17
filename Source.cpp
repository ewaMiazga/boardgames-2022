#include "Sudoku.h"
#include "TicTacToe.h"
#include "Crossword.h"

int main()
{
    std::cout << "Hello World!\n";
    /*int arr[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };*/
    //{ 
    //    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    //    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    //    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    //    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    //    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    //    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    //    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    //    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    //    { 0, 0, 5, 2, 0, 6, 3, 0, 0 } 
    //};

    //int arr[9][9] = {
    //    {5, 9, 8, 3, 2, 6, 1, 4, 7},
    //    {6, 4, 3, 9, 7, 1, 5, 8, 2},
    //    {1, 7, 2, 4, 5, 8, 3, 9, 6},
    //    {9, 8, 1, 2, 6, 3, 4, 7, 5},
    //    {3, 5, 4, 8, 1, 7, 2, 6, 9},
    //    {2, 6, 7, 5, 9, 4, 8, 3, 1},
    //    {4, 1, 6, 7, 8, 2, 9, 5, 3},
    //    {7, 3, 9, 1, 4, 5, 6, 2, 8},
    //    {8, 2, 5, 6, 3, 9, 7, 1, 4}
    //};

//    int arr[9][9] = { {1 , 8 , 7 , 9 , 6 , 4 , 3 , 5 , 2 },
//        {2, 3, 6, 1, 8, 5, 9, 4, 7},
//        {5 , 4 , 9 , 2 , 3 , 7 , 6 , 1 , 8} ,
//        {6 , 9 , 4 , 7 , 2 , 1 , 5 , 8 , 3} ,
//        {3 , 1 , 5 , 4 , 9 , 8 , 2 , 7 , 6} ,
//        {7 , 2 , 8 , 6 , 5 , 3 , 4 , 9 , 1} ,
//        {4 , 5 , 3 , 8 , 1 , 2 , 7 , 6 , 9} ,
//        {8 , 6 , 2 , 5 , 7 , 9 , 1 , 3 , 4} ,
//        {9 , 7 , 1 , 3 , 4 , 6 , 8 , 2 , 5} 
//};
//
//    Sudoku s1(50);
//    int** mat;
//    mat = new int* [10];
//    for (int i = 0; i < 9; i++)
//        mat[i] = new int[10];
//    for (int i = 0; i < 9; i++)
//        mat[i] = arr[i];
    //s1.displaySudoku();
    //s1.fillBoard(mat);
    //std::cout << std::endl;
    //s1.solve(0, 0);
    //s1.generateSolvedBoard();
    //s1.displaySudoku();
    //std::cout << std::endl;
    //s1.generateStartBoard();
    //s1.play();
    //s1.solve(0, 0, )

    //if (1 == 0 == 0)
    //   std::cout << "ewa" << std::endl;
    //TicTacToe t1;
    //t1.display();
    ////t1.insert(0, 1, 'X');
    ////t1.insert(1, 1, 'O');
    ////t1.insert(2, 1, 'X');
    ////t1.display();
    ////t1.gameOver();
    ////t1.insert(0, 0, 'X');
    ////t1.insert(0, 2, 'X');
    ////t1.insert(1, 0, 'X');
    ////t1.insert(1, 2, 'X');
    ////t1.insert(2, 0, 'X');
    ////t1.insert(2, 2, 'X');
    ////t1.insert(0, 1, 'O');
    //t1.insert(1, 1, 'O');    
    //t1.display();
    //t1.moveAI('X', 'O');
    //t1.display();
    //t1.insert(1, 2, 'O');
    //t1.display();
    //t1.moveAI('X', 'O');
    //t1.display();
    //t1.insert(2, 0, 'O');
    //t1.display();
    //t1.moveAI('X', 'O');
    //t1.display();
    //t1.insert(0, 1, 'O');
    //t1.display();
    //t1.moveAI('X', 'O');
    //t1.insert(2, 2, 'X');
    ////t1.insert(2, 1, 'X');
    //t1.display();
    ////t1.display();
    ////t1.moveAI('X', 'O');
    ////t1.insert(0, 0, 'O');
    ////t1.moveAI('X', 'O');
    ////t1.moveAI('X', 'O');
    ////t1.display();
    //t1.gameOver();

   TicTacToe board;
   board.play();
   // board.insert(1, 1, 'O');
   // //board.insert(0, 2, 'O');
   // board.insert(1, 0, 'X');
   // //board.insert(1, 1, 'O');
   // //board.insert(0, 1, 'X');
   //// board.insert(1, 0, 'O');
   // board.display();
   // board.moveAI('X', 'O');
   // board.display();
   // board.gameOver();

    //Crossword c1;
    //std::cout << c1.getClue() << std::endl;
    //std::cout << c1.getClueInfo() << std::endl;
    //c1.display();
    ////std::cout << "write clue" << std::endl;
    ////int num;
    ////std::string clue;
    ////std::cin >> num;
    ////std::cin >> clue;
    ////c1.insert(num, clue);
    ////c1.solveCrossword();
    //c1.play();
    //c1.checkCorrectness();
    system("pause 0");
    return 0;
}