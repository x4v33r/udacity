#include <iostream>
#include "Board.hpp"

int main()
{
    // instance which creates the board
    GameBoard game;

    std::cout << "Welcome to TicTacToe!!!\n";

    std::cout << "\n\n";

    while (game.gameover)
    {
        game.draw_board();
        game.read_input();
        game.gameOver();
    }

    return 0;
}
