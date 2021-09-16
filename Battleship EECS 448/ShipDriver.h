#ifndef SHIPDRIVER_H
#define SHIPDRIVER_H

#include <iostream>
#include <stdexcept>
#include <tuple>
#include "ShipBoard.h"
#include "DisplayBoard.h"

class ShipDriver
{
	private:
		ShipBoard m_P1;
		ShipBoard m_P2;
		int m_P1ShipNum; // Number of ships chosen by Player 1
		int m_P2ShipNum; // Number of ships chosen by Player 2
		int playerTurn; // Stores the current turn. Value initialized to 1 for Player One, -1 for Player Two. Multiply by -1 to change turns. 
		int counter = 0; // Counter used to ensure all ships have been placed
	

	public:

		ShipDriver();
	
		/*
		@pre: None
		@post: Sets up ship locations and marks them on the respective player's shipBoard
		@param: None
		@return: None
		*/
	
		void SetUpBoard();

		/*
		@pre: None
		@post: Initializes the start of the game
		@param: None
		@return: None
		*/
		//void StartGame();

		/*
		@pre: None
		@post: None
		@param: None
		@return: True if board satisfies win condition, false if not
		*/
		bool CheckWin();

		/*
		@pre: Get both user's desired number of ships
		@post: Get's position for each ship and populates the board
		@param: Number of ships for both players, integer. 
		@return: None
		*/
		void PopulateBoard(int m_P1ShipNum, int m_P2ShipNum);

		/*
		@pre: Get coordinate from player. For example, "A1"
		@post: Converts the alphanumeric coordinate to a row and column on the board. 
		@param: The coordinate string
		@return: The row and column of the ship's placement as tuple. Returns -1 on bad input in first index location of tuple. 
		*/
		std::tuple<int, int> ConvertCoordinate(std::string coordinate);

		/*
		@pre: Get Row and Col of location that needs to be marked and which player's turn it is
		@post: Mark Loction at Row/Col
		@param: Coordinates (row, col)
		@return: None
		*/
		void PlaceShip(int row, int col); //We can change this to a tuple I just don't know how to use them ATM
};
#endif
