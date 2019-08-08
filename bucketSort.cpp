
// 桶排序1：基于计数的排序
void bucketsort(vector<int>& arr)
{
    if(arr.size()<2)
        return;
    int max=arr[0];
    // 找最大值
    for(int i=0;i<arr.size();i++){
        max = max(max,arr[i]);
    }
    // 统计频率
    int bucket[max+1]={0};
    for(int i=0;i<arr.size();i++){
        bucket[arr[i]]++;
    }
    // 将容器中的数据倒出
    int i=0;
    for(int j=0;j<max+1;j++){
        while(bucket[j]-- > 0){
            arr[i++]=j;
        }
    }
}



// 基数排序（支持的范围更大）
// 待定