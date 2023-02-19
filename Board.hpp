class GameBoard
{
private:
    int row;
    int col;
    char turn = 'x';
    char board[4][4];

public:
    GameBoard();
    int gameover = 1;
    void draw_board();
    void read_input();
    void gameOver();
};
