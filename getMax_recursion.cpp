#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
* 递归获取array中left-right之间的最大值
*/
int getMax(vector<int>& array, int left, int right)
{
	if (left == right)
		return array[left];
	int mid = left + (right - left) / 2;        // mid写成这样比较好，避免溢出,如果是位运算记得加括号
	int leftMax = getMax(array,left, mid);                // 左边的最大值
	int rightMax = getMax(array, mid + 1, right);        // 右边的最大值
	return max(leftMax, rightMax);
}

int main(){
	vector<int> array;
	cout << "array content :    ";
	for (int i = 0; i < 23; i++){
		array.push_back(i * 2 + 7);
		cout << array[i] << "  ";
	}
	cout << endl << "max number in array is :    "<<getMax(array,0,array.size()-1) << endl;

	system("pause");
	return 0;
}