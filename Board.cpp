#include "Board.hpp"
#include <iostream>
using namespace std;

namespace ariel
{
    void Board::post(unsigned int row, unsigned int col, Direction d, const std::string &s)
    {
        sizeOfShow(d, row, col, s.length());

        if (d == Direction::Horizontal)
        {
            for (size_t i = 0; i < s.length(); i++)
            {
                my_board[{row, col++}] = s.at(i);
            }
        }
        else if (d == Direction::Vertical)
        {
            for (size_t i = 0; i < s.length(); i++)
            {
                my_board[{row++, col}] = s.at(i);
            }
        }
    }

    void Board::sizeOfShow(Direction d, unsigned int row, unsigned int col, unsigned int length)
    {
        if (min_cap.first > row)
        {
            min_cap.first = row;
        }
        if (min_cap.second > col)
        {
            min_cap.second = col;
        }

        if (d == Direction::Vertical)
        {

            if (max_cap.first < row + length)
            {
                max_cap.first = row + length;
            }

            if (max_cap.second < col)
            {
                max_cap.second = col;
            }
        }

        if (d == Direction::Horizontal)
        {
            if (max_cap.first < row)
            {
                max_cap.first = row;
            }
            if (max_cap.second < col + length)
            {
                max_cap.second = col + length;
            }
        }
    }

    string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int length)
    {
        if (length == 0)
        {
            return "";
        }

        int dist = 0;

        map<std::pair<unsigned int, unsigned int>, char>::iterator it;
        string s;

        if (d == Direction::Horizontal)
        {
            while (dist != length)
            {

                it = my_board.find({row, col});
                if (it == my_board.end())
                {
                    s += "_";
                    col++;
                    dist++;
                }
                else
                {
                    s += my_board[{row, col}];
                    col++;
                    dist++;
                }
            }
        }

        else if (d == Direction::Vertical)
        {
            while (dist != length)
            {

                it = my_board.find({row, col});
                if (it == my_board.end())
                {
                    s += "_";
                    row++;
                    dist++;
                }
                else
                {
                    s += my_board[{row, col}];
                    row++;
                    dist++;
                }
            }
        }

        return s;
    } // namespace ariel

    void Board::show()

    {
        string show;

        map<std::pair<unsigned int, unsigned int>, char>::iterator it;

        for (int i = (int)(min_cap.first * Minimum_epsilon); i <= (int)(max_cap.first * Maximum_epsilon); i++)
        {
            for (int j = (int)(min_cap.second * Minimum_epsilon); j <= (int)(max_cap.second * Maximum_epsilon); j++)
            {

                it = my_board.find({i, j});

                if (it == my_board.end())
                {
                    show += " ";
                }
                if (it != my_board.end())
                {
                    show += it->second;
                }
            }
            show += "\n";
        }

        cout << show << endl;
    }
}; // namespace ariel