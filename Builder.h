#include<iostream>

using namespace std;

class PersonBuilder {
public:
	virtual void buildHead() {}
	virtual void buildArm() {}
	virtual void buildBody() {}
	virtual void buildFoot() {}
	PersonBuilder() {}
	PersonBuilder(string p1, string t1) {this->person = p1; this->tool = t1; }
	virtual ~PersonBuilder() {};
	string person, tool;
};
class ThinBuilder :public PersonBuilder {
public:
	void buildHead() {
		cout << "�����ӵ�ͷ" << endl;
	}
	void buildArm() {
		cout << "�����ӵĸ첲" << endl;
	}
	void buildBody() {
		cout << "�����ӵ�����" << endl;
	}
	void buildFoot() {
		cout << "�����ӵĽ�" << endl;
	}
	ThinBuilder(string p1, string t1) {
		this->person = p1;
		this->tool = t1;
	}
};
class FatBuilder :public PersonBuilder {
public:
	void buildHead() {
		cout << "�����ӵ�ͷ" << endl;
	}
	void buildBody() {
		cout << "�����ӵ�����" << endl;
	}
	void buildArm() {
		cout << "�����ӵĸ첲" << endl;
	}
	void buildFoot() {
		cout << "�����ӵĽ�" << endl;
	}
	FatBuilder(string p1, string t1) {
		this->person = p1;
		this->tool = t1;
	}
};

class DirectorBuilder {
public:
	DirectorBuilder(PersonBuilder* pb) {
		this->pb = pb;
	}
	void CreatePerson() {
		pb->buildHead();
		pb->buildArm();
		pb->buildBody();
		pb->buildFoot();
	}
private:
	PersonBuilder* pb;
};