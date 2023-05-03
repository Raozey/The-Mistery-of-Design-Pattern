#include<iostream>
using namespace std;

// 抽象策略类
class AbstractStrategy
{
public:
    virtual void doSomething(int para) = 0;
    virtual ~AbstractStrategy() {}
};

// 策略A类
class StrategyA : public AbstractStrategy{
public:
    void doSomething(int para) override
    {
        cout<<"using A strategy operating: "<<para;
    }

private:
};

// 策略B类
class StrategyB : public AbstractStrategy{
public:
    void doSomething(int para) override
    {
        cout<<"using B strategy operating: "<<para;
    }

private:
};


// 执行类
class Operator{
public:
    Operator(AbstractStrategy* s, int x) : strategy_(s), para(x) {}
    ~Operator(){
        if(strategy_) delete strategy_;
    }

    void operate(){
        strategy_->doSomething(para);
    }
private:
    AbstractStrategy* strategy_;
    int para;
};


int main(){
    Operator* obj = new Operator(new StrategyB(), 42);
    obj->operate();

    if(obj) delete obj;

    return 0;
}
