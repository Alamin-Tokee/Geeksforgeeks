
//TC O(n)
//SC O(26)
int remAnagram(string str1, string str2)
{
// Your code goes here
     int a[26]={0}, b[26]={0}, count=0;
     
     for(int i=0;i<str1.size();i++) a[str1[i]-97]++;
     for(int i=0;i<str2.size();i++) b[str2[i]-97]++;
     
     for(int i=0;i<26;i++) count+=abs(a[i]-b[i]);
     
     return count;
}

//TC O(n)
//SC O(26)

int remAnagram(string str1, string str2)
{
// Your code goes here
     int a[26]={0}, count=0;
     
     for(int i=0;i<str1.size();i++) a[str1[i]-'a']++;
     for(int i=0;i<str2.size();i++) a[str2[i]-'a']--;
     
     for(int i=0;i<26;i++) count+=abs(a[i]);
     
     return count;
}


//TC O(n)
//SC O(n)
int remAnagram(string str1, string str2)
{
// Your code goes here
     map<int,int>m; int count=0;
     
     for(int i=0;i<str1.size();i++) m[str1[i]-'a']++;
     for(int i=0;i<str2.size();i++) m[str2[i]-'a']--;
     
     for(auto it=m.begin();it!=m.end();it++){
         if(it->second != 0){
             count += abs(it->second);
         }
     }
     
     return count;
}
