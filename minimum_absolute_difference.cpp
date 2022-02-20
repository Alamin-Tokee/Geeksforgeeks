int count(int a[],int n,int mid){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt+=upper_bound(a+i,a+n,a[i]+mid)-(a+i+1);
    }
    return cnt;
}

int kthDiff(int a[], int n, int k)
{
    sort(a,a+n);
    int low=a[1]-a[0];
    for(int i=1;i<n-1;i++){
        low=min(a[i+1]-a[i],low);
    }
    int high = a[n-1]-a[0];
    while(low<high){
        int mid = (low+high)/2;
        if(count(a,n,mid) < k){
            low = mid+1;
        }else{
            high = mid;
        }
    }
    return low;
}


    // int kthDiff(long nums[], long n, long k){
    //     sort(nums,nums+n);
    //     long lo = 0;
    //     long  hi = nums[nums.length - 1]-nums[0];
    //     while (lo < hi) {
    //         long mi = (lo + hi) / 2;
    //         int  count = 0, left = 0;
    //         for (int right = 0; right < nums.length; ++right) {
    //             while (nums[right] - nums[left] > mi) left++;
    //             count += right - left;
    //         }
    //         if (count >= k) hi = mi;
    //         else lo = mi + 1;
    //     }
    //     return lo;
    // }