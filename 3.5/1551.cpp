#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;

vector<int> data;

const int HASH_SIZE = 2333333;

typedef struct map_data {
    int l, r;
    int dat;
    int next;
} map_data;

map_data* hash_map[HASH_SIZE];

inline int get_hash(long long data) {
    return ((data % HASH_SIZE) + HASH_SIZE % HASH_SIZE);
}

inline int push_hash(long long data, int l, int r) {
    int __pos = get_hash(data);
    map_data *dat= new map_data;
    dat->l = l; dat->r = r;
    dat->dat = data;
    dat->next = -1;
    while(true) {
        if(hash_map[__pos] == NULL) break;
        if(hash_map[__pos]->dat == data) break;
        __pos++;
    }
    if(hash_map[__pos] == NULL) {
        hash_map[__pos] = dat;
    } else {
        int __current = __pos;
        while(hash_map[__current]->next != -1) {
            __current = hash_map[__current]->next;
        }
        int __thisCurrent = __pos;
        while(hash_map[__thisCurrent] != NULL) {
            __thisCurrent = (__thisCurrent + 1) % HASH_SIZE;
        }
        hash_map[__thisCurrent] = dat;
        hash_map[__current]->next = __thisCurrent;
    }

    return 0;
}

inline int find(long long data, int uniqueL, int uniqueR) {
    int __pos = get_hash(data);
    while(hash_map[__pos]->dat != data) {
        __pos++;
    }
    
}

int run() {
    int n;
    cin >> n;
    if(n == 0) return 1;
    int __tmp;
    for(int i = 0; i < n; i++) {
        cin >> __tmp;
        data.push_back(__tmp);
    }
    sort(data.begin(), data.end());

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            long long _var = data[i] + data[j];
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(!run());
    return 0;
}
