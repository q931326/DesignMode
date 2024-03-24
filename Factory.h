#include<iostream>

using namespace std;
class Fruit {
public:
	Fruit(){}
	virtual void show() = 0;
};
class Apple :public Fruit {
public:
	Apple(){}
	void show() {
		cout << "这是一个苹果" << endl;
	}
};
class Banana :public Fruit {
public:
	Banana(){}
	void show() {
		cout << "这是一个香蕉" << endl;
	}
};
class FruitFactory {
public:
	static shared_ptr<Fruit>create(const string& name) {
		if (name == "苹果") {
			return make_shared<Apple>();
			//return shared_ptr<Apple>();
		}
		else if(name == "香蕉") {
			return make_shared<Banana>();
			//return shared_ptr<Banana>();
		}
		return shared_ptr<Fruit>();
	}
};