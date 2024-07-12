class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        int recent_score = -1; //will be overriden anyways
        while (recent_score != 0) {
            if (x > y) { recent_score = checkStrings(s,"ab", "ba", x, y); }
            else { recent_score = checkStrings(s, "ba", "ab", y, x); }
            score += recent_score;
        }
        return score;
    }

private:
    void removeSubstring(string& s, size_t pos) {
        s.erase(pos, 2); //2 because its always "ab" or "ba"
    }

    int checkStrings(string& s, string first, string second, int fval, int sval) {
        size_t find = s.find(first);
        if (find != string::npos) {
            removeSubstring(s, find);
            return fval;
        }
        else if ( (find = s.find(second)) != string::npos) {
            removeSubstring(s, find);
            return sval;
        }
        else {
            return 0;
        }
    }
};

/*
This was my first attempt. It technically works, however it fails as a submission because time exceeded. This is because s.find()
is linear and.. ultimately.. too slow.

So we need a better solution that is less reliant on the string.find() function.
*/