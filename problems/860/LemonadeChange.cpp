class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cash_register[3] = {0};
        for (auto bill: bills){
            if (bill == 5) cash_register[0]++;
            else if (bill == 10) cash_register[1]++;
            else cash_register[2]++;

            int change = max(bill-5, 0);

            while(change >= 20 && cash_register[2] > 0){
                change -= 20;
                cash_register[2]--;
            }
            while(change >= 10 && cash_register[1] > 0){
                change -= 10;
                cash_register[1]--;
            }
            while(change >= 5 && cash_register[0] > 0){
                change -= 5;
                cash_register[0]--;
            }
            if(change != 0) return false;
        }
        return true;
    }
};

/*
This is my first attempt and is a very naive solution. Turns out, we dont need to keep track of 20s at all, since customers will only give
up to 20 dollar bills. The change can only be 15, 5 and 0.
74ms Beats 48.46%
85.98MB Beats 50.86%
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cash_register[2] = {0};
        for (auto bill: bills){
            if (bill == 5) cash_register[0]++;
            else if (bill == 10) cash_register[1]++;

            int change = bill-5;

            if (change == 0) continue;

            else if (change == 15 && cash_register[1] >= 1){
                change -= 10;
                cash_register[1]--;
            }
            cash_register[0] -= change/5;
            if(cash_register[0] < 0) return false;
        }
        return true;
    }
};

/*
This is a better solution. It doesn't keep track of 20s at all and it utilizes the fact that change can only be 15, 5, or 5 to avoid
while loops. Assuming you can make perfect change, revenue calculation is easy. bills.size() * 5;
Runtime
70ms - Beats 67.05% O(N)
Memory - 86.09MB Beats 32.71%
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for (int bill : bills) {
            if (bill == 5) {
                fives++;
            } else if (bill == 10) {
                tens++;
                fives--;
            } else { //we have a 20
                if (tens > 0) {
                    tens--;
                    fives--;
                } else {
                    fives -= 3;
                }
            }
            if (fives < 0) return false; // Not enough $5 bills to give change
        }
        return true;
    }
};

/*
I figured I could improve readability. So I used two variables representing fives and tens.
*/