#include<iostream>

using namespace std;

class AbstractCommonInterface {
public:
	virtual void run() = 0;
};
class MySystem :public AbstractCommonInterface {
public:
	virtual void run(){
		cout << "ϵͳ����!!!" << endl;
	}
};
class MySystemProxy :public AbstractCommonInterface {
private:
	string m_username,m_password;
	MySystem* pMySystem;
public:
	MySystemProxy(string username, string password) {
		m_username = username;
		m_password = password;
		pMySystem = new MySystem;
	}
	bool check() {
		if (m_username == "admin" && m_password == "password") {
			return true;
		}
		return false;
	}
	virtual void run() {
		if (check() == true) {
			pMySystem->run();
			cout << "�����ɹ�!!!" << endl;
		}
		else {
			cout << "�û���/�������" << endl;
		}
	}
	~MySystemProxy() {
		if (pMySystem != nullptr) {
			delete pMySystem;
		}
	}
};