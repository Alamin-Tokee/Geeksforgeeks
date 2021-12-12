class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        
       map<int,int>mp;
       int x = 0, ans = 0;
       for(int i = 0; i < n; i++){
           mp[x]++;
           if(arr[i]) x++;
           else x--;
           ans += mp[x];
       }
      for(auto it=mp.begin();it!=mp.end();it++){
          cout<<it->first << " " << it->second << endl; 
      }
       
       return ans;
    }
};


long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        int sum = 0; long long int ans = 0;
        unordered_map<int,int> mp;
        int k = 0;//subarray of sum k
        mp[0] = 1;//assume it is there
        for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(mp.find(sum-k) != mp.end()){
                ans += mp[sum-k];
            }
            mp[sum] += 1;
        }
        return ans;
    }