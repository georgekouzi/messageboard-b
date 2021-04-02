/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "Board.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{

    ariel::Board board;
    board.post(/*row=*/0, /*column=*/1, Direction::Horizontal, "***");
    board.post(/*row=*/1, /*column=*/0, Direction::Vertical, "***");
    board.post(/*row=*/4, /*column=*/1, Direction::Horizontal, "***");
    board.post(/*row=*/1, /*column=*/4, Direction::Vertical, "***");

    board.post(/*row=*/2, /*column=*/3, Direction::Horizontal, "***");
    board.post(/*row=*/3, /*column=*/2, Direction::Vertical, "***");
    board.post(/*row=*/6, /*column=*/3, Direction::Horizontal, "***");
    board.post(/*row=*/3, /*column=*/6, Direction::Vertical, "***");

    board.post(/*row=*/0, /*column=*/6, Direction::Horizontal, "***");
    board.post(/*row=*/1, /*column=*/5, Direction::Vertical, "***");
    board.post(/*row=*/4, /*column=*/6, Direction::Horizontal, "***");
    board.post(/*row=*/1, /*column=*/9, Direction::Vertical, "***");

    board.post(/*row=*/2, /*column=*/8, Direction::Horizontal, "***");
    board.post(/*row=*/3, /*column=*/7, Direction::Vertical, "***");
    board.post(/*row=*/6, /*column=*/8, Direction::Horizontal, "***");
    board.post(/*row=*/3, /*column=*/11, Direction::Vertical, "***");

    board.post(/*row=*/0, /*column=*/11, Direction::Horizontal, "***");
    board.post(/*row=*/1, /*column=*/10, Direction::Vertical, "***");
    board.post(/*row=*/4, /*column=*/11, Direction::Horizontal, "***");
    board.post(/*row=*/1, /*column=*/14, Direction::Vertical, "***");

    board.post(/*row=*/8, /*column=*/1, Direction::Horizontal, "Olympics 2021");

    board.post(/*row=*/4, /*column=*/21, Direction::Horizontal, "Part-time employees are needed:");
    board.post(/*row=*/6, /*column=*/30, Direction::Horizontal, "050-0000070");
    for (int i = 1; i < 8; i++)
    {
        board.post(/*row=*/i, /*column=*/19, Direction::Vertical, "|");
    }
    board.post(/*row=*/1, /*column=*/19, Direction::Horizontal, "___________________________________");
    for (int i = 2; i < 8; i++)
    {
        board.post(/*row=*/i, /*column=*/53, Direction::Vertical, "|");
    }
        board.post(/*row=*/7, /*column=*/20, Direction::Horizontal, "_________________________________");

    // board.post(/*row=*/2, /*column=*/21, Direction::Horizontal,"Part-time employees are needed:");
    // board.post(/*row=*/2, /*column=*/21, Direction::Horizontal,"Part-time employees are needed:");

    board.show();

}
