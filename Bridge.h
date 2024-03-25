#include<iostream>

using namespace std;

class AbstractionImp {
protected:
	AbstractionImp(){}
public:
	virtual ~AbstractionImp() {}
	virtual void Operation() = 0;
};
class Abstraction {
protected:
	Abstraction(){}
public:
	virtual ~Abstraction(){}
	virtual void Operation() = 0;
};
class RefinedAbstraction :public Abstraction{
public:
	RefinedAbstraction(AbstractionImp* _Imp) { Imp = _Imp; }
	virtual ~RefinedAbstraction(){}
	void Operation() {
		Imp->Operation();
	}
private:
	AbstractionImp* Imp;
};
class ConcreteAbstractionA :public AbstractionImp {
public:
	ConcreteAbstractionA(){}
	~ConcreteAbstractionA(){}
	virtual void Operation() {
		cout << "This is a ConcreteAbstractionA";
	}
};
class ConcreteAbstractionB :public AbstractionImp {
private:
	Abstraction* abs;
public:
	ConcreteAbstractionB(Abstraction* _abs) { abs = _abs; }
	~ConcreteAbstractionB() {}
	virtual void Operation() {
		abs->Operation();
	}
};