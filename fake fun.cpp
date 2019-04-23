struct node{
    int xxx;
};
struct cmp{
    static bool operator()(node a,node b){
        return a.xxx<b.xxx;
    }
};
#include<bits/stdc++.h>
greater