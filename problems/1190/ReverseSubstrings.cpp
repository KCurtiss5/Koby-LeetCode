class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> parens; //index of parentheses
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                parens.push(i);
            }
            else if (s[i] == ')'){
                reverse(s.begin()+parens.top()+1, s.begin()+i);
                s.erase(s.begin()+parens.top());
                s.erase(s.begin()+i-1);
                i -= 2;
                parens.pop();
            }
        }
        return s;
    }
};

/*
This is a simple algorithm that uses a stack to reverse parens. Wehn it finds a closing parenthesis, it reverses the letters in
between the parens, then it erases the parens it just "consumed" and backs up the for loop two spots back to where we started. 

Runtime - 0ms Beats 100.00%
Memory - 7.76MB Beats 52.67%
*/