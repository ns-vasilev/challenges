/*

Gas Station

Given two integer arrays A and B of size N. There are N gas stations along a circular route, where the amount of gas at station i is A[i].

You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.

*/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
     int n = A.size();
     
     int total_tank = 0;
     int current_tank = 0;
     int start_index = 0;
     
     for (int i = 0; i < n; ++i) {
         int gain = A[i] - B[i];
         
         total_tank += gain;
         current_tank += gain;
         
         if (current_tank < 0) {
             current_tank = 0;
             start_index = i + 1;
         }
     }
     
     return (total_tank >= 0) ? (start_index % n) : -1;
}
