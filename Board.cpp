#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>


using namespace std;
//using namespace ariel;



namespace ariel{
    void Board::post(unsigned int row, unsigned int col, Direction d, string const &message){
        // std::string location = to_string(row) + "," + to_string(col);
        // this->messages[location] = message;
        ++this->x;
        std::cout << "post ";
        std::cout << message;
        std::cout << endl;
    }

    string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int length){
        // std::string message = this->messages.at(to_string(row));        //  index!
        // if (message.empty()){
        //     message= "";
        //     for (int i=0; i<length; ++i){
        //         message += "_";
        //     }
        // }
        // return message;
        ++this->x;
        return "A";
    }

    void Board::show(){
        // this->messages["100"] = "h";
        // std::cout << "message";
        ++this->x;
        cout<<"show";
    };
}