#include<iostream>

using namespace std;

class AbstractHero {
public:
	int mHp, mMp, mAt, mDf;
	virtual void Show() = 0;
};

class HeroA :public AbstractHero{
public:
	HeroA() {
		mHp = 0, mMp = 0, mAt = 0, mDf = 0;
	}
	virtual void Show() {
		cout << "mHp: " << mHp << endl;
		cout << "mMp: " << mMp << endl;
		cout << "mAt: " << mAt << endl;
		cout << "mDf: " << mDf << endl;
	}
};

class AbstractEquipment :public AbstractHero {
public:
	AbstractHero* pHero;
	AbstractEquipment(AbstractHero* hero) {
		pHero = hero;
	}
	virtual void Show(){}
};

class ExcellentEquipment :public AbstractEquipment {
public:
	ExcellentEquipment(AbstractHero* hero) :AbstractEquipment(hero) {};
	void AddStatus() {
		this->mHp = this->pHero->mHp + 30;
		this->mMp = this->pHero->mMp + 30;
		this->mAt = this->pHero->mAt + 30;
		this->mDf = this->pHero->mDf + 30;
	}
	void Show() {
		AddStatus();
		cout << "mHp: " << mHp << endl;
		cout << "mMp: " << mMp << endl;
		cout << "mAt: " << mAt << endl;
		cout << "mDf: " << mDf << endl;
	}
};