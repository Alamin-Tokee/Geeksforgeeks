//Time Complexity O(N^2)
//Space Complexity O(N)
class Solution {
  public:
    double findSlope(pair<int,int> &p1, pair<int,int>& p2){
        double x1 = p1.first;
        double x2 = p2.first;
        double y1 = p1.second;
        double y2 = p2.second;
        return (y2-y1)/(x2-x1);
    }
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int ans = INT_MIN;
        for(int i = 0; i < N-1; i++){
            unordered_map<double, int> mp;
            int cnt = 0;
            for(int j = i+1; j < N; j++){
                if(arr[i]==arr[j]){
                    cnt++;continue;
                }
                double val = findSlope(arr[i], arr[j]);
                mp[val]++;
            }
            for(auto &e:mp){
                ans = max(ans,e.second+cnt);
            }
        }
        return ans+1;
    }
};


class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int ans = 0;
        for(int i = 0; i < N; i++){
            int x1 = arr[i].first;
            int y1 = arr[i].second;
            int cnt = 0;
            unordered_map<double,int>mp;
            for(int j = 0; j < N; j++){
                int x2 = arr[j].first;
                int y2 = arr[j].second;
                if(x2==x1 && y2==y1){
                    cnt++;continue;
                }else{
                    double slope = (double)(y2-y1)/(double)(x2-x1);
                    mp[slope]++;
                }
            }
            for(auto p:mp){
                ans = max(ans,p.second+cnt);
            }
        }
        return ans;
    }
};

class Solution {
  public:
   int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int ans = 0;
        for(int i = 0; i < N; i++){
            int same = 0;
            map<pair<int,int>, int> mp;
            for(int j = i; j < N; j++){
                int dy = arr[j].second - arr[i].second;
                int dx = arr[j].first - arr[i].first;
                if(dy == 0 && dx == 0){
                    same++;
                }
                else{
                    int gcd = __gcd(dx, dy);
                    dx/=gcd;
                    dy/=gcd;
                    mp[{dy, dx}]++;
                }
            }
            for(auto &p: mp){
                ans = max(ans, p.second + same);
            }
        }
        return ans;
    }
};

// 0 0 0 0 0
// 0 0 0 0 0 
// 0 0 0 0 0
// 0 0 0 0 0 

// {{1, 2}, {2, 3}, {3, 4}}
