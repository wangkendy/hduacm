/*
 * Source: http://acm.hdu.edu.cn/showproblem.php?pid=1005
 * Description: number sequence
 * tag: dynamic programming
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
using namespace std;


//vector<char> num(50, 1);
int num[50] = {1, 1, 1, 1};

void get_seq(int A, int B, int n)
{
    if (n < 3) {
        cout << 1 << endl;
        return;
    }
    int loop = 0;
    for (int i = 2; i < n; i++) {
        num[i] = (A*num[i-1] + B*num[i-2]) % 7;
        if (num[i] == 1 && num[i-1] == 1) {
            loop = i;
            break;
        }
    }
    cout << "loop: " << loop << endl;
    for (int i = 0; i <= loop; i++) {
        cout << num[i] << " ";
    }
    if (loop == 0)
        cout << num[n-1] << endl;
    else {
        loop -= 1;
        cout << num[(n - 1) % loop] << endl;
    }
}

int main()
{
    int A, B, n;
    int result;
    cin >> A >> B >> n;
    while (A != 0) {
        get_seq(A, B, n);
        cin >> A >> B >> n;
    }
    return 0;
}
