 lass Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int hash[n+1] = {0};
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        
        int *res = new int[2];
        for(int i=1;i<=n;i++){
            if(hash[i]==2) res[0] = i;
            if(hash[i]==0) res[1] = i;
        }
        
        return res;
    }
};



class Solve {
    int *findTwoElement(int arr[], int n) {
        int *res = new int[2];
        int xy = 0;
        for(int a : arr){
            xy ^=a;
        }
        
        for(int a = 1; a <= n ; a++){
            xy ^=a;
        }
        
        int rmsb = xy & (~xy+1);
        int x = 0, y = 0;
        
        for(int a : arr){
            if((a & rmsb) == 0)
                x ^=a;
            else
                y ^=a;
        }
        
        for(int a = 1; a <=n; a++){
            if((a & rmsb) == 0)
                x ^=a;
            else
                y ^=a;
        }
        
        for(int a : arr){
            if(a == x){
                res[0] = x;
                res[1] = y;
            }
            if(a == y){
                 res[1] = x;
                res[0] = y;
            }
        }
        return res;
    }
};