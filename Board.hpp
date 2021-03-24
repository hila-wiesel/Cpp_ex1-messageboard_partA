#include <string>
#include <map>
#include "Direction.hpp"

namespace ariel{
    class Board{

        private:
        std::map<std::string, std::string> messages;
        int x=0;

        public:

        Board(){}
        ~Board(){}
        
        void post(unsigned int row,unsigned int col, Direction d, std::string const &message);
        std::string read(unsigned int row, unsigned int  col, Direction d, unsigned int length);
        void show();
    };

}