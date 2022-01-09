//Time Complexity O(n)
//Space Complexity O(n)
class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) {
        // code here
        vector<int>ans;
        map<int,int>m;
        for(int i=0;i<n;i++){
            if(!m[abs(arr[i])]){
                m[abs(arr[i])]++;
            }else if(m[abs(arr[i])]){
                if(arr[i] < 0){
                    ans.push_back(arr[i]);
                    ans.push_back(abs(arr[i]));
                }else{
                    ans.push_back(-arr[i]);
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
};

class Solution{
    public:
    vector <int> findPairs(int arr[], int n) {
       // code here
       vector<int>ans;
       unordered_set<int>s;
      
       for(int i=0;i<n;i++){
           if(s.find(-1*arr[i])!=s.end()){
                 ans.push_back(min(-1*arr[i],arr[i]));
                 ans.push_back(max(-1*arr[i],arr[i]));
           }
           else{
               s.insert(arr[i]);
           }
       }
       return ans;
   }
};
