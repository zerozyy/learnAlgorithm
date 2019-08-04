/**
 * 插入排序
 */
void insertSort(vector<int> array)
{
    if(array.size() < 2)
        return;
    for(int i = 0;i < array.size();i++){
        for(int j = i-1;j >= 0 && array[j] > array[j+1];j--){// 将i前面的数字排序
            swap(array[j],array[j+1]);
        }
    }
}