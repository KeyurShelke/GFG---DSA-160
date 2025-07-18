class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        int a,b;
        for(auto &i: arr){
            if(i=="+" || i=="-" || i=="*" || i=="/"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                if(i=="+") st.push(b+a);
                else if(i=="-") st.push(b-a);
                else if(i=="*") st.push(b*a);
                else if(i=="/") st.push(b/a);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
        }
};