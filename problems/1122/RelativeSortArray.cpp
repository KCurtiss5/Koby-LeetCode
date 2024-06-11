class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> ordering;
        for (int i = 0; i < arr2.size(); i++){
            ordering[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&ordering](int a, int b){
            bool a_in_ordering = ordering.count(a) > 0;
            bool b_in_ordering = ordering.count(b) > 0;
            if (a_in_ordering && b_in_ordering) {
                return ordering[a] < ordering[b];
            }
            else if (a_in_ordering) {
                return true;
            }
            else if (b_in_ordering) {
                return false;
            }
            return a < b;
        });
        return arr1;
    }
};

/*
Creates a map with the order of how numbers appear in arr2. This allows us to create a custom sorting function that sorts every
element in arr1 by its position in arr2. Unfortunately there's lots of if cases because we have to deal with numbers not in arr2.
Runtime - 4ms Beats 39.79% of users with C++
Memory - 11.27MB Beats 6.16% of users with C++
*/
