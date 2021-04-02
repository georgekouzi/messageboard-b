#include <map>
#include <limits>
#include "Direction.hpp"
using ariel::Direction;

namespace ariel
{

    class Board
    {
    private:
        std::map<std::pair<unsigned int, unsigned int>, char> my_board;
        std::pair<unsigned int, unsigned int> min_cap;
        std::pair<unsigned int, unsigned int> max_cap;
        const double Minimum_epsilon;
        const double Maximum_epsilon;

    public:
        Board() : max_cap(0, 0), min_cap(std::numeric_limits<unsigned int>::max(), std::numeric_limits<unsigned int>::max()), Minimum_epsilon(0.9), Maximum_epsilon(1.1){};
        void post(unsigned int row, unsigned int col, Direction d, const std::string &s);
        std::string read(unsigned int row, unsigned int col, Direction d,  unsigned int length);
        void show();
        void sizeOfShow(Direction d,unsigned int row, unsigned int col,unsigned int length);
    };

}; // namespace ariel