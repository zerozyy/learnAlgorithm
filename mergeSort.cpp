/*
*
* 递归：样本量发生了变化，但是过程可以复用
* 写递归时先写base case,即递归退出条件
* 压栈：父函数中所有的变量及行号信息都会压入栈，根据此信息依次返回父函数
*
*/

/**
* 归并排序：先用递归将左边的部分按顺序拍好，再将右边的部分按顺序排好
* 归并：两个下标分别指向两部分的第一个数据，选较小的入辅助空间
* 复杂度 :T{N} = 左部分T{N/2} + 右部分T{N/2} + merge O(N)
*              = 2T{N/2} + O(N)
* a = 2 ,b = 2 , d = 1 时间复杂度O(NlogN)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sortProcess(vector<int>& array, int left, int right);
void mergeSort(vector<int>& array);
void merge(vector<int>& array, int left, int mid, int right);

// 归并排序
void mergeSort(vector<int>& array)
{
	if (array.size() < 2)
		return;
	sortProcess(array, 0, array.size() - 1);
}


// 递归过程 
void sortProcess(vector<int>& array, int left, int right)
{
	if (left == right)
		return ;
    // !  位运算记得加括号
	int mid = left + ((right - left)>>1);        // mid写成这样比较好，避免溢出,位运算取代除法
	sortProcess(array, left, mid);                // 左边部分
	sortProcess(array, mid + 1, right);        // 右边部分
	merge(array, left, mid, right);            // 归并
}

/*
 * 将一个数组的两个有序的部分（两个有序数组）进行归并
 */
void merge(vector<int>& array, int left, int mid, int right)
{
	vector<int> help;
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	
	while (p1 <= mid && p2 <= right) {
		//! 注意这里的写法   array[p1] < array[p2] ? array[p1++] : array[p2++]
		//! 不能写作array[p1] < array[p2] ? array[p1] : array[p2]; p1++;p2++
		//! 二者的区别是 选中谁 谁才++ 
		help.push_back((array[p1] < array[p2] ? array[p1++] : array[p2++])); // 将较小的数存入help
		//! 等价于下面的写法
		 /*int tmp=array[p1] < array[p2] ? array[p1] : array[p2];
		 if(tmp==array[p1] ) 
			 p1++;
		 else 
			 p2++;
		 help.push_back(tmp);*/
	}
	while (p1 <= mid) {
		help.push_back(array[p1]);
		p1++;
	}
	while (p2 <= right) {
		help.push_back(array[p2]);
		p2++;
	}

	for (int j = 0; j < help.size(); j++) {
		array[left + j] = help[j];
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
	mergeSort(array);
	cout << "after sort:" << endl;
	for (int i = 0; i < array.size(); i++){
		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}