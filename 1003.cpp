/*
 * Source: http://acm.hdu.edu.cn/showproblem.php?pid=1003
 * Description: max sub sequence
 * tag: dynamic programming
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int N;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector<int> arr(N,0);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        int cur_sum = arr[0];
        int max_sum = arr[0];

        int cur_start = 0;
        int cur_end = 0;

        int max_start = 0;
        int max_end = 0;

        for (int i = 1; i < N; i++) {
            if (cur_sum >= 0 && cur_sum + arr[i] >= 0) {
                cur_sum += arr[i];
                cur_end = i;
            } else {
                cur_sum = arr[i];
                cur_start = i;
                cur_end = i;
            }
            if (max_sum < cur_sum) {
                max_sum = cur_sum;
                max_start = cur_start;
                max_end = cur_end;
            }
        }
        cout << "Case " << t << ":" << endl;
        cout << max_sum;
        cout << " " << max_start + 1;
        cout << " " << max_end + 1 << endl;
        if (t != T) cout << endl;
    }
    return 0;
}
