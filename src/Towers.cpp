#include "Towers.h"
#include "MyStack.h"

#include <iostream>

using namespace std;
//YOUR CODE
//......

		Towers::Towers(int size) : numDisk(size), 
		peg1(new MyStack<int>(size)), // im just using the initialization list for all of these 
		peg2(new MyStack<int>(size)), 
		peg3(new MyStack<int>(size)){ }
		
		//destructor
		Towers::~Towers() {
			delete peg1;
			delete peg2;
			delete peg3;
		 }
		
		//copy constructor
		Towers::Towers(const Towers& rhs) : numDisk(rhs.numDisk), 
		peg1(rhs.peg1), // copying pegs from rhs to this
		peg2(rhs.peg2),
		peg3(rhs.peg3) { }

	   //operator= overloading
	   Towers& Towers::operator=(const Towers& rhs) {
		*this = Towers(rhs); // use copy constructor to create and assign new tower
	    	return *this;
		}

		void Towers::setDisks() { 
			//initialize start-tower by putting discs in, then print out the status of three towers after initialized
			for (int i = numDisk; i > 0; --i) {
				peg1->push(i);
			}
			plotPegs();
		}	

		void Towers::move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d) { 
			//move n discs from tower s to tower d by using a temporary tower t

			/*
			n-k
			n-2
			n-1
			n-0
			*/
			
			// First we move n-1 disk to temp peg
			if (n > 1) move(n-1, s, d, t);
			/*
			        n-k
			        n-2
			n-0     n-1
			*/
			// then we move n disk to destination peg
			try{moveOne(s,d);}
				catch(InvalidMove){std::cout<<"Invalid Move attmepted";} 
			plotPegs();
			/*
			        n-k
			        n-2
			    n-0 n-1
			*/
			// now we move n-1-1 peg to temp peg
			if(n > 2) move(n-2, t, d, s);
			/*    
			n-k  
			n-2 n-0 n-1
			*/
			// finally move n-1 peg to destination 
			if (n > 1) { 
				try{moveOne(t,d);}
				catch(InvalidMove){std::cout<<"Invalid Move attmepted";} 

			}
			/*
			
			n-k n-1 
			n-2 n-0
			*/
			// now put it all back on destination peg
			if(n > 2) move(n - 2, s, t, d);
			/*
			n-k
			n-2
			n-1
			n-0
			*/	
		} 

		void Towers::moveOne(MyStack<int>* s, MyStack<int>* d) { 
			//move one discs from tower s to tower d
			if(s->top() < d->top() && s != d) {
				d->push(s->pop());
				plotPegs();
			}
			else{
				throw InvalidMove();
			}
		}  

		
//display disks on the three pegs in the console window (stdout)
//DO NOT MODIFY THIS FUNCTION
void Towers::plotPegs()
{
  	if (peg1==NULL || peg2==NULL || peg3==NULL) return;

	int n1=peg1->size();
	int n2=peg2->size();
	int n3=peg3->size();
	int numDisk = n1+n2+n3;

	MyStack<int> tmp1(*peg1);
	MyStack<int> tmp2(*peg2);
	MyStack<int> tmp3(*peg3);

	//plot
	for (int i=0; i<numDisk; i++) {
		//peg1
		if (numDisk-n1-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m1 = tmp1.top();
			tmp1.pop();
			for (int j=0; j<m1; j++)
				cout << "*";
			for (int j=m1; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg2
		if (numDisk-n2-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m2 = tmp2.top();
			tmp2.pop();
			for (int j=0; j<m2; j++)
				cout << "*";
			for (int j=m2; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg3
		if (numDisk-n3-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m3 = tmp3.top();
			tmp3.pop();
			for (int j=0; j<m3; j++)
				cout << "*";
			for (int j=m3; j<numDisk; j++)
				cout << " ";
		}
		cout<<endl;
	}
	cout << "_________________________________________\n";
}
