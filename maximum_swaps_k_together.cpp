           
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int window_size=0;
        int swaps=0;
        int res=INT_MAX;
        for(int i=0;i<n;i++){
           if(arr[i] <= k) window_size++;
        }
        int wS = 0;
        int wE = 0;
        while(wE < window_size){
            if(arr[wE] > k) swaps++;
            wE++;
        }
        res=swaps;
        while(wE < n){
            if(arr[wS] > k) swaps--;
            if(arr[wE] > k) swaps++;
            res=min(res,swaps);
            wE++;
            wS++;
        }
        return res;
    }
};