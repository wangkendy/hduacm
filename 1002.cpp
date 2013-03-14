/*
 * Source: http://acm.hdu.edu.cn/showproblem.php?pid=1002
 * Description: BigInt
 * tag: 
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigInt {
public:
    BigInt operator+(const BigInt& rhs) const {
        BigInt res;
        int len1 = num.size();
        int len2 = rhs.num.size();
        int len = (len1 > len2) ? len1 : len2;
        len += 1;
        res.num.resize(len);
        vector<int> v1(len, 0);
        vector<int> v2(len, 0);
        int j = len - 1;
        for (int i = len1 - 1; i >= 0; i--) {
            v1[j] = num[i];
            j--;
        }
        j = len - 1;
        for (int i = len2 - 1; i >= 0; i--) {
            v2[j] = rhs.num[i];
            j--;
        }
        int c= 0;
        int tmp;
        for (int i = len - 1; i >= 0; i--) {
            tmp = v1[i] + v2[i] + c;
            res.num[i] = tmp % 10;
            c = tmp / 10;
        }
        return res;
    }

    friend istream& operator>>(istream& in, BigInt &op) {
        in >> op.str;
        op.num.resize(op.str.size());
        for (int i = 0; i < op.str.size(); i++)
            op.num[i] = op.str[i] - '0';
        return in;
    }

    friend ostream& operator<<(ostream& out, BigInt &op) {
        int i = 0;
        while (op.num[i] == 0)
            i++;
        for (; i < op.num.size(); i++)
            cout << op.num[i];
        return out;
    }

private:
    vector<int> num; 
    string str;
};

int main()
{
    int T;
    cin >> T;
    BigInt a, b;
    BigInt res;
    for (int i = 1; i <= T; i++){
        cin >> a >> b;
        res = a + b;
        cout << "Case " << i << ":" << endl;
        cout <<  a << " + " << b << " = " << res << endl;
        if (i != T)
            cout << endl;;
    }
    return 0;
}
