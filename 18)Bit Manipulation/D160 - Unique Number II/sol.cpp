class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int Xor=0;
        for(int &num:arr){
            Xor^=num;
        }
        int bitNo=(Xor)& ~(Xor-1);
        int a=Xor, b=Xor;
        for(int &num:arr){
            if(num&bitNo){
                a^=num;
            }else{
                b^=num;
            }
        }
        if(b>a) return {a,b};
        return {b,a};
    }
};