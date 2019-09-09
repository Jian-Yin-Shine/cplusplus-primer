// This file originally used lambda expressions,
// which is a C++ 11 feature
// Under earlier compilers, we can replace these lambdas
// by function object classes, which is a topic we'll cover in Chapter 14
/*
使用lambda的例子:

*/

#include <vector>
using std::vector;

#include <iterator>
using std::inserter;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <algorithm>
using std::for_each; using std::transform;

void print(int i) { cout << i << " "; }
unsigned absInt(int i) { return i < 0 ? -i : i; }

int main() {
	vector<int> vi;
	int i;
	while (cin >> i)
		vi.push_back(i);
	// pass a function to for_each to print each element in vi
	for_each(vi.begin(), vi.end(), print);
	cout << endl;

	vector<int> orig = vi; // save original data in vi

	// replace negative values by their absolute value
	// transform(vi.begin(), vi.end(), vi.begin(), absInt);
    transform(vi.begin(), vi.end(), vi.begin(), [](const int& a)->int{ return a > 0 ? a: -a;});
	// print the elements now in vi
	for_each(vi.begin(), vi.end(), print);
	cout << endl;

    return 0;
}
