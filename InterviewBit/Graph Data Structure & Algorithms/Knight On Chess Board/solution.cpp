/*

Knight On Chess Board

Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.

If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.

*/

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    if (C == E && D == F) { return 0; }
    if (C < 1 || C > A) { return -1; }
    if (D < 1 || D > B) { return -1; }
    
    std::vector<std::vector<bool>> visited(A + 1, std::vector<bool>(B + 1, false));
    
    std::queue<std::pair<int, int>> q;
    q.push({ C, D });
    
    visited[C][D] = true;
    
    int cnt = 0;
    
    std::vector<std::vector<int>> movements = {
        { 2, 1 }, { 2, -1 }, { 1, 2 }, { -1, 2 },
        { -2, 1 }, { -2 , -1 }, { 1, -2 }, { -1, -2 }
    };
    
    while (!q.empty()) {
        int size = q.size();
        
        cnt++;
        
        while (size--) {
            auto [r, c] = q.front();
            q.pop();
                        
            for (auto movement: movements) {
                int new_r = r + movement[0];
                int new_c = c + movement[1];
                
                if (new_r == E && new_c == F) {
                    return cnt;
                }
                
                if (new_r >= 1 && new_r <= A && new_c >= 1 && new_c <= B && !visited[new_r][new_c]) {
                    visited[new_r][new_c] = true;
                    q.push({ new_r, new_c });
                }
            }
        }
    }
    
    return -1;
}
