// 应用：一个无序的数组，返回其排序后相邻两元素的最大差值，要求时间复杂度在O(N)中
// 数组 3 1  6  0，排序后0 1 3 6 返回3
int maxGap(vector<int> nums){
    if(nums.size()<2)
        return 0;
    int len=nums.size();
    int max=nums[0];
    int min=nums[0];
    for(int i=0;i<len;i++){
        min=min(min,nums[i]);
        max=max(max,nums[i]);
    }
    if(max==min)
        return 0;
    int hasNum[len+1]={0}; //桶是否空
    int maxs[len+1];        // 桶的最大值
    int mins[len+1];        // 桶的最小值
    int bid=0;
    for(int i=0;i<len;i++){
        bid = bucket(nums[i],len,min,max);
        mins[bid] = hasNum[bid]?min(mins[bid],nums[i]):nums[i];  //更新桶的最小值
        maxs[bid] = hasNum[bid]?max(maxs[bid],nums[i]):nums[i];  //更新桶的最大值
        hasNum[bid] = 1;
    }

    // 遍历非空桶，计算最大值
    int res=0;
    int lastMax=maxs[0];// 0号桶一定会有值
    int i=1;
    for(;i<=len;i++){
        if(hasNum[i]) {
            res=max(res,mins[i]-lastMax);
            lastMax=maxs[i];
        }
    }
    return res;
}

// 数值对应,计算数字放进哪个桶
int bucket(long num,long len,long min,long max)
{
    return (int)((num-min)*len/(max-min));
}