/* This is a definitions file for Points2Graph */
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "graph.h"
using namespace std;

//Constructor for class graph
graph::graph(char *arr){
	size = maxX = minX = maxY = minY = indexX = indexY = 0;
	filename = strdup(arr); 
}

//Destructor for class graph
graph::~graph(){
	delete ptrx;
	delete ptry;
}

// Function that prints array
void graph::printxy(int *ptr){
	for(int i=0; i<size/2; i++)
		cout << ptr[i] << " " ;	
	cout << "\n";
}

// Function for getting ptrx
int* graph::getx(){
	return ptrx;
}

// Function for getting ptry
int* graph::gety(){
	return ptry;
}

// Function for reading points file and saving x and y coords
vector<int> graph::readFile(){
	ifstream inputFile;
	int num, i=0;
	vector<int> inVect;
	
	inputFile.open(filename);
	
	// format 0 0 1 1 where (0, 0), (1, 1)
	while(inputFile >> num)
	{
		inVect.push_back(num);
		i++;
	}

	inputFile.close();
	
	return inVect;
}

// Function for sepparating x and y to pointers
void graph::readxy(){
	vector<int> xyVect;
	int a=0, b=0 ; 
	xyVect = readFile();
	size = xyVect.size();

	ptrx = new int[size/2] ;
	ptry = new int[size/2] ;
	
	for(int i=0; i<size; i++)
	{
		if((i%2)== 0){
			ptrx[a] = xyVect[i];
			a++;
		}
		else{
			ptry[b] = xyVect[i];
			b++;
		}
	}	
}

// Function to find the max number
int graph::findMax(int *ptr)
{	int max = *ptr ;
	for(int i=0; i<size/2; i++){
		if (max < ptr[i])
			max = ptr[i];
	}
	return max;
}

// Function to find the min number
int graph::findMin(int *ptr)
{	int min = *ptr ;
	for(int i=0; i<size/2; i++){
		if (min > ptr[i])
			min = ptr[i];
	}
	return min;
}

// This function sets x's and y's min and max.
void graph::setParamaters(){
	maxX = findMax(ptrx);
	minX = findMin(ptrx);
	maxY = findMax(ptry);
	minY = findMin(ptry);
}

// Function that checks if there is a coordinate in list
bool graph::checkCoord(int numx, int numy){
	int tmpx, tmpy;
	for(int i=0; i<size/2; i++){
		tmpx = ptrx[i];
		tmpy = ptry[i];
		if((numx==tmpx)&&(numy==tmpy))
			return true;
	}
	return false;
}


// This function will draw the graph
void graph::drawGraph(){
	drawTop();
	drawXline();
	drawBot();
	// Example of what graph should look like with
	// x,y max and min of 4's
	//cout << "        4        \n";
	//cout << "        3        \n";
	//cout << "        2        \n";
	//cout << "        1        \n";
	//cout << "4 3 2 1 0 1 2 3 4\n";
	//cout << "        1        \n";
	//cout << "        2        \n";
	//cout << "        3        \n";
	//cout << "        4        \n";
} 

// Draws graph above x-axis
void graph::drawTop(){
	int maxTop = maxY;
	int min = abs(minX);
	int max = abs(maxX);
	cout << "\n";
	if(maxY > 0){
		for(int i = 0; i < maxY; i++){
			if(minX < 0){
				for(int j = 0; j < min; j++)
					if(checkCoord(minX+j,maxY-i))
						cout << "* ";
					else
						cout << "  ";
			}
			cout << maxTop-i;
			if(maxX > 0){ 
				for(int k = 0; k < max; k++)
					if(checkCoord(k+1,maxY-i))
						cout << " *";
					else
						cout << "  ";
			}
			cout << "\n";
		}
	}
}

// Draws x-axis
void graph::drawXline(){
	int min = abs(minX);
	int minNum = min;
	int maxNum = 1;
	if(minX < 0){
		for(int i=0; i<min; i++)
			cout << minNum-i << " ";
	}
	if(checkCoord(0,0))
		cout << "* ";
	else
		cout << "0 ";
	if(maxX > 0){
		for(int j=0; j<maxX; j++)
			cout << maxNum+j << " ";
	}
	cout << "\n";
}

// Draws below the x-axis
void graph::drawBot(){
	int maxBot = abs(minY);
	int maxnum = 1;
	int min = abs(minX);
	int max = abs(maxX);
	if(minY < 0){
		for(int i = 0; i < maxBot; i++){
			if(minX < 0){
				for(int j = 0; j < min; j++)
					if(checkCoord(minX+j, 1+i))
						cout << "* ";
					else
						cout << "  ";
			}
			cout << maxnum+i;
			if(maxX > 0){ 
				for(int k = 0; k < max; k++)
					if(checkCoord(1+k, 1+i))
						cout << " *";
					else
						cout << "  ";
			}
			cout << "\n";
		}
	}
}	

// Function to make and print the graph
void graph::writeGraph(){	
	setParamaters();
	drawGraph();
}

