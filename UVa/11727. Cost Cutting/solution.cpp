/*

11727 - Cost Cutting

Company XYZ have been badly hit by recession and is taking
a lot of cost cutting measures. Some of these measures include
giving up oﬃce space, going open source, reducing incentives,
cutting on luxuries and issuing pink slips.
They have got three (3) employees working in the accounts
department and are going to lay-oﬀ two (2) of them. After a
series of meetings, they have decided to dislodge the person
who gets the most salary and the one who gets the least. This
is usually the general trend during crisis like this.
You will be given the salaries of these 3 employees working
in the accounts department. You have to find out the salary
of the person who survives.

Input
The first line of input is an integer T (T < 20) that indicates the number of test cases. Each case
consists of a line with 3 distinct positive integers. These 3 integers represent the salaries of the three
employees. All these integers will be in the range [1000, 10000].

Output
For each case, output the case number followed by the salary of the person who survives.

Sample Input
3
1000 2000 3000
3000 2500 1500
1500 1200 1800

Sample Output
Case 1: 2000
Case 2: 2500
Case 3: 1500

*/

#include <stdio.h>

int main() {
    int k = 0;
    int case_num = 1;

    if (scanf("%d", &k) != 1) {
        return 0;
    }

    while (k != 0) {
        int a, b, c;
        int survivor;

        scanf("%d %d %d", &a, &b, &c);

        if ((a > b && a < c) || (a < b && a > c)) {
            survivor = a;
        } else if ((b > a && b < c) || (b < a && b > c)) {
            survivor = b;
        } else {
            survivor = c;
        }

        printf("Case %d: %d\n", case_num, survivor);

        case_num++;
        k--;
    }

    return 0;
}