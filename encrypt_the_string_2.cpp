//Time Complexity O(n)
//Space Complexity O(1)
class Solution{
public:
    string Hexadecimal(int n){
        string ans;
        while(n){ 
            int temp = n%16;
            n/=16;
            if(temp>=10){
                ans += (char)('a'+temp-10);
            }
            else{
                ans += (char)('0'+temp);
            }
       }
       return ans;
    }
    string encryptString(string str){
        int len = str.length();
        string ans;
        for(int i=0;i<len;i++) {
            char curr = str[i];
           int count = 0;
           while(str[i] == curr){
               count++;
               i++;
               if(i==len) break;
           }
           i--;
           ans+=curr+Hexadecimal(count);
        }
        int low = 0, high = ans.length()-1;
        while(low<high){
            swap(ans[low++], ans[high--]);
        }
        return ans;
    }
};


string hex(int n,unordered_map<int,char> &hexCodes){
        string res = "";
        while(n>0){
            int rem = n%16;
            n /= 16;
            res += hexCodes[rem];
        }
        // reverse(res.begin(),res.end());
        // I follow (lsb to msb) right to left  convention 
        return res;
    }
    string encryptString(string s) {
        // code here
        unordered_map<int,char> hexCodes;
        for(int i=0; i<10; i++){
            hexCodes[i] = char(i-0+'0');
        }
        for(int i=10; i<16; i++){
            hexCodes[i] = char(i-10+'a');
        }
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++){
            int cnt = 1;
            while(i<n-1 && s[i] == s[i+1]){
                cnt += 1;
                i += 1;
            }
            ans += s[i];
            ans += hex(cnt,hexCodes);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }





stringstream ss;
int cnt = 1;
int i = 1;
stack<pair<char, int>> sta;

while (i < S.size())
{
    if (S[i - 1] == S[i])
    {
        ++ cnt;
    }
    else
    {
        sta.push({S[i - 1], cnt});
        cnt = 1;
    }
    ++ i;
}

sta.push({S[i - 1], cnt});

while (sta.size())
{
    ss << std::hex << sta.top().second;
    ss << sta.top().first;
    sta.pop();
}

return ss.str();







//Time Complexity O(N)
//Space Complexity O(N)

class Solution{
      public:
    string encryptString(string S) {
        // code here
        map<char,int>m;
        for(int i=0;i<S.length();i++){
            m[S[i]]++;
        }
        for(auto it=m.rbegin();it!=m.rend();it++){
            printf("%x%c",(*it).second,(*it).first);
        }
    }
};