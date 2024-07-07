class Solution {
public:
    int passThePillow(int n, int time) {
        time = time % (2 * (n-1));
        if (time < n){
            return time + 1;
        }
        time = time - n;
        return n - time - 1;
    }
};

// simplified to
class Solution {
public:
    int passThePillow(int n, int time) {
        time = time % (2 * (n-1));
        if (time < n){
            return time + 1;
        }
        return 2*n - time - 1;
    }
};

/*

Lets see the pattern when passing the pillow. Example is n=5

1 2 3 4 5 4 3 2 |  1 2 3 4 5 4 3 2 | 1 2 3 4 5 4 3 2 |

The length is 8. 2(n-1). So now we can take time mod 2(n-1) to simplify the problem.

Knowing that the pillow is somewhere here: 1 2 3 4 5 4 3 2

We can break this further down into two groups

1 2 3 4 | 5 4 3 2

and we know t is 0-8 here, so:

if t >= n:
t = t-5
ans = n-t

else:
ans = t+1

Runtime - 2ms Beats 53.64%
Memory - 6.99MB Beats 96.78%
*/