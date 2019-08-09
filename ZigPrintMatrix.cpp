/*之字形打印矩阵，比如一个矩阵：
 1  2   3
 4  5   6
 7  8   9
 打印结果是1  4  2  3  5  7  8  6 9
 空间复杂度O(1)
 思路，每次打印一条对角线的元素 printDiaLine
 维护一条对角线的两个顶点坐标(row1,clo1,row2,clo2),并用一个表标识从上打印还是从下打印*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printDiaLine(vector<vector<int>> m, int row1, int clo1, int row2, int clo2, bool fromUp)
{
	/* 自己的实现 
	if (fromUp){
		// 从上向下打印对角线的元素
		// (row1,clo1)-->(row2,clo2)
		int row = row1;
		int clo = clo1;
		while (row <= row2 && clo >= clo2){
			cout << m[row][clo] << "  ";
			row++;
			clo--;
		}
	}
	else{
		// 从下向上打印对角线的元素
		// (row2,clo2)-->(row1,clo1)
		int row = row2;
		int clo = clo2;
		while (row >= row1 && clo <= clo1){
			cout << m[row][clo] << "  ";
			row--;
			clo++;
		}
	}*/
	/* 左程云的实现 */
	if (fromUp){
		while (row1 <= row2){
			cout << m[row1++][clo1--] << "  ";
		}
	}
	else{
		while (row2 != row1){
			cout << m[row2--][clo2++] << "  ";
		}
	}
}

void zPrintDiaLine(vector<vector<int>> m)
{
	if (m.empty()){
		cerr << "matrix is null" << endl;
		return;
	}
	int row1 = 0;
	int clo1 = 0;
	int row2 = 0;
	int clo2 = 0;
	bool fromUp = true;
	/* 自己的实现
	while ((row1 <= m.size()-1 && clo1 <= m[0].size() - 1)){// 至对角线的两个顶点都到了矩阵右下角顶点为止
		printDiaLine(m, row1, clo1, row2, clo2, fromUp);
		fromUp = (!fromUp);
		// (row1,clo1) 只要没到最后一列 就继续想右移动，如果到了最后一列就向下移动
		if (clo1 < m[0].size()-1){
			clo1++;
		}
		else{
			row1++;
		}
		// (row2,clo2) 只要没到最后一行 就继续想下移动，如果到了最后一行就向右移动
		if (row2 < m.size()-1){
			row2++;
		}
		else{
			clo2++;
		}
	}*/
	/* 左程云的实现 */
	int endR = m.size() - 1;
	int endC = m[0].size() - 1;
	while (row1 != endR + 1){
		printDiaLine(m, row1, clo1, row2, clo2, fromUp);
		row1 = clo1 == endC ? row1 + 1:row1;
		clo1 = clo1 == endC ? clo1 : clo1 + 1;
		clo2 = row2 == endR ? clo2 + 1: clo2;
		row2 = row2 == endR ? row2 : row2 + 1;
		fromUp = !fromUp;
	}
	
}

int main(){
	vector<int> tmp;
	vector<vector<int>> m;
	for (int i = 1; i < 7; i++)
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
	cout << endl << "Z print result:" << endl;
	zPrintDiaLine(m);
	system("pause");
	return 0;
}