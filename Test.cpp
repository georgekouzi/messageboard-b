#include <string>
#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "Board.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Good code")
{
    Board board;

    CHECK_NOTHROW(board.post(5, 0, Direction::Horizontal, "Beautiful"));
    CHECK_NOTHROW(board.post(14, 14, Direction::Vertical, "world"));
    CHECK(board.read(5, 0, Direction::Horizontal, 9) == "Beautiful");
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "ariel"));
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "george"));
    CHECK(board.read(0, 0, Direction::Horizontal, 6) == "george");
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "ariel"));
    CHECK(board.read(0, 0, Direction::Vertical, 6) == "arielB");
    CHECK(board.read(0, 0, Direction::Horizontal, 6) == "aeorge");
    CHECK_NOTHROW(board.post(0, 3, Direction::Vertical, "gorilla"));
    CHECK(board.read(0, 0, Direction::Horizontal, 6) == "aeogge");
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "ok"));
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "ok"));
    CHECK_NOTHROW(board.post(5012, 5012, Direction::Horizontal, "and"));
    CHECK_NOTHROW(board.post(5012, 5012, Direction::Vertical, "and"));
    CHECK_NOTHROW(board.post(10, 10, Direction::Horizontal, "cake"));
    CHECK_NOTHROW(board.post(10, 10, Direction::Vertical, "cake"));
    CHECK(board.read(10, 10, Direction::Horizontal, 5) == "cake_");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "okogg");
    CHECK(board.read(0, 0, Direction::Vertical, 3) == "oki");
    CHECK(board.read(5012, 5012, Direction::Horizontal, 5) == "and__");
    CHECK(board.read(5012, 5012, Direction::Vertical, 3) == "and");
    
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"123"));
    CHECK_NOTHROW(board.post(1,2,Direction::Horizontal,"ShAlOM"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical , "hello"));
    CHECK_NOTHROW(board.post(4,0,Direction::Vertical , "bye"));
    CHECK_NOTHROW(board.post(1,2,Direction::Vertical , "good sammer"));
    CHECK(board.read(0,0,Direction::Horizontal,3)=="h23");
    CHECK(board.read(1,2,Direction::Horizontal,1)=="g");
    CHECK(board.read(4,5,Direction::Vertical,2)=="_i");
    CHECK(board.read(5,1,Direction::Vertical,4)=="e___");
    CHECK(board.read(6,3,Direction::Vertical,7)=="a______");
}

TEST_CASE("Random index")
{
    Board board;
    for (int i = 0; i < 10000; i++)
    {
        int random_i = (uint)(rand());
        int random_j = (uint)(rand());
        string mes = "050" + to_string(abs((random_i + random_j) % 10));
        CHECK_NOTHROW(board.post(random_i, random_j, Direction::Horizontal, mes));
        CHECK(board.read(random_i, random_j, Direction::Horizontal, 4) == mes);
    }
}

TEST_CASE("bad input:")
{
    ariel::Board board;
    board.post(32, 36, Direction::Vertical, " ");
    CHECK(board.read(32, 36, Direction::Vertical, 1) == " ");

    board.post(1, 10, Direction::Horizontal, " ");
    CHECK(board.read(1, 10, Direction::Horizontal, 0) == " ");
    board.post(100, 1, Direction::Horizontal, "    &*&*&*&*&*");
    CHECK(board.read(100, 1, Direction::Horizontal, 15) == "    &*&*&*&*&*_");
}

