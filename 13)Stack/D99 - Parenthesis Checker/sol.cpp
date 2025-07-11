
class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        stack<char> stk;
        for (char ch : k) {
            if (ch == '(' || ch == '{' || ch == '[' ) {
                stk.push(ch);
            } else {
                if (stk.empty()) return false;
                char top = stk.top();
                if ((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||    
                   (ch == ']' && top != '[')) {
                       return false;
                   } 
                   stk.pop();
            }
        }
        return stk.empty();
    }
};