#include "Board.hpp"
#include <iostream>

GameBoard::GameBoard()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = '-';
        }
    }
}

void GameBoard::gameOver()
{
    int count_x = 0;
    int count_o = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if (board[i][j + 1] == 'x' && board[i + 1][j + 2] == 'x' && board[i + 2][j + 3] == 'x')
            {
                std::cout << "Player x wins\n";
                draw_board();
                gameover = 0;
            }

            else if (board[i + 1][j] == 'x' && board[i + 2][j + 1] == 'x' && board[i + 3][j + 2] == 'x')
            {
                std::cout << "Player x wins\n";
                draw_board();
                gameover = 0;
            }

            else if (board[i][j + 3] == 'x' && board[i + 1][j + 2] == 'x' && board[i + 2][j + 1] == 'x')
            {
                std::cout << "Player x wins\n";
                draw_board();
                gameover = 0;
            }

            else if (i == j && board[i][j] == 'x')
            {
                count_x++;
            }
            else if (i == j && board[i][j] == 'o')
            {
                // chnange logic here
                count_o++;
            }

            else
            {
                std::cout << "Player o wins\n";
                draw_board();
                gameover = 0;
            }
        }
    }

    if (count_x == 3)
    {
        std::cout << "Player x wins";
        draw_board();
        gameover = 0;
    }
    if (count_o == 3)
    {
        std::cout << "Player y wins";
        draw_board();
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
    for (int n = 0; n < 4; n++)
    {
        std::cout << " " << n;
    }
    std::cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < 4; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}