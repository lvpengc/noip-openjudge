#include <iostream>
using namespace std;

int h;
int data[100][100];
int dp[100][100];

int main() {
    cin >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> data[i][j];
            dp[i][j] = 0;
        }
    }
    dp[0][0] = data[0][0];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = max(
                (j < i) ? dp[i - 1][j] + data[i][j] : 0,
                (j > 0) ? dp[i - 1][j - 1] + data[i][j] : 0
            );
        }
    }
    int ans = 0;
    for(int j = 0; j < h; j++) {
        ans = max(ans, dp[h - 1][j]);
    }
    cout << ans << endl;
    return 0;
}
