
//TC O(N*M*M)
//SC O(1)
class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
        // Your code goes here
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int cnt = 0;
                for(int row=0;row<n;row++){
                    if(matrix[row][i]==1 && matrix[row][j]==1) cnt++;
                }
                if(cnt>=2) return true;
            }
        }
        return false;
    }
};


class Solution{
   public:
   
   bool ValidCorner(const vector<vector<int> >& matrix)
   {
       /**************** Brute Force *************/
       // Your code goes here
       
       int r = matrix.size();
       int c = matrix[0].size();
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               if(matrix[i][j]==1){
                   int right,down;
                   for(right=j+1;right<c;right++){
                       if(matrix[i][right]==1){
                           for(down=i+1;down<r;down++){
                               if(matrix[down][right]==1){
                                   if(matrix[down][j]){
                                       return true;
                                   }
                               }
                           }
                       }
                   }
               }
           }
       }
       return false;
   }
};

 

/*************** Optimal Approach **************/

 

class Solution{
   public:
   
   bool ValidCorner(const vector<vector<int> >& matrix)
   {
       /**************** Optimal Approach ***********/
        int r = matrix.size();
       int c = matrix[0].size();
       unordered_map<int,unordered_set<int>> map;
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               for(int z = j+1;z<c;z++){
                   if(matrix[i][j]==1 && matrix[i][z]==1){
                       if(map.find(j)!=map.end() && map[j].find(z)!=map[j].end()){
                           return true;
                       }
                       map[j].insert(z);
                   }
               }
           }
       }
       return false;
   }
};