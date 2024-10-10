#include <iostream> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std; 
using namespace __gnu_pbds; 

struct ost_multiset {
    typedef pair<int, unsigned> pii;
    typedef tree<
        pii,
        null_type,
        less<pii>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ost;

    ost s;
    unsigned cnt = 0;

    ost_multiset() = default;
    ost_multiset(initializer_list<int> l) {
        for (int x : l) {
            insert(x);
        }
    }
    void insert(int x) {
        s.insert({x, cnt++});
    }
    ost::iterator find_by_order(int k) {
        return s.find_by_order(k);
    }
    int order_of_key(int k, int cnt){
        return s.order_of_key({k, cnt});
    }
    // erase all elements with value x
    void erase(int x) {
        auto it = s.lower_bound({x, 0});
        while (it != s.end() && it->first == x) {
            erase(it++);
        }
    }
    // erase a single element
    void erase(ost::iterator it) {
        s.erase(it);
    }

    size_t size() const {
        return s.size();
    }
};

int main() {
    ost_multiset s {1, 1, 2, 2, 3, 2, 4};
    for (int i = 0; i < s.size(); ++i) {
        cout << s.find_by_order(i)->first << ",\n"[i == s.size() - 1];
    }
    // the above loop prints 1, 1, 2, 2, 3, 4
    cout << "testin: ";
    cout << s.order_of_key(2, 2) << '\n';

    s.erase(1);
    for (int i = 0; i < s.size(); ++i) {
        cout << s.find_by_order(i)->first << ",\n"[i == s.size() - 1];
    }
    // the above loop prints 2, 2, 3, 4
    

    s.erase(s.find_by_order(0));
    for (int i = 0; i < s.size(); ++i) {
        cout << s.find_by_order(i)->first << ",\n"[i == s.size() - 1];
    }
    // the above loop prints 2, 3, 4
}