#include <iostream>

//#include <curses.h>
#include "Pieces.h"
#include <chrono>

int main()
{
    std::array<int, 5> board = {0, 0, 0, 0, 1};
    std::array<int, 1> sprite = {1};
    size_t posY  = 0;   //счетчик положения обьекта
    bool endGame = false;
    size_t deadLine{0};
    bool createNewSprite{false};
    while( !endGame )
    {

        for( size_t row = 0; row < board.size(); row++)
        {
            if( board[row] == 1 ) { std::cout << "#"; };    // draw element from board
            if ( row <= posY )                  // start draw sprite
            {
                int index = posY; // 2
                if( index < sprite.size() )      // check out of array
                {
                    if( sprite[index] == 1 ) (std::cout << "#") ;    // draw if 2
                    // save sprite on board if prev element on board == 1 and cur element in sprite == 2
                    if ( row != 0 && board[row-1] == sprite[index] )
                    {
                        board[row] = sprite[index];     // save Sprite in board
                        createNewSprite = true;
                        ++deadLine;
                    }
                }
            }
            std::cout << std::endl;
        }
        system("cls");

        if (createNewSprite)
        {
            posY = 0;
            createNewSprite = false;
        }
        else
        {
            sleep(1);
            ++posY;
        }
        if (deadLine == board.size() - 1)
        {
            endGame = true;
        }
    }
    system("cls");
    return 0;
}