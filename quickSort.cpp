
/**
* 排序的稳定性：无序数组中的相同的值在排成有序数组后相对顺序不变。
* 比如 无序数组中 3 ... 3 ...3
* 排成有序后 3 3 3这三个3仍然是无序数组中的 第一个3 第二个3 第三个3，则称其为稳定的排序。
*
* 可实现为稳定得排序算法：冒泡算法、插入排序、归并排序
* 不可实现稳定的排序算法：选择排序、快速排序
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>  // 产生随机数
using namespace std;
/**
* 快排第一步：partition过程 时间复杂度O(n)
* 应用：数组分类，比如一个数组只包含0 1 2，将0放左边 1放中间 2放右边
* 将数组最后一个元素作为划分值，然后遍历数组，将每个元素cur与划分值作比较。
* 最后将划分值与大于区的第一个数交换
*/
vector<int> partition(vector<int>& array, int l, int r)
{
	int less = l - 1; //初始 小于区位于左边界的前一个
	int more = r;   //初始 大于区为与右边界,将最后一个边界值也纳入大于区。省掉一个记录划分值的变量。
	while (l < more){
		/* 将这里的判断条件改为奇偶性判断就可以实现奇偶划分 */
		if (array[l] < array[r]){ //如果cur<划分值，小于区的下一个数和cur交换，小于区向右扩大1，下标往下跳1   
			// !注意++的位置，先扩大范围 后交换
			swap(array[++less], array[l++]);
		}
		else if (array[l] == array[r]) {// 如果cur>划分值，大于区的前一个数与cur交换。大于区向左扩一个，cur停在原地继续判断
			// !注意--的位置
			swap(array[l], array[--more]);
		}
		else {   // 如果cur=划分值,直接下标往下跳1
			l++;
		}
	}
	//若一开始more=r+1则不用下面这一步。但需一个变量记录array[r]的值
	swap(array[more], array[r]); // 将大于区第一个数和划分值(即最后一个数)交换，相当于把最后一个数放到等于区。

	// 返回 等于区域的下标范围
	vector<int> res;
	res.push_back(less + 1);
	res.push_back(more);
	return res;
}

/*
* 快排：递归的将小于区的最后一个值作为划分值将小于区排序
*     ：递归的将大于区的最后一个值作为划分值将大于区排序
*      左右有序，整体有序
* 空间复杂度：最好的情况下O(log N)，每次递归都需要区分左右不分的边界
*            最差的O(N)，
* 最差 O(n^2)
*/

void quickSort(vector<int> array, int l, int r)
{
	if (l<r){
		// 常用随机快速排序 遇到划分值是否优良是一个概率事件，长期期望为O(NlogN),不能每次都击中最差的划分值。
		// 实际表现好。因为时间复杂度的常数项小，算法每一步的步骤很少，所以即使归并排序和堆排序的时间复杂度也是O(NlogN)，工程也依然选快排
		swap(array[l + rand() % (r - l + 1)], array[r]);  // 在l和r范围内随机选一个元素和最后一个数交换，即选一个数作为划分值
		// 经典快排，假设最后一个值都恰好是最大值即划分值不优良时让左部分过大或右部分过大时 则时间复杂度退化为O(n^2)
		// 最优良的时间复杂度发生在，每次的划分值恰好是平均大小时
		vector<int> p = partition(array, l, r);
		quickSort(array, l, p[0] - 1); // p[0]是等于区的下标的下边界
		quickSort(array, p[1] + 1, r); // p[1]是等于区的下标的上边界
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
	quickSort(array,0,array.size()-1);
	cout << "after sort:" << endl;
	for (int i = 0; i < array.size(); i++){
		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}
