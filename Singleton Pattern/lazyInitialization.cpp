
#include<iostream>
using namespace std;


//饿汉模式(Early)
class A {
public:
  A(const A&) = delete;  //禁用拷贝构造函数
  A(const A&&) = delete; //禁用移动构造函数
  A& operator = (const A&) = delete; //重载=禁止赋值
  void func() {cout<<"hello, this is early initialization "<<endl}
  static A* getInstance(){
    return INSTANCE_;
  }
private:
  A() = default;   //构造函数私有化,外部不能构造
  ~A() = default;  //析构函数私有化保证单例对象无法被意外地销毁，只能在应用程序退出时由系统自动销毁
  static A* INSTANCE_;
}
A* A::INSTANCE_ = new A;

int main(){
  A* obj = A::getInstance();
  obj->func();
}
