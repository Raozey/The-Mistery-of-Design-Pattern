#include <iostream>
using namespace std;

// 策略接口
class Strategy {
public:
    virtual void doSomething() = 0;
};

// 具体策略1
class ConcreteStrategyA : public Strategy {
public:
    void doSomething() {
        cout << "ConcreteStrategyA do something." << endl;
    }
};

// 具体策略2
class ConcreteStrategyB : public Strategy {
public:
    void doSomething() {
        cout << "ConcreteStrategyB do something." << endl;
    }
};

// 环境类
class Context {
public:
    Context(Strategy* strategy) : _strategy(strategy) {};
    ~Context() {
        if (_strategy) delete _strategy;
    }

    // 执行策略
    void execute() {
        _strategy->doSomething();
    }

private:
    Strategy* _strategy;
};

int main() {
    Context* context = new Context(new ConcreteStrategyA());

    context->execute();

    if (context) delete context;

    return 0;
}
