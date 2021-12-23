//TC O(nlogn)
//SC O(n)
class Solution{
    public:
    void merge(int a[], int l, int m, int r)
    {
         // Your code here
        int ls=m-l+1;
        int rs=r-m;
        
        int la[ls+1];
        int ra[rs+1];
        for(int i=0;i<ls;i++){
            la[i]=a[l+i];
        }
        for(int i=0;i<rs;i++){
            ra[i]=a[m+1+i];
        }
        la[ls] = ra[rs] = INT_MAX;
        int x = 0, y = 0;
        for(int i=l;i<=r;i++){
            if(la[x] <= ra[y]) a[i] = la[x++];
            else a[i] = ra[y++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r) return;
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};


class Solution{
{
    public:
    void merge(int a[], int l, int m, int r)
    {
         // Your code here
        int ma[r-l+1];
        int i = l;
        int j = m+1;
        int x = 0;
        
        while(i <= m && j <= r){
            if(a[i] <= a[j]){
                ma[x++] = a[i++];
            }else{
                ma[x++] = a[j++];
            }
        }
        while(i <= m){
            ma[x++] = a[i++];
        }
        
        while(j <= r){
            ma[x++] = a[j++];
        }
        
        for(int i = 0, j = l; i < sizeof(ma)/sizeof(ma[0]); i++ , j++){
            a[j] = ma[i];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r) return;
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};