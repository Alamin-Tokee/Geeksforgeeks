//O(2^n)
//O(2^n*length of each subset)

class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        //code here
        vector<vector<int>> ans = {{}};
        vector<int>temp;
        for (int num : nums) 
        {
            int n = ans.size();
            for (int i = 0; i < n; i++) 
            {
                temp = ans[i];
                temp.push_back(num);
                ans.push_back(temp);
                // ans.push_back(ans[i]); 
                // ans.back().push_back(num);
            }
        }
        sort (ans.begin(), ans.end());
        return ans;
    }
};

//O(2^n)
//O(2^n*length of each subset)
class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        //code here
        vector<vector<int>>ans;
        int n = nums.size();
        for (int i=0;i<(1<<n);i++){
            vector<int>subset;
            for (int j = 0; j < n; j++){
                if(i & (1<<j)){
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        sort (ans.begin(), ans.end());
        return ans;
    }
};

//O(2^n)
//O(2^n*length of each subset)
class Solution
{
    public:
    vector<vector<int>>res;
    vector<int>curr;
    void backtrack(vector<int>&nums, int i,int n){
        if(i>=n){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums,i+1,n);
        curr.pop_back();
        backtrack(nums,i+1,n);
    }
    vector<vector<int> > subsets(vector<int>& nums){
        int n = nums.size();
        backtrack(nums, 0 , n);
        sort(res.begin(),res.end());
        return res;
    }
};

//O(2^n)
//O(2^n*length of each subset)
class Solution
{
    public:
    vector<vector<int>>res;
    void backtrack(vector<int>&nums, int i,vector<int>temp){
        if(i>=nums.size()){
            res.push_back(temp);
            return;
        }
        backtrack(nums,i+1,temp);
        temp.push_back(nums[i]);
        backtrack(nums,i+1,temp);
    }
    vector<vector<int> > subsets(vector<int>& nums){
        vector<int>temp;
        backtrack(nums, 0 , temp);
        sort(res.begin(),res.end());
        return res;
    }
};

//O(2^n)
//O(2^n*length of each subset)
class Solution{
    public:
    vector<vector<int>>res;
    void backtrack(vector<int>&nums, int i,vector<int>&temp){
        res.push_back(temp);
        for(int k = i; k < nums.size(); k++){
            temp.push_back(nums[k]);
            backtrack(nums,k+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int>& nums){
        vector<int>temp;
        backtrack(nums, 0 , temp);
        sort(res.begin(),res.end());
        return res;
    }
};


//O(2^n)
//O(2^n*length of each subset)
class Solution{
private:
    void backtrack(vector<int>& A,int i,vector<vector<int>>& result,vector<int>& temp){
        if(i>=A.size()) return;
        
        for(int j=i;j<A.size();j++){
            temp.push_back(A[j]);
            result.push_back(temp);
            backtrack(A,j+1,result,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>> result={{}};
        vector<int> temp;
        backtrack(A,0,result,temp);
        // cout<<result[4][0]<<endl;
        sort(result.begin(),result.end());
        return result;
    }
};