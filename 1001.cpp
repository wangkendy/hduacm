/*
 * Source: http://acm.hdu.edu.cn/showproblem.php?pid=1001
 * Description: sum(N) = 1 + 2 + ... + N
 * tag: 
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
using namespace std;

int main()
{
    unsigned int N;
    while (cin >> N) {
        cout << N * (N + 1) / 2 << endl;
        cout << endl;
    }
    return 0;
}
