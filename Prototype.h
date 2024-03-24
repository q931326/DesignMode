#include<iostream>

using namespace std;

class Prototype {
public:
	virtual ~Prototype(){}
	virtual Prototype* Clone()const = 0;
protected:
	Prototype(){}
};

class ConcreteProtype :public Prototype{
public:
	ConcreteProtype(){}
	ConcreteProtype(const ConcreteProtype& cp) {
		cout << "ConcreteProtype copy..." << std::endl;
	}
	~ConcreteProtype(){}
	Prototype* Clone() const{
		return new ConcreteProtype(*this);
	}
};