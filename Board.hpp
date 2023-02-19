class GameBoard
{
private:
    int row;
    int col;
    char turn = 'x';
    char board[5][5];

public:
    GameBoard();
    int gameover = 1;
    void draw_board();
    void read_input();
    void gameOver();
};
