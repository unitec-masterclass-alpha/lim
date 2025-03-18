#include "sort.h"

int FindMinPosition(int array[], unsigned int size){
	int minPos = 0;
	for (unsigned i=0; i<size; i++)
		if (array[i] < array[minPos])
			minPos = i;
	return minPos;

}
void Swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
}
void Sort(int array[], unsigned int size){
	if (size == 1)
		return;
	Swap(array[0], array[FindMinPosition(array, size)]);
	Sort(array + 1, size - 1);
}


