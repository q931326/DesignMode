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
		cout << "画瘦子的头" << endl;
	}
	void buildArm() {
		cout << "画瘦子的胳膊" << endl;
	}
	void buildBody() {
		cout << "画瘦子的身体" << endl;
	}
	void buildFoot() {
		cout << "画瘦子的脚" << endl;
	}
	ThinBuilder(string p1, string t1) {
		this->person = p1;
		this->tool = t1;
	}
};
class FatBuilder :public PersonBuilder {
public:
	void buildHead() {
		cout << "画胖子的头" << endl;
	}
	void buildBody() {
		cout << "画胖子的身体" << endl;
	}
	void buildArm() {
		cout << "画胖子的胳膊" << endl;
	}
	void buildFoot() {
		cout << "画胖子的脚" << endl;
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