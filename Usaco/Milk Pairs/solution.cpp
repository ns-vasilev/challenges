/*

USACO 2016 February Contest, Bronze

Problem 1. Milk Pails

Farmer John has received an order for exactly M units of milk (1≤M≤1,000) that he needs to fill right away. Unfortunately, his fancy milking machine has just become broken, and all he has are three milk pails of integer sizes X, Y, and M (1≤X<Y<M). All three pails are initially empty. Using these three pails, he can perform any number of the following two types of operations:
- He can fill the smallest pail (of size X) completely to the top with X units of milk and pour it into the size-M pail, as long as this will not cause the size-M pail to overflow.

- He can fill the medium-sized pail (of size Y) completely to the top with Y units of milk and pour it into the size-M pail, as long as this will not cause the size-M pail to overflow.

Although FJ realizes he may not be able to completely fill the size-M pail, please help him determine the maximum amount of milk he can possibly add to this pail.

INPUT FORMAT (file pails.in):

The first, and only line of input, contains X, Y, and M, separated by spaces.
OUTPUT FORMAT (file pails.out):

Output the maximum amount of milk FJ can possibly add to the size-M pail.
SAMPLE INPUT:

17 25 77
SAMPLE OUTPUT:

76
In this example, FJ fills the pail of size 17 three times and the pail of size 25 once, accumulating a total of 76 units of milk.

Problem credits: Brian Dean

*/

#include <bits/stdc++.h>

int main() {
    std::ifstream fin("pails.in");
    std::ofstream fout("pails.out");

    int X, Y, M;

    if (!(fin >> X >> Y >> M)) {
        return 0;
    }

    int max_milk = 0;

    for (int i = 0; i * Y <= M; ++i) {
        int remaining_space = M - (Y * i);
        int num_X = remaining_space / X;

        int current_total = (i * Y) + (num_X * X);

        if (current_total > max_milk) {
            max_milk = current_total;
        }
    }

    fout << max_milk << std::endl;

    return 0;
}