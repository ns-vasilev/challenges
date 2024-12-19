/*

2336. Smallest Number in Infinite Set

You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

- SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
- int popSmallest() Removes and returns the smallest integer contained in the infinite set.
- void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.

*/

class SmallestInfiniteSet {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::set<int> s;

    int curr;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        int val;

        if (!pq.empty() && pq.top() < curr) {
            val = pq.top();
            pq.pop();
            s.erase(val);
            return val;
        } else {
            val = curr;
            curr++;
        }

        return val;
    }
    
    void addBack(int num) {
        if (num < curr && s.find(num) == s.end()) {
            s.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */