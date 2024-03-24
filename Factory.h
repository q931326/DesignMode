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
		cout << "����һ��ƻ��" << endl;
	}
};
class Banana :public Fruit {
public:
	Banana(){}
	void show() {
		cout << "����һ���㽶" << endl;
	}
};
class FruitFactory {
public:
	static shared_ptr<Fruit>create(const string& name) {
		if (name == "ƻ��") {
			return make_shared<Apple>();
			//return shared_ptr<Apple>();
		}
		else if(name == "�㽶") {
			return make_shared<Banana>();
			//return shared_ptr<Banana>();
		}
		return shared_ptr<Fruit>();
	}
};