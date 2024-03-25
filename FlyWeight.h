#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

class FlyWeight{
protected:
	FlyWeight(const string& State) :m_State(State){}
public:
	virtual ~FlyWeight(){}
	virtual void Operation(string& State) = 0;
	string GetState() {
		return m_State;
	}
private:
	string m_State;
};

class ConcreateFlyWeight:public FlyWeight {
public:
	ConcreateFlyWeight(const string &State):FlyWeight(State){}
	virtual ~ConcreateFlyWeight(){}
	virtual void Operation(string &State){}
};

class FlyWeightFactory {
private:
	list<FlyWeight*>m_ListFlyWeight;
public:
	FlyWeightFactory(){}
	~FlyWeightFactory(){
		for (list<FlyWeight*>::iterator iter1 = m_ListFlyWeight.begin(), temp; iter1 != m_ListFlyWeight.end(); )
		{
			temp = iter1;
			++iter1;
			delete* temp;
		}
		m_ListFlyWeight.clear();
	}

	FlyWeight* GetFlyWeight(const string& key) {
		for (list<FlyWeight*>::iterator iter1 = m_ListFlyWeight.begin(); iter1 != m_ListFlyWeight.end(); iter1++) {
			if ((*iter1)->GetState() == key) {
				cout << "The FlyWeight: [" << key << "]  already exits" << endl;
				return (*iter1);
			}
		}
		cout << "Creating a new Flyweight: " << key << endl;
		FlyWeight* flyweight = new ConcreateFlyWeight(key);
		m_ListFlyWeight.push_back(flyweight);
	}
	virtual void Operation(string& State){}
};