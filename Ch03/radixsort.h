#ifndef __RADIXSORT_H__
#define __RADIXSORT_H__

// Return the radix of number at position radixPos
inline unsigned int GetRadix(unsigned int number, unsigned int radixPos)
{
	for (size_t i = 0; i < radixPos; i++)
		number /= 10;
	return number % 10;
}


// Radix Sort
void RadixSort(unsigned int Array[], const unsigned int N);
void PushToBucket(unsigned int Array[], const unsigned int N, 
					unsigned int *buckets[10], unsigned int sizePerBucket[10], unsigned int radixPos);
void PopToBucket(unsigned int Array[], unsigned int *buckets[10], unsigned int sizePerBucket[10]);

// test
void TestRadixSort(unsigned int dataSize = 100);
#endif
