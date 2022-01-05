class Solution{
public:
    
// TC O(n)
//SC O(1)
    // void binSort(int A[], int N)
    // {
    //   //Your code here
       
    //   /**************
    //     * No need to print the array
    //     * ************/
    //     int k=0;
    //     for(int i=0;i<N;i++){
    //         if(A[i]==0){
    //             A[k]=0;
    //             k++;
    //         }
    //     }
        
    //     for(int i=k;i<N;i++){
    //         A[i]=1;
    //     }
    // }
    
// TC O(n)
//SC O(1)
    // void binSort(int A[], int N)
    // {
    //   int j = 0;
    //   for(int i = 0; i<N; i++){
    //       if(A[i]==0){
    //           swap(A[i],A[j++]);
    //       }
    //   }
    // }
// TC O(n)
//SC O(1)
     void binSort(int A[], int N)
    {
       for(int i = 0, j = 0; i<N; i++){
           if(A[i]==0){
               swap(A[i],A[j++]);
           }
       }
    }
};