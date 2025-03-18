#include <iostream>
#include "sort.h"

using namespace std;

int main(){
	int data[] = {5, 4, 6};
	Sort(data, 3);
	for (int i=0; i<3; i++)
		cout << data[i] << "\t";
	cout << endl;
	return 0;
}
