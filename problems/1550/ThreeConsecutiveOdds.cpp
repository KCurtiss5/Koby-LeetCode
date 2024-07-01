class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCounter = 0;
        for (auto num: arr){
            if (isOdd(num)){
                oddCounter++;
                if (oddCounter == 3){
                    return true;
                }
            }
            else {
                oddCounter = 0;
            }
        }
        return false;
    }

private:
    bool isOdd(int num){
        return num & 1;
    }
};


/*
This problem is all about finding three consecutive odds. So we can use a O(n) algorithm with one pass counting the number of odds
it sees. Nothing too difficult about this problem
Runtime - 0ms Beats 100%
Memory - 10.59MB Beats 45.76%
*/