class Solution
{
    private:
    vector<int> getLongestPrefix(string p){
        vector<int> arr(p.length(), 0);
        int i = 0, j = 1, l = p.length();
        while(j < l){
            if(p[i] == p[j]){
                arr[j] = arr[i] + 1;
                i++;
                j++;
            }else{
                if(i == 0) j++;
                else i = arr[i-1];
            }
        }
        return arr;
    }
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int> lps = getLongestPrefix(pat) , ans;
            int i = 0, j = 0, n = txt.length(), m = pat.length();
            while(i < n){
                if(pat[j] == txt[i]){
                    i++;
                    j++;
                }else{
                    if(j != 0) j = lps[j - 1];
                    else i = i + 1;
                }
                
                if(j == m){
                    ans.push_back(i-j+1);
                }
            }
            return ans;
        }
     
};