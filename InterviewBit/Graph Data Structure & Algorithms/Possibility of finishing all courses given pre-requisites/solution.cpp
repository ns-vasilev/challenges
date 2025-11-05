/*

Possibility of finishing all courses given pre-requisites

There are a total of A courses you have to take, labeled from 1 to A.
Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].
The pairs are given as two arrays B and C, where [B[i], C[i]] form a pair.

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.


Problem Constraints
1 <= A <= 105
1 <= length(B) = length(C) <= 105
1 <= B[i], C[i] <= A


Input Format
The first argument of input contains an integer A, representing the number of courses.
The second argument of input contains an integer array, B.
The third argument of input contains an integer array, C.

*/

std::vector<std::vector<int>> build_matrix(int A, std::vector<int> B, std::vector<int> C) {
    std::vector<std::vector<int>> m(A, std::vector<int>());
    
    for (int i = 0; i < B.size(); ++i) {
        m[B[i] - 1].push_back(C[i] - 1);
    }
    
    return m;
}

bool has_cycle(
    std::vector<std::vector<int>> &m, 
    std::vector<bool> &visited,
    std::vector<bool> &in_stack, 
    std::vector<int> &res, 
    int v
) {
    if (in_stack[v]) { return true; }
    if (visited[v]) { return false; }
    
    in_stack[v] = true;
    visited[v] = true;
    
    for (auto &u: m[v]) {
        if (has_cycle(m, visited, in_stack, res, u)) {
            return true;
        }
    }
    
    in_stack[v] = false;
    
    res.push_back(v);
    
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    std::vector<std::vector<int>> m = build_matrix(A, B, C);
    std::vector<bool> in_stack(A, false);
    std::vector<bool> visited(A, false);
    std::vector<int> order;
    
    bool res = false;
    
    for (int v = 0; v < A; ++v) {
        if (!visited[v] && has_cycle(m, visited, in_stack, order, v)) {
            res = true;
            break;
        }
    }
    
    return res ? 0 : 1;
}
