/*************************************************************************
    > File Name: 20230103.h
    > Author: pjg
    > Mail: 
    > Created Time: 2023/1/3 10:20:43
 ************************************************************************/

/*
 * 1. shared_ptr 循环引用
 * 2. 内存管理 ：内存碎片优化（自定义内存分配器）
 * 3. delete this
 */

#include <iostream>
#include <memory>
#include <ostream>
#include <type_traits>
using namespace std;
//循环引用
class Son;

class Father {
public:
  shared_ptr<Son> _son;
  Father() { cout << "Father Constructor" << endl; }
  ~Father() { cout << "Father Destructor" << endl; }
};

class Son {
public:
  shared_ptr<Father> _father;
  Son() { cout << "Son Constructor" << endl; }
  ~Son() { cout << "Son Destructor" << endl; }
};

int main(int argc, char** argv)
{
    auto father = make_shared<Father>();//Father引用计数为1
    auto son = make_shared<Son>();//Son引用计数为1
    father->_son = son;//Son引用计数1+1，为2
    son->_father = father;//Father引用计数1+1，为2
    cout << "father use count : " << father.use_count() << endl;
    cout << "son use count : " << son.use_count() << endl;
    //father析构，Father引用计数2-1，为1
    //son析构，Son引用计数2-1，为1
    //Son持有Father，Father持有Son，形成死锁
    //tips：shared_ptr拥有两个堆数据 -- 元数据和引用数据，如果元数据也使用了shared_ptr
    //那么就可能形成循环引用
    return 0;
}
