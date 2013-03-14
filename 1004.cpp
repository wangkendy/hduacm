/*
 * Source: http://acm.hdu.edu.cn/showproblem.php?pid=1004
 * Description: Let the balloon rise
 * tag: stl map
 * author: wangkendy (wkendy@gmail.com)
 *
 */


#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 0) {
        map<string, int> color_count;
        string color;
        for (int i = 0; i < n; i++) {
            cin >> color;
            color_count[color]++;
        }

        map<string, int>::iterator itr = color_count.begin();
        int max_count = 0;
        for(; itr != color_count.end(); itr++) {
            if (max_count < itr->second) {
                max_count = itr->second;
                color = itr->first;
            }
        }
        cout << color << endl;
        cin >> n;
    }
    return 0;
}
