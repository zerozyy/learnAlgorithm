#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
* 插入排序
*/
void insertSort(vector<int>& array)
{
	if (array.size() < 2)
		return;
	for (int i = 0; i < array.size(); i++){
		for (int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--){// 将i前面的数字排序
			swap(array[j], array[j + 1]);
		}
	}
}

int main()
{
	vector<int> array;
	cout << "before sort:" << endl;
	for (int i = 15; i > 0; i--){
		array.push_back(i);
		cout << i << " ";
	}
	cout << endl << endl;
	insertSort(array);
	cout << "after sort:" << endl;
	for (int i = 0; i < array.size(); i++){
		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}