// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        if(e == 0) return 1.0;
        if(e<0){
            b=1/b;
            long long exp=-(long long )e;
            return powerU(b,exp);
        }
        return powerU(b,e);
    }
    private: 
    double powerU(double b, long long e){
        if(e==0) return 1.0;
        double half=powerU(b,e/2);
        
        if(e%2==0) return half*half;
        else return half*half*b;
    }
};