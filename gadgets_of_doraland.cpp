//TC O(NlogN)
//SC O(N)

class Solution{
   class Comp{
        public:
        using item = pair<int,int>;
        bool operator()(item &i1, item &i2){
            if(i1.second == i2.second) return i2.first > i1.first;
            
            return i2.second > i1.second;
        }
    };
    public:
    using item = pair<int,int>;
    vector<int> TopK(vector<int> &arr,int k){
        priority_queue<item, vector<item>, Comp>pq;
        unordered_map<int,int>mp;
        vector<int> ans;
        for(auto &num: arr){
            mp[num]++;
        }
        for(auto &pr: mp){
            pq.push({pr.first, pr.second});
        }
        while(k!=0){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
};

//TC O(N)
//SC O(N)
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        // code here
        unordered_map<int,int>m;
        for(int i=0;i<array.size();i++){
            m[array[i]]++;
        }
        
        vector<pair<int,int>> vec;
        for(auto it:m){
            vec.push_back(it);
        }
        
         sort(vec.begin(),vec.end(),[](pair<int,int>&a , pair<int,int>&b){
            if(a.second==b.second) return a.first>b.first;
            
            return a.second>b.second;    
        });
        
        vector<int> ans;
        for(int i = 0; i < k ; i++){
            ans.push_back(vec[i].first);
        }
        
        return ans;
    }
};