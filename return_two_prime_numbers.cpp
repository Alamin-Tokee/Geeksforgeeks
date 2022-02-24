//Time complexity O(n*logn*logn)
//Space complexity O(n)
class Solution{
public:
    bool isPrime(int n){
        if(n<=1) return false;
        if(n==2) return true;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int> primeDivision(int N){
        // code here
        int i=2;
        for(i=2;i<=sqrt(N);i++){
            if(isPrime(i) && isPrime(N-i)) break;
        }
        return {i,N-i};
    }
};

//Time complexity O(n*log(logn))
//Space complexity O(n)
int N = 10000;
vector<int>isPrime(N+5,1);
class Solution{
private:
    void sieveOfEratosthenes(){
        for(int i=2;i*i<N;i++){
            if(isPrime[i]){
                for(int j=i*i;j<N;j+=i){
                    isPrime[j] = 0;
                }
            }
        }
    }
public:
    vector<int> primeDivision(int n){
        // code here
        sieveOfEratosthenes();
        for(int i=2;i<=(n/2)+1;i++){
            if(isPrime[i] && isPrime[n-i]) return {i,n-i};
        }
        // return {i,N-i};
    }
};


//Time complexity O(n*log(logn))
//Space complexity O(n)
class Solution{
public:
    vector<int> primeDivision(int N){
        // code here
        vector<int> isPrime(N, 1);
        for(int i=2; i<sqrt(N); i++)
            for(int j=2; i*j<N; j++) 
                isPrime[i*j] = 0;
        for(int i=2; i<N; i++)
            if(isPrime[i] and isPrime[N-i]) return {i, N-i};
    }
};