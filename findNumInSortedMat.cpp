/*题目：矩阵的每行和每列都是排好序的例如：
 0   1  2
 2   3  4
 4   4  4
 5   7  7
实现一个函数判断数字K是否在矩阵m中
要求时间复杂度O(N+M) 空间复杂度O(1)
思路：初始当前数指向 右上角（巧妙），将当前数与K比较
当前数<K，说明当前数前面的数不会包含K,向下移动
当前数>K，说明当前数所在列不会包含K，向左移动
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool findNumInMat(vector<vector<int>> m, int K){
	int row = 0;
	int col = m[0].size()-1;
	int endR = m.size()-1;
	int endC = 0;
	while (row <= endR && col >= endC){
		if (m[row][col] == K){
			return true;
		}
		else if (m[row][col] < K){
			row++;
		}
		else{
			col--;
		}
	}
	return false;
}
int main(){
	vector<int> tmp;
	vector<vector<int>> m;
	for (int i = 1; i < 15; i++)
		tmp.push_back(i);
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			m.push_back(tmp);
		else{
			reverse(tmp.begin(), tmp.end());
			m.push_back(tmp);
		}
	}
	cout << "matrix content is:" << endl;
	for (int i = 0; i < m.size(); i++){
		for (int j = 0; j < m[0].size(); j++){
			cout << m[i][j] << "  ";
		}
		cout << endl;
	}
	int number = 2;
	if (findNumInMat(m, number)){
		cout << number << "  is in matrix" << endl;
	}
	else{
		cout << number << "  is not in matrix" << endl;
	}

	system("pause");
	return 0;
}