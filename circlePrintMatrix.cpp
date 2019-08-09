
/*转圈打印矩阵，例如矩阵 
1 2  打印结果为 1 2 4 3 
3 4
分析：如果按照下标偏移来控制打印的话太过麻烦，
所以维护2个顶点坐标，每次外围打印一圈数字。
要求空间复杂度为O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 打印边缘一圈的函数
void printpEdge(vector<vector<int>> m, int row1, int clo1, int row2, int clo2)
{
	if (row1 > row2 || clo1 > clo2){
		cerr << " row or clo wrong" << endl;
		return;
	}
	if (clo1 == clo2){
		// 列标相等 说明只有1列
		for (int i = row1; i <= row2; i++){
			cout << m[i][clo1] << " ";
		}
	}
	else if (row1 == row2){
		// 行标相等 说明只有1行
		for (int i = clo1; i <= clo2; i++){
			cout << m[row1][i] << " ";
		}
	}
	else{
		// 注意顶角4元素不要重复打印
		// 从左到右打印第row1行
		for (int i = clo1; i <= clo2; i++){
			cout << m[row1][i] << " ";
		}
		// 从上到下打印第clo2列
		for (int i = row1 + 1; i <= row2; i++){
			cout << m[i][clo2] << " ";
		}
		// 从右到左打印第row2行
		for (int i = clo2-1; i >= clo1; i--){
			cout << m[row2][i] << " ";
		}
		// 从下到上打印第clo1列
		for (int i = row2 - 1; i >= row1 + 1; i--){
			cout << m[i][clo1] << " ";
		}
	}
}

// 转圈打印矩阵
void circleMatrix(vector<vector<int>> m)
{
	if (m.empty()){
		cerr << "martix is null";
		return;
	}
	int row1 = 0; 
	int clo1 = 0;
	int row2 = m.size() - 1;
	int clo2 = m[0].size() - 1;
	while (row1 <= row2 && clo1 <= clo2){
		printpEdge(m, row1, clo1, row2, clo2);
		row1++;
		clo1++;
		row2--;
		clo2--;
	}
}

int main(){
	vector<int> tmp;
	vector<vector<int>> m;
	for (int i = 1; i < 15; i++)
		tmp.push_back(i);
	for (int i = 0; i < 4; i++)
	{
		if (i%2==0)
			m.push_back(tmp);
		else{
			reverse(tmp.begin(),tmp.end());
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
	cout << endl << "circle print result:" << endl;
	circleMatrix(m);
	system("pause");
	return 0;
}