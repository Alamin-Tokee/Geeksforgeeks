//TC O(n)
//SC O(1)
class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i = N - 1;
        while(i > 0 && arr[i] <= arr[i-1]) i--;
        reverse(arr.begin()+i, arr.end());
        int l = i-1, r = i;
        while(l >= 0 && r < N){
            if(arr[r] > arr[l]){
                swap(arr[l], arr[r]);
                break;
            }
            r++;
        }
        return arr;
    }
};

//TC O(n)
//SC O(1)
class Solution{
public:
   vector<int> nextPermutation(int N, vector<int> arr){
       // code here
       bool done=false;
       int i=0;
       for(i=N-1;i>=1;i--){
           if(arr[i]>arr[i-1]){
               done=true;
               break;
           }
       }
       if(done){
           int l=i,h=N-1;
           while(l<=h){
               int mid=(l+h)/2;
               if(arr[mid]<arr[i-1])h=mid-1;
               else l=mid+1;
           }
           swap(arr[h],arr[i-1]);
       }
       reverse(arr.begin()+i,arr.end());
       return arr;
   }
};
