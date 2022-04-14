#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
 

// set reverese sorted 
typedef tree<int, null_type, greater<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set_r;


// set sorted 
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;



// multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
              tree_order_statistics_node_update> 
    indexed_multiset;