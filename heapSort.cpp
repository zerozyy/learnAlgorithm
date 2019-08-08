// 堆是完全二叉树：满二叉树或者在到达满二叉树的路上
// 堆排序实际上使用数组来存储完全二叉树
// i节点：左孩子i*2+1  右孩子i*2+2  父节点(i-1)/2 通过下标计算可以直接访问左右孩子及父
/*
* 大根堆结构：对整个树而言整个堆的最大值是堆的头结点，对于每一个子树而言它的头结点也是该子树的最大值
* 小根堆结构：对整个树而言整个堆的最小值是堆的头结点，对于每一个子树而言它的头结点也是该子树的最小值
* 建造大根堆的过程：通过自己的下标计算父节点下标，与父节点比大小：若比父小，不操作；若比父大，与父交换，来到父的位置后再与新位置的父比，若大若小进行操作。
*/
// 非递归实现 空间复杂度O(1)
/*
* 每次调整只看一条路径,即二叉树的高度，所以时间复杂度O(log N)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void heapInsert(vector<int>& arr, int index);
void heapify(vector<int>& arr, int index, int heapSize);
void heapSort(vector<int>& arr);

void heapSort(vector<int>& arr)
{
	if (arr.size()<2)
		return;

	// 堆和堆排序的解耦
	// 构造大根堆，但是该堆可能无序  往上走
	// 建立大根堆的时间复杂度：log1+log2+log3...+logN = O(N)
	for (int i = 0; i < arr.size(); i++) {
		heapInsert(arr, i);
	}
	int size = arr.size();

	// 0位置上的数(最大值) 和最后一个位置上的数进行交换
	swap(arr[0], arr[--size]);

	// 不断调整这个堆直至都排好     往下走
	// 调整的过程是O(NlogN)
	while (size>0) {
		heapify(arr, 0, size);        // 调整堆
		swap(arr[0], arr[--size]);  // 把最大值往后放
	}
}
// 构造大根堆
void heapInsert(vector<int>& arr, int index)
{
	while (arr[index] > arr[(index - 1) / 2]){ // 如果大于我父
		swap(arr[index], arr[(index - 1) / 2]);  // 和我父进行交换
		index = (index - 1) / 2;              // 作为新的节点，进行下一轮比对
	}
}

// 调整堆
void heapify(vector<int>& arr, int index, int heapSize)
{
	// 和自己的左右孩子进行比较，若比孩子小就和孩子交换
	int left = index * 2 + 1;//左孩子，左孩子 + 1即为右孩子
	while (left<heapSize) {
		// 不越界,largest等于较大的孩子的下标
		int largest = left + 1 < heapSize && arr[left + 1] >arr[left]
			? left + 1
			: left;
		largest = arr[largest] > arr[index] ? largest : index;
		if (largest == index)
			break;
		swap(arr[largest], arr[index]);
		// 进行下一轮
		index = largest;
		left = index * 2 + 1;
	}
}

int main()
{
	vector<int> array;
	cout <<"before sort:"<< endl;
	for (int i = 15; i > 0; i--){
		array.push_back(i);
		cout << i << " ";
	}
	cout << endl << endl;
	heapSort(array);
	cout << "after sort:" << endl;
	for (int i = 0; i < array.size(); i++){
		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}