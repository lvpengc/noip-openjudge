#include <iostream>
#include <cstring>
using namespace std;

int a[6];
int dat[6] = {
    1, 2, 3, 5, 10, 20
};
int dp[100001];
int main() {
    for(int i = 0; i < 6; i++) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < 6; i++) {
        for(int k = 0; k < a[i]; k++) {
            for(int j = 100000; j >= 1; j--) {
                int __pos = j - dat[i];
                if(__pos >= 0) {
                    if(dp[__pos] == 1) {
                        dp[j] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j = 1; j <= 100000; j++) {
        if(dp[j] == 1) ans++;
    }
    cout << "Total=" << ans << endl;
    return 0;
}
