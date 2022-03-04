//TC O(n)
//SC O(n)
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> A, int N){
        // code here
        vector<int> ans;
        for(int i=0;i+2<N;i++){
            if(A[i]+A[i+1] > A[i+2] && A[i]+A[i+2] > A[i+1] && A[i+1]+A[i+2] > A[i]){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
}; 

//TC O(n)
//SC O(n)
class Solution{
    public:
    bool isValid(int a,int b,int c){
        if(a+b > c && a+c > b && b+c > a) return true;
        
        return false;
    }
    vector<int> canMakeTriangle(vector<int> A, int N){
        // code here
        vector<int> ans;
        for(int i=0;i<N-2;i++){
            if(isValid(A[i],A[i+1],A[i+2])){
                ans.emplace_back(1);
            }else{
                ans.emplace_back(0);
            }
        }
        return ans;
    }
}; 