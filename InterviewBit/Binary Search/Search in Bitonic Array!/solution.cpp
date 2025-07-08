/*

Search in Bitonic Array!

Problem Description
 
 

Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.

NOTE:

A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

*/

int find_peak(std::vector<int> &A) {
    int l = 0;
    int r = A.size() - 1;
    
    while (l < r) {
        int m = (l + r) / 2;
        
        if (A[m] > A[m + 1]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    return l;
}

int binary_search(std::vector<int> &A, int l, int r, int key) {
    while (l <= r) {
        int m = (l + r) / 2;
        
        if (A[m] == key) {
            return m;
        } else if (A[m] < key) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    
    return -1;
}

int binary_search_desc(const std::vector<int>& A, int l, int r, int key) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (A[m] == key) {
             return m;
        } else if (A[m] > key) { 
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B) {
    int peak = find_peak(A);
    
    if (A[peak] == B) {
        return peak;
    }
    
    int left = binary_search(A, 0, peak - 1, B);
    if (left != -1) {
        return left;
    }

    return binary_search_desc(A, peak + 1, A.size() - 1, B);
}
