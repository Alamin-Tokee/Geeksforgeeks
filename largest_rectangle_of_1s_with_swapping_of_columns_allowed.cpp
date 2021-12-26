//Time Complexity O(R*(R+C))
//Space Complexity O(R*C)

class Solution{
public:	
	// Returns area of the largest rectangle of 1's
	int getMaxArea(vector<int>& a,int n){
	    sort(a.begin(),a.end());
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        ans = max(ans, a[i]*(n-i));
	    }
	    return ans;
	}
	int maxArea(vector<bool> mat[], int r, int c) {
	    // code here
	    vector<vector<int>>aux (r,vector<int>(c,0));
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            aux[i][j] = (mat[i][j]==true ? 1 : 0);
	            
	            if(i>0){
	                if(aux[i][j]) aux[i][j]+=aux[i-1][j];
	            }
	        }
	    }
	    
	    int ans = 0;
	    for(auto& x:aux){
	        ans=max(ans,getMaxArea(x,c));
	    }
	    
	    return ans;
	}

};




class Solution{
public:	
	// Returns area of the largest rectangle of 1's
	int maxArea(vector<bool> mat[], int r, int c) {
	    // code here
	    vector<vector<int>> aux(r, vector<int>(c));
	    //First row as it is
	    for(int i=0; i<c; i++)
	        aux[0][i] = mat[0][i];
	    //Rest of the array
	    for(int i=1; i<r; i++)
	    {
	        for(int j=0; j<c; j++)
	        {
	            if(mat[i][j] == 1)
	                aux[i][j] = 1 + aux[i-1][j];
	            else 
	                aux[i][j] = mat[i][j];
	        }
	    }
	    //Sorting row wise
	    for(int i=0; i<r; i++)
	        sort(aux[i].begin(), aux[i].end(), greater<int>());
	    //Calculating max area
	    int maxArea = 0;
	    for(int i=0; i<r; i++)
	    {
	        for(int j=0; j<c; j++)
	        {
	            maxArea = max(maxArea, aux[i][j]*(j+1));
	        }
	    }
	    return maxArea;
	}

};