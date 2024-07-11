class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;
        for (auto str: logs){
            if (str.find("../") != string::npos){
                steps = max(0, steps-1);
            }
            else if (str.find('.') == string::npos){
                steps++;
            }
        }
        return steps;
    }
};

/*
This is a bit of a weird solution. So we only need to track two operations: "../" for the parent dir and then "x/" to move to a 
child directory. We don't need to track "./". First we can check for the parent dir command. If we find it, then we know we're going
up a level or we are already there. Then if didn't find the parent dir command ("../"), we can search for a period. If found, we know
to do nothing, otherwise we know we're going a level down, hence the steps increment statement.

Runtime - 3ms Beats 86.24%
Memory - 13.89MB Beats 84.70%
*/