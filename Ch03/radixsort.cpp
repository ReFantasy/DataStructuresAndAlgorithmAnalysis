#include "radixsort.h"
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;

// N is the size of Array
void RadixSort(unsigned int Array[], const unsigned int N)
{
	unsigned int *buckets[10];
	for (size_t i = 0; i < 10; i++)
		buckets[i] = new unsigned int[N];

	for (unsigned int i = 0; i < 10; i++)
	{
		unsigned int sizePerBucket[10] = { 0 };
		PushToBucket(Array, N, buckets, sizePerBucket, i);
		PopToBucket(Array, buckets, sizePerBucket);
	}
}

void PushToBucket(unsigned int Array[], const unsigned int N,
				unsigned int *buckets[10], unsigned int sizePerBucket[10], unsigned int radixPos)
{
	for (size_t i = 0; i < N; i++)
	{
		unsigned int bucketIndex = GetRadix(Array[i], radixPos);
		buckets[bucketIndex][sizePerBucket[bucketIndex]] = Array[i];
		sizePerBucket[bucketIndex]++;
	}
}

void PopToBucket(unsigned int Array[], unsigned int *buckets[10], unsigned int sizePerBucket[10])
{
	unsigned int k = 0;
	for (unsigned int i = 0; i < 10; i++)
	{
		for (unsigned int j = 0; j < sizePerBucket[i]; j++)
		{
			Array[k++] = buckets[i][j];
		}
	}
}



void TestRadixSort(unsigned int dataSize)
{
	const size_t n = dataSize;
	const unsigned int maxValue = 10000000000;
	default_random_engine e(time(0));
	uniform_int_distribution<unsigned int> u(0, maxValue);
	unsigned int *array = new unsigned int[n];
	vector<unsigned int> varry;
	for (size_t i = 0; i < n; i++)
	{
		array[i] = u(e);
		varry.push_back(array[i]);
	}
	cout << "------------------" << "Data Number:" << n << "--------------------" << endl << endl;
	cout << "------------------RadixSort--------------------" << endl;
	clock_t t1 = clock();
	RadixSort(array, n);
	clock_t t2 = clock();
	cout << "clocks: " << (t2 - t1) << endl;
	cout << "second: " << (t2 - t1) / CLOCKS_PER_SEC << endl;

	cout << "------------------StlSort--------------------" << endl;
	clock_t t3 = clock();
	sort(varry.begin(), varry.end());
	clock_t t4 = clock();
	cout << "clocks: " << (t4 - t3) << endl;
	cout << "second: " << (t4 - t3) / CLOCKS_PER_SEC << endl;
}
