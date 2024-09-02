class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        k %= sumVect(chalk);
        for (int i = 0; i < chalk.size(); i++){
            if (k-chalk[i] < 0){
                return i;
            }
            k -= chalk[i];
        }
        return 0;
    }

private:
    int sumVect(vector<int>& vect){
        long long sum = 0;
        for (auto each: vect){
            sum += each;
        }
        return sum;
    }
};

/*
Runtime - 95ms Beats 62.02% O(N)
Memory - 77.06MB Beats 18.08%
*/