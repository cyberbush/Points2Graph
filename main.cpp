/* This is the main file for Points2Graph 
*	, 9/1/2020 */
#include <iostream>
#include "graph.cpp"
using namespace std;

int main(int argc, char *argv[])
{
	graph test(argv[1]); 
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
