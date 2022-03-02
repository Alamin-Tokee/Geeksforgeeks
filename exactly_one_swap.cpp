//TC O(S)
//SC O(1)
class Solution{
public:
    long long countStrings(string S){
        // code here
        int N = S.length();
        int freq[26]={0};
        for(auto &ch:S){
            freq[ch-'a']++;
        }
        long long int ans = 0;
        for(auto &ch:S){
            // cout<< N-freq[ch-'a'] <<endl;
            ans += N-freq[ch-'a'];
        }
        // cout<<ans<<endl;
        ans/=2;
        //cout<<ans<<endl;
        
        for(int i=0;i<26;i++){
            if(freq[i]>=2){
                ans++;
                break;
            }
        }
        return ans;
    }
};