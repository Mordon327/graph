#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class dictionary {
	//this struct allows you to use a doubly linked list if you want, for chaining entries
	//but you can also use a vector--so modify this accordingly
	struct Entry {
		T key;

		Entry(const T& newKey, double val) { key = newKey; }
	};

	vector<vector<Entry>> myVec;

public:
	//Constructor that takes maximum capacity as a parameter: size table so that 75 % of max capacity is "full"--above than requires a resize
	const int SIZE = 127;
	dictionary()
	{

		for (int i = 0; i < SIZE; ++i)
		{
			myVec.push_back(vector <Entry>());
		}
	}


	dictionary(unsigned int max_capacity)
	{
		for (unsigned int i = 0; i < max_capacity; ++i)
		{
			myVec.push_back(vector <Entry>());
		}
	}


	dictionary(dictionary &in)
	{
		if (this == &in)
		{
			return;
		}
		this->clear();
		this->myVec.resize(in.myVec.size());
		for (unsigned int i = 0; i < in.myVec.size(); ++i)
		{
			for (unsigned int j = 0; j < in.myVec.at(i).size(); ++j)
			{
				this->myVec.at(i).at(j).key = in.myVec.at(i).at(j).key;
				this->myVec.at(i).at(j).value = in.myVec.at(i).at(j).value;
			}
		}
	}


	~dictionary()
	{
		for (unsigned int i = 0; i < myVec.size(); ++i)
		{
			myVec.at(i).clear();
		}
		myVec.clear();
	}

	//remove all from hash table
	void clear()
	{
		for (unsigned int i = 0; i < myVec.size(); ++i)
		{
			myVec.at(i).clear();
		}
	}

	//use a good hash function for keys & resolve collisions with chaining
	void put(const string& key, const double value)
	{
		//Temporary fix, one out of four isn't bad.
		if (value == NULL)
		{
			return;
		}

		if (myVec.at(key).empty())
		{
			myVec.at(key).push_back(Entry(key, value));
		}
		myVec.at(key).push_back(Entry(key, value));
	}


	void remove(const int& key)
	{
		if (myVec.at(key).empty())
		{
			return;
		}
		else
		{
			for (unsigned int i = 0; i < myVec.at(key).size(); ++i)
			{
				if (myVec.at(key).at(i).key == key)
				{
					myVec.at(value).erase(myVec.at(value).begin() + i);
				}
			}
		}
	}


	double get(const string& key)
	{
		int value = hash(key);
		if (myVec.at(value).empty())
		{
			return -1;
		}
		else
		{
			for (unsigned int i = 0; i < myVec.at(value).size(); ++i)
			{
				string compare = myVec.at(value).at(i).key;
				if (compare == key)
				{
					return myVec.at(value).at(i).value;
				}
			}
			cout << "Key not found.";
			return -1;
		}
	}

	//default value is a value to return if key is not found in the table
	double get(const string& key, double defaultValue)
	{
		int value = hash(key);
		if (myVec.at(value).empty())
		{
			return defaultValue;
		}
		else
		{
			for (unsigned int i = 0; i < myVec.at(value).size(); ++i)
			{
				if (myVec.at(value).at(i).key == key)
				{
					return myVec.at(value).at(i).value;
				}
			}
			cout << "Key not found.";
			return defaultValue;
		}
	}


	double operator[](const string& key)
	{
		return get(key);
	}

	//copy constructor
	dictionary& operator=(const dictionary& in)
	{
		if (this == &in)
		{
			return *this;
		}

		this->clear();

		//dictionary newDictionary;
		for (unsigned int i = 0; i < in.myVec.size(); ++i)
		{
			for (unsigned int j = 0; j < in.myVec.at(i).size(); ++j)
			{
				string temp = in.myVec.at(i).at(j).key;
				double nums = in.myVec.at(i).at(j).value;
				this->put(temp, nums);
			}
		}
		return *this;
	}

};
#endif