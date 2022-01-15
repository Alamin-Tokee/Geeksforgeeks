//TC O(nlogn)
//SC O(n+m)

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        priority_queue<int>pq;
        
        for(auto x:a) pq.push(x);
        for(auto x:b) pq.push(x);
        
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            ans.push_back(a);
        }
        
        return ans;
    }
};

//TC O(nlogn)
//SC O(n+m)
class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        for(auto x:a) ans.push_back(x);
        for(auto x:b) ans.push_back(x);
        
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};


//TC O(n+m)
//SC O(n+m)
class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans(n+m);
        int i=0, j=0, k=0;
        while(i<n && j<m){
            ans[k++] = a[i] > b[j] ? a[i++] : b[j++];
        }
        while(i<n) ans[k++]=a[i++];
        while(j<m) ans[k++]=b[j++];
        return ans;
    }
};

//TC O(nlogn)
//SC O(n+m)
class Solution{
    void heapify(vector <int> &arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void buildHeap(vector <int> &arr, int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> c;
        for(int i=0;i<n;i++)
        {
            c.push_back(a[i]);
        }
        for(int j=0;j<m;j++)
        {
            c.push_back(b[j]);
        }
        buildHeap(c, n+m);
        return c;
    }
};