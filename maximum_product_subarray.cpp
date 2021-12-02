//Time Complexiy O(n)
//Space Complexity O(1)

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	   // int64_t mx = 1, mn = 1 , ans = LLONG_MIN, t;
	   // for(int i=0;i<n;i++){
	   //     t=mx;
	   //     mx=max({(int64_t)a[i], mn*a[i], mx*a[i]});
	   //     mn=min({(int64_t)a[i], mn*a[i], t*a[i]});
	   //     ans=max(ans,mx);
	   // }
	    
	   // return ans;
	   
	   long long maxp=arr[0];
       long long minp=arr[0];
       long long res=arr[0];
       for(int i=1;i<n;i++){
           if(arr[i]<0) {
               cout<< maxp << " " <<minp <<endl;
               swap(maxp,minp);
           }
           maxp=max((long long)arr[i],maxp*arr[i]);
           minp=min((long long)arr[i],minp*arr[i]);
           res=max(res,maxp);
        }
        return res;
	}
};


    long long maxProduct(vector<int> arr, int n) {
	    long long leftT=0;
	    long long rightT=0;
	    long long res=INT_MIN;
	    for(int i=0;i<n;i++){
	        leftT=(leftT!=0 ? leftT : 1)*arr[i];
	        rightT=(rightT!=0 ? rightT : 1)*arr[n-1-i];
	        res=max(res,max(rightT,leftT));
	    }
	    return res;
   }