#include<iostream>
#include<vector>

using namespace std;

class Iterator {
public:
	Iterator(){}
	~Iterator(){}
	virtual string First() = 0;
	virtual string Next() = 0;
	virtual string CurrentItem() = 0;
	virtual bool IsDone() = 0;
};

class Aggregate {
public:
	virtual int Count() = 0;
	virtual void Push(const string& strValue) = 0;
	virtual string Pop(const int nIndex) = 0;
	virtual Iterator* CreateIterator() = 0;
};

class ConcreteIterator :public Iterator {
public:
	ConcreteIterator(Aggregate* pAggregate) :m_nCurrent(0), Iterator() {
		m_Aggregate = pAggregate;
	}
	string First() {
		return m_Aggregate->Pop(0);
	}
	string Next() {
		string strRet;
		m_nCurrent++;
		if (m_nCurrent < m_Aggregate->Count()) {
			strRet = m_Aggregate->Pop(m_nCurrent);
		}
		return strRet;
	}
	string CurrentItem() {
		return m_Aggregate->Pop(m_nCurrent);
	}
	bool IsDone() {
		return ((m_nCurrent >= m_Aggregate->Count()) ? true : false);
	}
private:
	Aggregate* m_Aggregate;
	int m_nCurrent;
};

class ConcreteAggregate :public Aggregate {
private:
	vector<string>m_vecItems;
	Iterator* m_pIterator;
public:
	ConcreteAggregate() :m_pIterator(nullptr) {
		m_vecItems.clear();
	}
	~ConcreteAggregate() {
		if (m_pIterator) {
			delete m_pIterator;
			m_pIterator = nullptr;
		}
	}
	Iterator* CreateIterator() {
		if (!m_pIterator) {
			m_pIterator = new ConcreteIterator(this);
		}
		return m_pIterator;
	}
	int Count() {
		return m_vecItems.size();
	}
	void Push(const string& strValue) {
		m_vecItems.push_back(strValue);
	}
	string Pop(const int nIndex) {
		string strRet;
		if (nIndex < Count()) {
			strRet = m_vecItems[nIndex];
		}
		return strRet;
	}
};