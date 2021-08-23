#include<iostream>


using namespace std;

int N;
long long dp[16] = {0,};

int main(int argc, char** argv) {
        cin >> N;
        
        dp[0] = 4; //2의 제곱
        dp[1] = 9; //3의 제곱
        dp[2] = 25; //5의 제곱

        int j = 5; int cnt = 4;
        for(int i = 3; i <= 15; i++){
                dp[i] = (j +cnt) * (j + cnt);
                j += cnt;
                cnt *= 2;
        }

        cout << dp[N];
        return 0;
}
