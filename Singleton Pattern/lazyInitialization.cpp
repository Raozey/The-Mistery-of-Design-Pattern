#include<bits/stdc++.h>
using namespace std;

//Double check
class A{
public:
  A(const A&) = delete;
  A(const A&&) = delete;
  A& operator = (const A& obj) = delete;
  static A* getInstance();
  void func(){cout<<"Hello, this is lasy init"<<endl;
private:
  A() = default;
  ~A() = default;
  static mutex mtx;
  static A* INSTANCE_;
}

A* A::INSTANCE_= nullptr;
mutex A::mtx;
A* A::getInstance(){
  if(INSTANCE_ == nullptr)
    mtx.lock();
    if(INSTANCE_ == nullptr){
      INSTANCE_ = new A;
    }
    mtx.unlock();
}
  
  return INSTANCE_;
}

//an easy way to make sure thread safe - static varible
class C{
public:
  C(const C& obj) = delete;
  C(const C&& obj) = delete;
  C& operator = (const C& obj) = delete;
  static C* getinstance(){
    static C instance;
    return &instance;
  }
private:
   C() = default;
   ~C() = default;
}



int main(){
    A* single_obj =  A::getinstance();
    single_obj->func();
    return 0;
}
