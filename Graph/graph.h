#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
using namespace std;

template <typename T>
class graph
{
vector<vector<T>> matrix;
vector<T> labels;
public:
	graph() 
	{
		int size = 5;
		for (int i = 0; i < size; i++)
		{
			labels.push_back(-1);
			vector<T> temp;
			matrix.push_back(temp);
			for (int j = 0; j < size; j++)
			{
				matrix.at(i).push_back(-1);
			}
		}
	}

	graph(graph& other) 
	{
		if (!this->matrix.empty())
		{
			this->labels.clear();
			this->matrix.clear();
		}
		vector<int> temp;
		while (temp.size() < other.matrix.size())
		{
			temp.push_back(-1);
		}
		this->labels.push_back(temp);
		for (int i = 0; i < other.matrix.size(); i++)
		{
			this->matrix.push_back(temp);
			this->labels.push_back(other.labels[i]);
			for (int j = 0; j < other.matrix.at(i).size(); j++)
			{
				this->matrix.at(i).at(j) = other.matrix[i][j];
			}
		}
	}

	~graph() 
	{
		//for (auto i = 0; i < matrix.size(); i++)
		//{
		//	delete[] matrix[i];
		//}
		////might not need this delete
		//delete[] matrix;
		//delete[] labels;
	}
	
	vector<T> vertices() 
	{
		//vector<T> verts;
		//if (matrix.empty())
		//{
		//	return verts;
		//}
		//int size = matrix.size();
		//for (unsigned int i = 0; i < size; i++)
		//{
		//	verts.push_back(i);
		//}
		//return verts;
		return labels;
	}

	vector<tuple<T, T>> edges()
	{
		vector<tuptle<T, T>> edgeList;
		for (auto i = 0; i < manyVertices; i++)
		{
			T l1 = labels[i];
			for (auto j = 0; j < manyVertices; j++)
			{
				if (matrix[i][j] > 0)
				{
					T l2 = labels[j];
					tuple <T, T> edge = make_tuple<T, T>(l1, l2);
					edgeList.push_back(edge);
				}
			}
			return edgeList;
		}
	}

	void addVector(T& v)
	{
		//int size = matrix.size();
		//if (v < matrix.size() && v > -1)
		//{
		//	cout << "Vector exists." << endl;
		//}
		//else if (v < 0)
		//{
		//	cout << "Illegal vector." << endl;
		//}
		//else
		//{
		//	vector<T> temp;
		//	for (int i = 0; i < size + 1; i++)
		//	{
		//		temp.push_back(-1);
		//	}

		//	while (size < v)
		//	{
		//		matrix.push_back(temp);
		//		size++;
		//	}
		//}

		for (int i = 0; i < labels.size(); i++)
		{
			if (labels[i] == v)
			{
				cout << "Vector exists." << endl;
				return;
			}
		}
		if (v > 0)
		{
			int size = labels.size();
			if (v > size)
			{
				while (v > size)
				{
					labels.push_back(-1);
					size++;
				}
				labels.push_back(v);
			}
			else
			{
				labels.push_back(v);
			}
			
		}
		if (matrix.size() < labels.size())
		{
			if (matrix.size() < labels.size())
			{
				vector<int> temp;
				while (temp.size() < labels.size())
				{
					temp.push_back(-1);
				}
				while (matrix.size() < labels.size())
				{
					matrix.push_back(temp);
				}
			}
		}
	}

	//add edge with default weight of 1
	void addEdge(T& v1, T& v2)
	{
		addEdge(v1, v2, 1);
	}

	//if the default weight is not 1
	//this is not all of this function
	void addEdge(T& v1, T& v2, int weight)
	{
		if (v1 >= matrix.size() || v1 < 0 || v2 >= matrix.size() || v2 < 0)
		{
			cout << "Vertex doesn't exist." << endl;
		}
		else if (weight < 0)
		{
			cout << "Illegal weight.  Can't accept weights of negative value." << endl;
		}
		else
		{
			int foundOne = 0;
			int foundTwo = 0;
			for (int i = 0; i < labels.size(); i++)
			{
				if (labels[i] == v1)
				{
					foundOne = 1;
				}
				if (labels[i] == v2)
				{
					foundTwo = 1;
				}
			}
			if (foundOne == 0 || foundTwo == 0)
			{
				cout << "Vertex doesn't exist." << endl;
				return;
			}
			for (int i = 0; i < labels.size(); i++)
			{
				if (matrix.size() < labels.size())
				{
					while (matrix.size() < labels.size())
					{
						vector<T> temp;
						matrix.push_back(temp);
					}
				}
				int size = matrix.at(i).size();
				if (size < labels.size())
				{
					while (size < labels.size())
					{
						matrix.at(v1).push_back(-1);
						size++;
					}
				}
			}
			replace(matrix.at(labels[v1]).begin(), matrix.at(labels[v1]).end(), matrix[labels[v1]][labels[v2]], weight);			
		}
	}

	string toString() 
	{
		return "";
	}

	graph& operator=(graph& other) 
	{
		if (!this->matrix.empty())
		{
			this->labels.clear();
			this->matrix.clear();
		}
		vector<int> temp;
		while (temp.size() < other.matrix.size())
		{
			temp.push_back(-1);
			this->labels.push_back(-1);
		}
		
		for (int i = 0; i < other.matrix.size(); i++)
		{
			this->matrix.push_back(temp);
			this->labels.push_back(other.labels[i]);
			for (int j = 0; j < other.matrix.at(i).size(); j++)
			{
				this->matrix.at(i).at(j) = other.matrix[i][j];
			}
		}
		return *this;
	}
	
	bool hasEdge(T& v1, T& v2) 
	{
		//int size = matrix.size();
		//if (v1 < 0 || v2 < 0)
		//{
		//	int temp = 0;
		//	if (v1 < 0)
		//		temp = v1;
		//	else
		//		temp = v2;
		//	cout << "Illegal vertex: " << temp << endl;
		//	return false;
		//}
		//else if (v1 < size && v2 < size && matrix[v1][v2] > 0)
		//{
		//	int size = matrix.at(v1).size();
		//	if (size < matrix.size())
		//	{
		//		while (size < matrix.size())
		//		{
		//			matrix.at(v1).push_back(-1);
		//			size++;
		//		}
		//	}
		//	if (matrix[v1][v2] > 0)
		//		return true;
		//	else
		//		return false;
		//}
		//else if (v1 > size || v2 > size)
		//{
		//	int temp = 0;
		//	if (v1 > 0)
		//		temp = v1;
		//	else
		//		temp = v2;
		//	cout << "Vertex doesn't exist: " << temp << endl;
		//	return false;
		//}
		//else
		//{
		//	cout << "No edge exists between vertex: " << v1 << " and " << v2 << endl;
		//	return false;
		//}
		int oneFound = 0;
		int twoFound = 0;
		int i = 0;
		int size = labels.size();
		if (v1 < 0 || v2 < 0)
		{
			cout << "Out of bounds index: " << v1 << " " << v2 << endl;
			return false;
		}
		while (i < size)
		{
			if (labels[i] == v1)
			{
				oneFound++;
			}
			else if (labels[i] == v2)
			{
				twoFound++;
			}
			i++;
		}
		if (oneFound == 0 || twoFound == 0)
		{
			cout << "Vertice not found: " << v1 << " " << v2 << endl;
			return false;
		}
		if (matrix[labels[v1]][labels[v2]] > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	vector<T> neighbors(T& v) 
	{
		vector<T> temp;
		//int size = matrix[v].size();

		//if (v >= size || v < 0)
		//{
		//	cout << "Illegal vector: " << v << endl;
		//}
		//for (int i = 0; i < size; i++)
		//{
		//	if (matrix[v][i] > 0)
		//	{
		//		temp.push_back(i);
		//	}
		//}
		//return temp;
		if (v < 0)
		{
			return temp;
		}
		int oneFound = 0;
		int size = labels.size();
		int i = 0;
		while (i < size)
		{
			if (labels[i] == v)
			{
				oneFound++;
			}
			i++;
		}
		if (oneFound != 0)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				if (matrix.at(labels[v]).at(i) > 0) //out of bounds???
				{
					temp.push_back(i);
				}
			}
		}
		return temp;
	}

	vector<T> dfs(T& v) 
	{
		return v;
	}

	int shortestPath(T& v1, T& v2) 
	{
		return 0;
	}

	//tuple<T, int> shortestPath(T& v1) 
	//{
	//
	//}
};
#endif