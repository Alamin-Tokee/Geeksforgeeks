class Solution {
  public:
    int count(int Arr[], int N,int value) {
        if(N<2) return 0;
        int cnt=0;
        sort(Arr,Arr+N);
        for(int i=0;i<N-2;i++){
            int num=Arr[i];
            int l=i+1;
            int r=N-1;
            while(l<r){
                int sum=num+Arr[l]+Arr[r];
                if(sum > value) {
                    r--;
                }else{
                    cnt=cnt+(r-l);
                    l++;
                }
            }
        }
        return cnt;
    }
    
    int countTriplets(int Arr[], int N, int L, int R) {
        int left=count(Arr,N,L-1);
        int right=count(Arr,N,R);
        return right - left;
    }
};