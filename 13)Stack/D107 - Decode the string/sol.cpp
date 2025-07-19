
class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string> strStack;
        stack<int> countStack;
        string curr="";
        int num=0;
        
        for(char ch:s){
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }
            else if(ch=='['){
                countStack.push(num);
                strStack.push(curr);
                num=0;
                curr="";
            }
            else if(ch==']'){
                string temp=curr;
                curr=strStack.top();
                strStack.pop();
                int repeat=countStack.top();
                countStack.pop();
                while(repeat--) curr +=temp;
            }else{
                curr +=ch;
            }
        }
        return curr;
    }
};