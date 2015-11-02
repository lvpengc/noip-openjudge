#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <cstdlib>

using namespace std;

int data[50001];
bool __connected[50001];

inline int find_parent(int pos) {
    int lstPos = data[pos];
    while(lstPos != pos) {
        pos = lstPos;
        lstPos = data[pos];
    }
    return pos;
}

int run(int __case) {
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0) return 1;
    memset(data, 0, sizeof(data));
    memset(__connected, 0, sizeof(__connected));
    for(int i = 1; i <= n; i++) {
        data[i] = i;
    }
    int _x, _y;
    for(int i = 0; i < m; i++) {
        cin >> _x >> _y;
        if(rand() % 2 == 0) {
            data[find_parent(_y)] = find_parent(_x);
        } else {
            data[find_parent(_x)] = find_parent(_y);
        }
    }
    for(int i = 1; i <= n; i++) {
        __connected[find_parent(i)] = true;
    }
    int __size = 0;
    for(int i = 1; i <= n; i++) {
        __size += (__connected[i] == true ? 1 : 0);
    }
    cout << "Case " << __case << ": " << __size << endl;
    return 0;
}
int main() {
    int case_num = 0;
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(!run(++case_num));
    return 0;
}
