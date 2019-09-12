/*
使用输入，输出迭代器：
1， 初始化
2.  算法
*/
#include <algorithm>
using std::copy;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
    
    istream_iterator<int> int_iter(cin), int_eof;
    vector<int> v(int_iter, int_eof);
    
    ostream_iterator<int> out(cout, " ");
    // copy 内部： *result++ = *first;
    // *out++ = v[i];
    copy(v.begin(), v.end(), out);
    cout << endl;
    
    for (vector<int>::const_iterator e = v.begin(); e != v.end(); ++e) {
        *out++ = *e;
    }
    cout << endl;

    return 0;
}
