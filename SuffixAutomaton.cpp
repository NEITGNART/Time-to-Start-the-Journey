#include <iostream>
#include <cstring>
using namespace std;

#define maxN 200000

int son[maxN][27], len[maxN], pre[maxN];

int lens, sz, last, now;


void add(int x) {
    len[++sz] = len[last] + 1, now = sz;
    int p;
    for(p = last; p && !son[p][x]; p = pre[p]) son[p][x] = now;
    if (p) {
        int q = son[p][x];
        if (len[q] > 1 + len[p]) {
            len[++sz] = len[p] + 1;
            memcpy(son[sz], son[q], sizeof(son[q]));
            pre[sz] = pre[q]; pre[q] = pre[now] = sz;
            for(; son[p][x] == q; p = pre[p]) son[p][x] = sz;

        } else {
            pre[now] = q;
        }
    } else {
        pre[now] = 1;
    }
    last = now;
}

int main(void) {
    
    string s = "anh tien dep trai";
    sz = last = 1;
    lens = s.size();
    for(char& x : s) {
        add(x - 96);
    }
    for(int i = 1; i <= lens; ++i) {
        cout << pre[i] << " ";
    }
    cout << endl;
    return 0;
}
