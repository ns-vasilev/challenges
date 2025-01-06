/*

790. Domino and Tromino Tiling

You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

*/

class Solution {
public:
    int numTilings(int n) {
        std::vector<unsigned int> v(n + 3);

        v[0] = 1;
        v[1] = 2;
        v[2] = 5;

        for (int i = 3; i < n; ++i) {
            v[i] = (2 * v[i - 1] + v[i - 3]) % 1000000007;
        }

        return v[n - 1];
    }
};