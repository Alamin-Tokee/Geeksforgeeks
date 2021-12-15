
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        queue<pair<int,long long>>q;
        vector<long long>ans;
        for(int i=0;i<N;i++){
            if(A[i] < 0) q.push({i,A[i]});
            
            if(i >= K-1){
                while(!q.empty() && q.front().first < (i-K+1)) q.pop();
                
                (q.empty()) ? (ans.push_back(0)) : (ans.push_back(q.front().second));
            }
        }
        return ans;
 }

//Time Complexity O(n)
 //Space Complexity O(k)

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        int i=0,j=0;
        queue<long long>q;
        vector<long long> result(N-K+1);
        long long index=0;
        while(j<N){
            if(A[j] < 0) q.push(A[j]);
            
            if(j-i+1 == K){
                if(q.size()==0) result[index++]=0;
                else{
                    result[index++]=q.front();
                    if(A[i]==q.front()) q.pop();
                }
                i++;
            }
            j++;
        }
        return result;
 }

 
    //  vector<long long> ans;
    //   deque<long long> dq;
    //   int i=0;
       
    //   for(; i<K; i++)
    //   {
    //         if(A[i] < 0)
    //             dq.push_back(i);
    //   }
       
       
    //   while(i<N)
    //   {
    //         if(dq.size())
    //             ans.push_back(A[dq.front()]);
    //         else
    //             ans.push_back(0);
           
    //       while(dq.size() and dq.front() <= i-K)
    //             dq.pop_front();
           
    //       if(A[i] < 0)
    //             dq.push_back(i);
                
    //       i++;
    //   }
       
    //   if(dq.size())
    //         ans.push_back(A[dq.front()]);
    //   else
    //         ans.push_back(0);
                
    //   return ans;