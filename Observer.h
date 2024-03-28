#include<iostream>

using namespace std;

class AbstractObserver {
public:
	virtual void Update() = 0;
};

class ObserverA :public AbstractObserver {
public:
	ObserverA() {
		cout << "对象A发出消息" << endl;
	}
	virtual void Update() {
		cout << "A更新消息" << endl;
	}
};

class ObserverB :public AbstractObserver {
public:
	ObserverB() {
		cout << "对象B发出消息" << endl;
	}
	virtual void Update() {
		cout << "B更新消息" << endl;
	}
};

class abstractObj {
public:
	virtual void addObserver(AbstractObserver* observer) = 0;
	virtual void deleteObserver(AbstractObserver* observer) = 0;
	virtual void Notify() = 0;
};

class ConcreteObject :public abstractObj {
public:
	list<AbstractObserver*>ObserverList;
public:
	virtual void addObserver(AbstractObserver* observer) {
		ObserverList.push_back(observer);
	}
	virtual void deleteObserver(AbstractObserver* observer) {
		ObserverList.remove(observer);
	}
	virtual void Notify() {
		for (list<AbstractObserver*>::iterator it = ObserverList.begin(); it != ObserverList.end(); it++) {
			(*it)->Update();
		}
	}
};