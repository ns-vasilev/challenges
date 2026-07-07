/*

11799 - Horror Dash

It is that time of the year again! Colorful balloons and brightly colored
banners spread out over your entire neighborhood for just this one occasion.
It is the annual clown’s festival at your local school. For the first time in
their lives, students from the school try their hands at being the best clown
ever. Some walk on long poles, others try to keep a crowd laughing for
the day with stage comedy, while others still try out their first juggling act
— some ‘master clowns’ even teach these juggling tricks to visitors at the
festival.

As part of the festival, there is a unique event known as the “Horror
Dash”. At this event, N (1 ≤ N ≤ 100) students dressed in the scariest
costumes possible start out in a race to catch a poor clown running on
the same track. The clown trips over, loses his mind, and does all sorts of
comical acts all while being chased round and round on the track. To keep
the event running for as long as possible, the clown must run fast enough not to be caught by any of
the scary creatures. However, to keep the audience on the edge of their seats, the clown must not run
too fast either. This is where you are to help. Given the speed of every scary creature, you are to find
out the minimum speed that the clown must maintain so as not to get caught even if they keep on
running forever.

Input
The first line of input contains a single integer T (T ≤ 50), the number of test cases. This line is
followed by T input cases. Each input case is on a single line of space-separated integers. The first
of these integers is N , the number of students acting as scary creatures. The rest of the line has
N more integers, c0, c1, . . . , cN−1, each representing the speed of a creature in meters per second
(1 ≤ ci ≤ 10000 for each i). You can assume that they are always running in the same direction on the
track.

Output
There should be a single line of output for each test case, formatted as ‘Case c: s’. Here, c represents
the serial number of the input case, starting with 1, while s represents the required speed of the clown,
in meters per second.

Sample Input
2
5 9 3 5 2 6
1 2

Sample Output
Case 1: 9
Case 2: 2

*/

#include <stdio.h>

int main() {
    int num_lines;

    scanf("%i", &num_lines);

    for (int i = 0; i < num_lines; ++i) {
        int result = 0;
        int n = 0;

        scanf("%d", &n);

        while (n--) {
            int curr = 0;

            scanf("%d", &curr);

            if (result < curr) {
                result = curr;
            }
        }

        printf("Case %d: %d\n", i + 1, result);
    }

    return 0;
}