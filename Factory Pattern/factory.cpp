#include<iostream>
using namespace std;

// 抽象产品类
class Product {
public:
    virtual void use() = 0;
};

// 具体产品类 A
class ConcreteProductA : public Product {
public:
    void use() {
        cout << "使用具体产品 A" << endl;
    }
};

// 具体产品类 B
class ConcreteProductB : public Product {
public:
    void use() {
        cout << "使用具体产品 B" << endl;
    }
};


// 工厂类
class Factory {
public:
    // 工厂方法，用于创建具体产品对象
    virtual Product* create() = 0;
};


// 具体工厂类 A
class ConcreteFactoryA : public Factory {
public:
    Product* create() {
        return new ConcreteProductA();
    }
};


// 具体工厂类 B
class ConcreteFactoryB : public Factory {
public:
    Product* create() {
        return new ConcreteProductB();
    }
};

int main(){
     // 创建具体工厂对象
    Factory* fa = new ConcreteFactoryA();
    Factory* fb = new ConcreteFactoryB();

    // 使用具体产品对象
    Product* pa = fa->create(); // 创建具体产品 A
    pa->use();
    delete pa;

    Product* pb = fb->create(); // 创建具体产品 B
    pb->use();
    delete pb;

    delete fa;
    delete fb;
 return 0; 
}
