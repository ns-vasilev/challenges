/*

Max Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]

*/

int Solution::maxProduct(const vector<int> &nums) {
        int res = nums[0];

        int max_n = res;
        int min_n = res;

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            if (num < 0) {
                std::swap(max_n, min_n);
            }

            max_n = std::max(max_n * num, num);
            min_n = std::min(min_n * num, num);

            res = std::max(res, max_n);
        }

        return res;
}
