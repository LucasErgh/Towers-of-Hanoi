#ifndef TOWERS_H
#define TOWERS_H

#include "mystack.h"

//********************************//
//prototype of class tower        //
//put all functions to towers.cpp //
//DO NOT MODIFY THIS FILE         //
//********************************//

class Towers {
	private:
		MyStack<int> *peg1; //start stack
		MyStack<int> *peg2; //tmp stack
		MyStack<int> *peg3; //destination stack
		int numDisk;	//number of di`scs to move
	public:
		class InvalidMove{};

		//constructor, passing in an int to tell how many discs to move
		Towers(int);
		
		//destructor
		~Towers();
		
		//copy constructor
		Towers(const Towers &);

	   //operator= overloading
	   Towers& operator=(const Towers &);
	   
	   //start function, DO NOT MODIFY
		void start() {
			setDisks();
			move(numDisk, peg1, peg2, peg3); 

			// this is loop to allow me to play the game to get the hang of the logic
			{ // brackets are just so its colapsable
				char fromC, toC;
				int from, to;
				MyStack<int>* pegFrom;
				MyStack<int>* pegTo;

				while (true) {
					std::cout << "Your move, tower from, tower to, towers are 1, 2, 3\n";
					std::cin >> fromC >> toC;
					std::cout << std::endl;
					if (std::cin.fail() || 
						fromC == 'q' || toC == 'q' || 
						fromC < '1' || fromC > '3' ||
						toC < '1' || toC > '3')
					{
						std::cout << "Characters were out of range or entered q\nReceived: " << fromC << toC;
						break;
					}
					to = (int)toC - '0';
					from = (int)fromC - '0';

					switch (to)
					{
					case 1:
						pegTo = peg1;
						break;
					case 2:
						pegTo = peg2;
						break;
					case 3:
						pegTo = peg3;
						break;
					default:
						throw "How'd we end up here?";
					}

					switch (from)
					{
					case 1:
						pegFrom = peg1;
						break;
					case 2:
						pegFrom = peg2;
						break;
					case 3:
						pegFrom = peg3;
						break;
					default:
						throw "How'd we end up here?";
					}

					try { moveOne(pegFrom, pegTo); }
					catch ( std::string ) { std::cout << "Invalid move\n";}
					plotPegs();
				}
			}
		}
		
	private:
		void setDisks();	//initialize start-tower by putting discs in, then print out the status of three towers after initialized
		void plotPegs();	//print out the status of three towers
		void move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d); //move n discs from tower s to tower d by using a temporary tower t
		void moveOne(MyStack<int>* s, MyStack<int>* d);  //move one discs from tower s to tower d
};

#endif
