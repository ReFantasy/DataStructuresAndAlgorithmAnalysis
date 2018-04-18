#ifndef __INTCELL_H__
#define __INTCELL_H__
#include <vector>
using namespace std;
class IntCell
{
public:
	explicit IntCell(int initialValue = 0);

	int Read()const;

	void Write(int X);

private:
	int _storedValue;

};

template <typename Object>
class Matrix
{
public:
	Matrix(int rows, int cols)
		:arr(rows)
	{
		for (int i = 0; i < rows; i++)
			arr[i].resize(cols);
	}

	const vector<Object>& operator[](size_t i)const
	{
		return arr[i];
	}

	vector<Object>& operator[](size_t i)
	{
		return arr[i];
	}

	int numrows()const
	{
		return arr.size();
	}
		

	int numcols()const
	{
		return numrows() ? arr[0].size() : 0;
	}
		

private:
	vector<vector<Object>> arr;
};
#endif
