/* This is the main file for Plotting Points Progam 
*	, 9/1/2020 */
#include <iostream>
#include "graph.cpp"
using namespace std;

int main()
{
	graph test;
	int *ptrx, *ptry;

	test.readxy();
	ptrx = test.getx();
	ptry = test.gety();
	//cout << "X Coordinates \n";
	//test.printxy(ptrx);	 
	//cout << "Y Coordinates \n";
	//test.printxy(ptry);
	//cout << "Max of x is " << test.findMax(ptrx) << "\n" ;
	//cout << "Min of x is " << test.findMin(ptrx) << "\n" ;
	test.writeGraph();
}