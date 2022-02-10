class Solution{
public:
    int xorCal(int k){
        // code here
        if(k==1)return 2;
        return (k&(k+1))==0? (k/2): -1;
    }
};