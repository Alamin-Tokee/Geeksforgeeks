//TC O(Nlog(Sum of weights))
//SC O(1)
class Solution {
  public:
     int countDays(int weights[],int n,int limit) {
        int days = 1;
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += weights[i];
            if(sum > limit) {
                days++;
                sum = weights[i];
            }
        }
        return days;
    }
    int leastWeightCapacity(int weights[], int N, int days) {
        // code here
        int sumWeight = 0;
        int maxWeight = 0;
        for(int i = 0; i < N; i++){
            sumWeight += weights[i];
            maxWeight = max(maxWeight, weights[i]);
        }
        int low = maxWeight;
        int high = sumWeight;
        
        while(low < high){
            int mid = (low+high) >> 1;
            if(countDays(weights, N , mid) <= days){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return high;
    }
};
