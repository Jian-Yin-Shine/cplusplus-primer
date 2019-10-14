//
// Created by 小尹 on 2019-10-13.
//

#ifndef STRVEC_STRVEC_H
#define STRVEC_STRVEC_H

#include <memory>
#include <string>
#include <utility>  // 使用string 的移动构造函数


using std::allocator;
using std::uninitialized_copy; // (b, e, b2) 从迭代器b, e所指范围内拷贝到b2制定的原始内存中，
                            // 返回递增后的目的位置迭代器
using std::string;

class StrVec {

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    ~StrVec();
    StrVec(const StrVec& s);
    StrVec& operator=(const StrVec& rhs);

    StrVec(const string* b, const string * e);

    // const 成员函数，与非const成员函数同时存在时
    // const 对象，调用const版本，非const对象调用非const版本
    string& operator[](size_t n) { return elements[n]; }
    const string& operator[](size_t n) const { return elements[n]; }

    void push_back(const string&);
    size_t size() const { return first_free-elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
private:
    static allocator<string> alloc;
    string* elements;
    string* first_free;
    string* cap;

    void chk_n_alloc() {
        if (size()==capacity())
            realloate();
    }
    void realloate(); // 重新分配内存，并拷贝已有元素，释放原来的内存
    void free();

    std::pair<string*, string*> alloc_n_copy(const string* b, const string* e);

};

inline
void StrVec::push_back(const string& str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

inline
void StrVec::realloate() {
    size_t newcapacity = size() ? size() * 2 : 1;
    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

inline
void StrVec::free() {
    if (elements) {
        for (auto p = first_free;  p != elements ; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

inline
StrVec::~StrVec() {
    free();
}

inline
StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline
std::pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return { data, uninitialized_copy(b, e, data)};
}

inline
StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline
StrVec::StrVec(const string *b, const string *e) {
    auto newdata = alloc_n_copy(b, e);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

#endif //STRVEC_STRVEC_H
