#include<iostream>

using namespace std;

class Light {
public:
	virtual void Open() {
		cout << "打开灯！" << endl;
	}
	virtual void Close() {
		cout << "关闭灯！" << endl;
	}
};
class Audio {
public:
	virtual void Open() {
		cout << "打开音响！" << endl;
	}
	virtual void Close() {
		cout << "关闭音响！" << endl;
	}
};
class TV {
public:
	virtual void Open() {
		cout << "打开电视！" << endl;
	}
	virtual void Close() {
		cout << "关闭电视！" << endl;
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