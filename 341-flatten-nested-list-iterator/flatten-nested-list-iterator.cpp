/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto rit = nestedList.rbegin(); rit != nestedList.rend(); ++rit) {
            list.push(*rit);
        }
    }

    int next() {
        int ret = list.top().getInteger();
        list.pop();
        return ret;
    }

    bool hasNext() {
        if (list.empty()) return false;

        // flatten the first element until it becomes an integer
        NestedInteger top_ele = list.top();

        if (top_ele.isInteger()) return true;

        list.pop(); // pop it out if it is not an integer
        vector<NestedInteger> top_list = top_ele.getList();
        for (auto rit = top_list.rbegin(); rit != top_list.rend(); ++rit) {
            list.push(*rit);
        }

        return hasNext();
    }
    
    stack<NestedInteger> list;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */