    class Solution{
    using ll = long long int;
    class Compare{
        public:
        inline bool operator()(ll &a,ll &b){
            return a > b;
        }
    };
    public:
        //TC O(n)
        //SP (1)
    // long long int maximizeSum(long long int a[], int n, int k)
    // {
    //     // Your code goes here
    //     long long int ans = 0, mn = 1e9;
    //     sort(a,a+n);
    //     for(int i=0;i<n;i++){
    //         if(a[i] < 0 && k) a[i]*=-1,k--;
    //         ans+=a[i];
    //         mn=min(mn,a[i]);
    //     }
    //     if(k & 1) ans-=2*mn;
        
    //     return ans;
    // }
    
    //TC O(nlogn)
    //SC O(n)
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        priority_queue<ll,vector<ll>,Compare>pq;
        ll ans = 0;
        for(int i=0;i<n;i++){ 
            pq.push(a[i]);
        }
        
        while(k > 0){
            if(pq.top() <= 0){
                ll minn = pq.top();
                minn = -1LL*minn;
                pq.pop();
                pq.push(minn);
                k--;
            }else break;
        }
        
        if(k > 0){
            ll minn = pq.top(); pq.pop();
            if(k%2 == 0){
                pq.push(minn);
            }else{
                pq.push(-minn);
            }
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
       return ans;
    }
};