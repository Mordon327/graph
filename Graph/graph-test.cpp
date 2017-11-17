#include "graph.h"
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
using namespace std;
	int zero = 0;
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;
	int five = 5;
	int six = 6;
	int seven = 7;
	int outofbounds = -1;
	void print(vector<int> v)
	{
		if (v.empty())
		{
			cout << "Empty vector." << endl;
			return;
		}
		for (unsigned int i = 0; i < v.size(); i++)
		{
			cout << v[i] << ", ";
		}
		cout << endl;
	}

int main()
{
	graph<int> matrix;
	vector<int> stuff;
	stuff = matrix.vertices();
	print(stuff);

	matrix.addEdge(zero, one);
	matrix.addEdge(one, two, three);
	matrix.hasEdge(zero, one);
	matrix.hasEdge(zero, two);
	matrix.addVector(six);
	matrix.addVector(three);
	matrix.addEdge(six, one, four);
	matrix.addEdge(six, two, two);
	matrix.hasEdge(six, outofbounds);
	matrix.hasEdge(outofbounds, zero);
	matrix.addVector(seven);
	matrix.addEdge(six, one, four);
	matrix.addEdge(six, two, two);
	matrix.hasEdge(six, outofbounds);
	matrix.hasEdge(outofbounds, zero);
	stuff = matrix.neighbors(three);
	print(stuff);
	stuff = matrix.neighbors(six);
	print(stuff);
	graph<int> newMatrix;
	matrix.addEdge(six, six);
	newMatrix = matrix;
	stuff = matrix.neighbors(six);
	print(stuff);


	system("Pause");
}