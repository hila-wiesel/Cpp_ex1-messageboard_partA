#include "doctest.h"
#include "Board.hpp"
#include <algorithm>
#include <stdexcept>
#include "Direction.hpp"

using namespace ariel;
using namespace std;
//using namespace ariel::Direction;



TEST_CASE("simple tests for functions- post and read"){
    Board board = Board();

	board.post(10, 20, Direction::Horizontal, "abcd");
    CHECK( board.read(10, 20, Direction::Horizontal, 4) == "abcd");

    board.post(0, 0, Direction::Vertical, "111");
    CHECK( board.read(0, 0, Direction::Vertical, 3) == "111");
}


TEST_CASE("read empty spaces as _"){
    Board board = Board();
    CHECK(board.read(10, 20, Direction::Horizontal, 4) == "____");  

    board.post(0, 0, Direction::Horizontal, "111");
    CHECK(board.read(10, 20, Direction::Horizontal, 4) == "111_");  
}


TEST_CASE("read the last message in this place"){
    Board board = Board();

	board.post(10, 20, Direction::Horizontal, "123456789");
    CHECK(board.read(10, 20, Direction::Horizontal, 9) == "123456789"); 
    
	board.post(10, 20, Direction::Horizontal, "abcd");
    CHECK(board.read(10, 20, Direction::Horizontal, 4) == "abcd"); 
    CHECK(board.read(10, 20, Direction::Horizontal, 9) == "abcd56789"); 

	board.post(10, 20, Direction::Vertical, "xx");
    CHECK(board.read(10, 20, Direction::Vertical, 2) == "xx");
    CHECK(board.read(10, 20, Direction::Horizontal, 4) == "xbcd");
}
    

TEST_CASE("post and read messege with down line"){
    Board board = Board();
	board.post(0, 0, Direction::Horizontal, "Line 1.\nLine2.");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "Line 1.");
    CHECK(board.read(1, 0, Direction::Horizontal, 7) == "Line 2.");

	board.post(0, 0, Direction::Horizontal, "Hello!\nTo\nYou!");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "Hello");
    CHECK(board.read(1, 0, Direction::Horizontal, 2) == "To");
    CHECK(board.read(2, 0, Direction::Horizontal, 4) == "You!");

}

TEST_CASE("empty message"){
    Board board = Board();
	board.post(0, 0, Direction::Horizontal, "");
    CHECK(board.read(0, 0, Direction::Horizontal, 4) == "____");

	board.post(1, 1, Direction::Horizontal, "Hi");
    board.post(1, 1, Direction::Horizontal, "");
    CHECK(board.read(1, 1, Direction::Horizontal, 2) == "Hi");
}

TEST_CASE("space as a message"){
    Board board = Board();
	board.post(0, 0, Direction::Horizontal, "    ");
    CHECK(board.read(0, 0, Direction::Horizontal, 4) == "    ");

	board.post(1, 1, Direction::Horizontal, "Hi");
    CHECK(board.read(1, 1, Direction::Horizontal, 2) == "Hi");
    board.post(1, 1, Direction::Horizontal, " ");
    CHECK(board.read(1, 1, Direction::Horizontal, 2) == " i");

    board.post(10, 10, Direction::Vertical, "  ");
    CHECK(board.read(10, 10, Direction::Horizontal, 2) == "  ");


}

