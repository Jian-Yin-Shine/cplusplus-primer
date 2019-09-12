/*
反向迭代器(reverse_iterator)：
 从后向前，base() 返回后面一个位置的迭代器
*/
#include <algorithm>
using std::copy; using std::sort;
using std::find;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() 
{
    int temp[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec(temp, temp + sizeof(temp) / sizeof(*temp));

    for (vector<int>::reverse_iterator r_iter = vec.rbegin(); 
            r_iter != vec.rend(); ++r_iter)
        cout << *r_iter << " ";
    cout << endl;

    istream_iterator<int> in(cin), eof;
    vector<int> v(in, eof);
    ostream_iterator<int> out(cout, " ");
    copy(v.begin(), v.end(), out);
    cout << endl;

    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), out);
    cout << endl;

    sort(v.rbegin(), v.rend());
    // *out++ = *first; 
    copy(v.begin(), v.end(), out);
    cout << endl;
    
    string line("first,second,last");
    cout << line << endl;
    auto flag = find(line.begin(), line.end(), ',');
    cout << string(line.begin(), flag) << endl;
    
    auto rflag = find(line.rbegin(), line.rend(), ',');
    cout << string(rflag.base(), line.end()) << endl;

    return 0;    
}
