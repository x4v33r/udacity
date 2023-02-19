#include "Board.hpp"
#include <iostream>

GameBoard::GameBoard()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            board[i][j] = '-';
        }
    }
}

void GameBoard::gameOver()
{
    int count_x = 0;
    int count_o = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == j && board[i][j] == 'x')
            {
                count_x++;
            }
            if (i == j && board[i][j] == 'o')
            {
                count_o++;
            }
        }
    }

    if (count_x == 4)
    {
        std::cout << "Player x wins";
        gameover = 0;
    }
    if (count_o == 4)
    {
        std::cout << "Player y wins";
        gameover = 0;
    }
}

void GameBoard::read_input()
{
    if (turn == 'x')
        std::cout << "Player 1 turn\n";
    if (turn == 'o')
        std::cout << "Player 2 turn\n";

    std::cin >> row;
    std::cin >> col;

    if (turn == 'x' && board[row][col] != 'x' && board[row][col] != 'o')
    {
        board[row][col] = 'x';
        turn = 'o';
    }

    else if (turn == 'o' && board[row][col] != 'x' && board[row][col] != 'o')
    {
        board[row][col] = 'o';
        turn = 'x';
    }

    else
    {
        std::cout << "Box already filled. Please choose another! \n\n";
        read_input();
    }
}

void GameBoard::draw_board()
{
    std::cout << " ";
    for (int n = 0; n < 6; n++)
    {
        std::cout << " " << n;
    }
    std::cout << "\n";
    for (int i = 0; i < 6; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < 6; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}