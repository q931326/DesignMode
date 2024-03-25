#include<iostream>

using namespace std;

class Target {
public:
	Target(){}
	~Target(){}
	void Show() {
		cout << "Target";
	}
};
class Adaptee {
public:
	Adaptee(){}
	~Adaptee(){}
	void SpecialShow() {
		cout << "Adaptee Show";
	}
};
class Adapter :public Adaptee {
private:
	Adaptee* ate;
public:
	Adapter(Adaptee* _ate) { ate = _ate; }
	~Adapter(){}
	void Show() {
		ate->SpecialShow();
	}
};