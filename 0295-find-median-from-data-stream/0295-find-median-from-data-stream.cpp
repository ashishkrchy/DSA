#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


using pii = pair<int,int>;

using ordered_multiset = tree<
    pii,
    null_type,
    less<pii>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

class MedianFinder {
public:
    ordered_multiset st;
    int id;

    MedianFinder() : id(0) {}

    void addNum(int num) {
        st.insert({num, id++});
    }

    double findMedian() {
        int n = (int)st.size();
        if (n == 0) return 0.0; 

        if (n % 2 == 1) {
            
            auto it = st.find_by_order(n / 2);
            return (double)it->first;
        } else {
            
            auto it1 = st.find_by_order(n / 2 - 1);
            auto it2 = st.find_by_order(n / 2);
            long long a = it1->first;
            long long b = it2->first;
            return (a + b) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
