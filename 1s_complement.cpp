class Solution{ 
public:

    //Time Complexity O(n)
    //Space Complexity O(1)
    string onesComplement(string S,int N){
        //code here
        for(int i=0;i<N;i++){
            S[i] = ((S[i] == '1') ? '0' : '1');
        }
        return S;
    }
    
    string onesComplement(string s,int N){
        //code here
        for(int i =0;i<N;i++){
            s[i] = s[i]^1;
        }
        return s;
    }
    
     string onesComplement(string S,int N)
    {
        for(int i=0;i<N;S[i]=((S[i++]=='1')?'0':'1'));
        return S;    
    }
};