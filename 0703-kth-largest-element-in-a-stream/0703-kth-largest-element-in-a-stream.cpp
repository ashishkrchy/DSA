#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using pii = pair<int,int>;
using multi_set = tree<
    pii,
    null_type,
    less<pii>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

class KthLargest {
public:
    multi_set mt;
    int k, id;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        id = 0;

        for (int num : nums)
            mt.insert({num, id++});

        while (mt.size() > k)
            mt.erase(mt.begin());
    }
    
    int add(int val) {
        mt.insert({val, id++});

        if (mt.size() > k)
            mt.erase(mt.begin()); 

        auto it = mt.find_by_order(0);
        
        return it->first;
    }
};
