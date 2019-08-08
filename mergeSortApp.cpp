/**
* 题目：计算出每个数字前面的比它小的数字的和，返回这些和的和
* 比如：               4   1   3   5   0   6
* 前面比它小的元素的和  0   0   1   8   0   13
*              返回：  1 + 8 + 13 =  22
* 题目：求每个数组中有多少个降序对 4   1   3   5   0   6
*          降序对：4,1  4,3   4,0  1,0   3,0  5,0即求每个元素后面有多少个比它小的数字
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int  sortProcess(vector<int>& array, int left, int right);
int  merge(vector<int>& array, int left, int mid, int right);
// 归并排序改写
int solution(vector<int>& array)
{
	if (array.size() < 2)
		return 0;
	return sortProcess(array, 0, array.size() - 1);
}


// 递归过程 返回归并过程中产生的小和
int  sortProcess(vector<int>& array, int left, int right)
{
	if (left == right)
		return 0;
	int mid = left + ((right - left) >> 1);        // mid写成这样比较好，避免溢出,位运算取代除法
	return sortProcess(array, left, mid)                // 左边的小和
		+ sortProcess(array, mid + 1, right)       // 右边的小和
		+ merge(array, left, mid, right);            // 归并产生的小和
}

/*
* 将一个数组的两个有序的部分（两个有序数组）进行归并
*/
int  merge(vector<int>& array, int left, int mid, int right)
{
	vector<int> help;
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	int res = 0;
	while (p1 <= mid && p2 <= right) {
		// !在归并排序的基础上添加的一行记录和的代码
		res += array[p1] < array[p2] ? (right - p2 + 1) * array[p1] : 0;    // 存储和
		help.push_back(array[p1] < array[p2] ? array[p1++] : array[p2++]); // 将较小的数存入help
	}
	while (p1 <= mid) {
		help.push_back(array[p1]);
		p1++;
	}
	while (p2 <= right) {
		help.push_back(array[p2]);
		p2++;
	}
	for (i = 0; i < help.size(); i++) {
		array[left + i] = help[i];
	}
	return res;
}
int main()
{
	vector<int> array;
	array.push_back(4);
	array.push_back(1);
	array.push_back(3);
	array.push_back(5);
	array.push_back(0);
	array.push_back(6);
	cout << "array content:    ";
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << "  ";
	cout << endl;
	cout << "there is " << solution(array) << " descending pair in array" << endl;

	system("pause");
	return 0;
}