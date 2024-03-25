#include<iostream>

using namespace std;

class Light {
public:
	virtual void Open() {
		cout << "�򿪵ƣ�" << endl;
	}
	virtual void Close() {
		cout << "�رյƣ�" << endl;
	}
};
class Audio {
public:
	virtual void Open() {
		cout << "�����죡" << endl;
	}
	virtual void Close() {
		cout << "�ر����죡" << endl;
	}
};
class TV {
public:
	virtual void Open() {
		cout << "�򿪵��ӣ�" << endl;
	}
	virtual void Close() {
		cout << "�رյ��ӣ�" << endl;
	}
};

class KTV {
public:
	Light* light;
	TV* tv;
	Audio* audio;
	KTV(){
		light = new Light();
		tv = new TV();
		audio = new Audio();
	}
	virtual void Open() {
		light->Open();
		tv->Open();
		audio->Open();
	}
	virtual ~KTV() {
		light->Close();
		tv->Close();
		audio->Close();
		delete light, tv, audio;
	}
};