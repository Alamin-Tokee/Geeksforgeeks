//Time Complexity O(4^N*N)
//Space Complexity O(N)

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int i,string res,unordered_map<int,string>mp,int a[],int N,vector<string> &ans){
        if(i>=N){
            ans.push_back(res);
        }
        int key=a[i];
        for(char ch:mp[key]){
            res+=ch;
            solve(i+1,res,mp,a,N,ans);
            res.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N){
        //Your code here
        unordered_map<int,string>mp;
        mp[1]="";
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        mp[10]="*";
        mp[11]="0";
        mp[12]="#";
        string res="";
        vector<string>ans;
        
        solve(0,res,mp,a,N,ans);
        
        return ans;
    }
};


//Time Complexity O(4^N*N)
//Space Complexity O(N)

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(unordered_map<int,vector<char>> &mp,int a[],int n,int index,string res,vector<string>&ans){
        if(index==n){
            ans.push_back(res);
        }
        auto v=mp[a[index]];
        for(int i=0;i<v.size();i++){
            solve(mp,a,n,index+1,res+v[i],ans);
        }
    }
    vector<string> possibleWords(int a[], int N){
        //Your code here
        unordered_map<int,vector<char>>mp;
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        
        vector<string>ans;
        solve(mp,a,N,0,"",ans);
        
        return ans;
    }
};

//Time Complexity O(4^N*N)
//Space Complexity O(N)
class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N){
        //Your code here
        unordered_map<int,vector<string>>mp;
        mp[2] = {"a", "b", "c"};  
        mp[3] = {"d", "e", "f"};   
        mp[4] = {"g", "h", "i"};   
        mp[5] = {"j", "k", "l"};       
        mp[6] = {"m", "n", "o"};
        mp[7] = {"p", "q", "r", "s"};
        mp[8] = {"t", "u", "v"};
        mp[9] = {"w", "x", "y", "z"};
        
        vector<string>first=mp[a[0]];
        for(int i=1;i<N;i++){
            vector<string>second=mp[a[i]],ans;
            for(auto f:first){
                for(auto s:second)
                    ans.push_back(f+s);
            }
            first=ans;
        }
        
        return first;
    }
};