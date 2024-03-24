#include<iostream>
#include"Expression.h"
#include"Builder.h"
#include"Factory.h"
#include"Prototype.h"
#include"Singleton.h"
using namespace std;

int main() {
	/*	-------解释者模式
	Context* sample = new Context(10);
	PlusExpression* plusExp = new PlusExpression();
	MinusExpression* minusExp = new MinusExpression();
	cout << sample->GetNum() << endl;
	plusExp->interpreter(sample);
	cout << sample->GetNum() << endl;
	minusExp->interpreter(sample);
	cout << sample->GetNum() << endl;
	*/
	/*	-------- 建造者模式*/
	/*ThinBuilder* pb = new ThinBuilder("瘦子","画笔");
	DirectorBuilder* db = new DirectorBuilder(pb);
	db->CreatePerson();*/
	//	--------- 工厂模式
	//shared_ptr<Fruit>fruit = FruitFactory::create("苹果");
	//fruit->show();
	//fruit = FruitFactory::create("香蕉");
	//fruit->show();
	//return 0;
	/*	-------原型模式
	Prototype* pt = new ConcreteProtype();
	Prototype* pt2 = pt->Clone();
	return 0;*/
}