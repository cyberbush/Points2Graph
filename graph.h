/* This is a header file for Points2Graph */
using namespace std;
class graph{
	public:
		graph(char *arr);
		~graph();
		void printxy(int *);
		vector<int> readFile();
		int* getx();
		int* gety();
		void readxy();
		int findMax(int *);
		int findMin(int *);
		bool checkCoord(int numx, int numy);
		void setParamaters();
		void drawGraph();
		void drawTop();
		void drawXline();
		void drawBot();
		void writeGraph();
	private:;
		int *ptrx, *ptry;
		int size, maxX, minX, maxY, minY, indexX, indexY;
		char *filename;
};
