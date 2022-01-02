  class Solution{
  public:
    int kThSmallestFactor(int N , int K) {
        // code here
        for(int i=1;i<=N;i++){
            if(N%i==0 && --K==0) return i;
        }
        return -1;
    }
};