/*

Bulbs

N light bulbs are connected by a wire.

Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.

Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.

You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.

*/

int Solution::bulbs(vector<int> &A) {
    int p = 0;
    int f = 0;
    
    for (int bulb: A) {
        int c = bulb ^ f;
        
        if (c == 0) {
            p++;
            f ^= 1;
        }
    }
    
    return p;
}
