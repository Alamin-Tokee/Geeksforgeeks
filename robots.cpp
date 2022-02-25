// class Solution{   
// public:
//     string moveRobots(string s1, string s2){
//         // code here 
//         int n = s1.size();
        
//         int i = 0, j = 0;
//         while(i < n){
//             if(s1[i]=='#') continue;
//             while(s2[j]=='#') j++;
//             if(s1[i]!=s2[j]) return "No";
//         }
//         return "Yes";
//     }
    
//     // s1 = #B#A# i < j
//     // s2 = ##BA# 
    
//     // s1 = #B#A#
//     // s2 = #A#B# 
    
//     // ###A##B## i > j
//     // ##A##B###
    
//     // ####A###B#### i < j
//     // ######A#####B
    
//     // #####B######A### i > j
//     // ###B######A#####
// };

//TC O(|S|)
//SC O(|S|)
class Solution{   
public:
    string moveRobots(string s1, string s2){
        int n = s1.size();
        int i = 0, j = 0;
        while(i < n && j < n){
            if(s1[i] == '#') i++;
            else if(s2[j] == '#') j++;
            else if(s1[i] != s2[j]) return "No";
            else if(s1[i] == 'B' and i > j) return "No";
            else if(s1[i] == 'A' and i < j) return "No";
            else i++, j++;
        }
        return "Yes";
    }
};

//TC O(|S|)
//SC O(|S|)
class Solution{   
public:
    string moveRobots(string s1, string s2){
        int n = s1.size();
        int i = 0, j = 0;
        while(i < n && j < n){
            while(s1[i] == '#') i++;
            while(s2[j] == '#') j++;
            if(i < n and j < n) {
                if((s1[i] != s2[j]) or (s1[i] == 'A' and i < j) or (s1[i] == 'B' and i > j)) 
                    return "No";
            }
        }
        while(i<n) if(s1[i++]!='#') return "No";
        while(j<n) if(s2[j++]!='#') return "No";
        return "Yes";
    }
};

//TC O(|S|)
//SC O(|S|)
class Solution{
public:
   string moveRobots(string s1, string s2){
       stack<pair<char,int>> st ;
       
       int n = s1.size() ;
       
       for(int i=0;i<n;i++)
       {
           if(s2[i]!='#')
               st.push({s2[i],i}) ;
       }
       
       for(int i=n-1;i>=0;i--)
       {
           if(s1[i]=='#')
               continue ;
           
           if(st.empty() || s1[i]!=st.top().first)
               return "No" ;
           
           if(s1[i]=='A' && st.top().second<=i)
               st.pop() ;
           if(s1[i]=='B' && st.top().second>=i)
               st.pop() ;
       }
       
       if(st.empty())
           return "Yes" ;
           
       return "No" ;
       // code here 
   }
};