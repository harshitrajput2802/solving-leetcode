/*
Problem: 1052. Grumpy Bookstore Owner

Problem Description:
We are given two arrays:
    customers[i] -> number of customers at minute i
    grumpy[i] -> owner is grumpy (1) or not (0)
If at any point of time,
    the owner is not grumpy then -> customers are satisfied
    If grumpy then -> customers are unsatisfied
The owner can use a secret technique for for 'minutes' consecutive minutes to become not grumpy.
Return the maximum number of satisfied customers.

So we have to utilise this time to maximum the number of satisfied customers.

Our Approach(Sliding Window):
- First we will calculate how many customers are satisfied (sum of all customers[i] when grumpy[i] == 0)
- Now we have to find a window of size 'k' that maximizes extra satisfied customers
- So we will only consider customers where grumpy[i] == 1
- Calculate the sum of first k customers which are unsatisfied(where grumpy[i] == 1) => This will be our window
- check if sum >= targetSum then increment count
- Use a loop starting from index k to the end of the array,
    add new customer if grumpy[i] == 1
    and remove old customer if grumpy[i - k] == 1 -> sliding the window
- after each slide, update the 'maxExtra' count
- At the end, total satisfied customer = base + maxExtra

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int base = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                base += customers[i];
        }
        int k = minutes;
        int extra = 0;
        for (int i = 0; i < k; i++) {
            if (grumpy[i] == 1)
                extra += customers[i];
        }
        int maxExtra = extra;
        for (int i = k; i < n; i++) {
            if (grumpy[i] == 1)
                extra += customers[i];
            if (grumpy[i - k] == 1)
                extra -= customers[i - k];
            maxExtra = std::max(maxExtra, extra);
        }
        return base + maxExtra;
    }
};