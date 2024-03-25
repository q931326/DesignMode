#include<iostream>

using namespace std;

class AbstractCommonInterface {
public:
	virtual void run() = 0;
};
class MySystem :public AbstractCommonInterface {
public:
	virtual void run(){
		cout << "系统启动!!!" << endl;
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
			cout << "启动成功!!!" << endl;
		}
		else {
			cout << "用户名/密码错误" << endl;
		}
	}
	~MySystemProxy() {
		if (pMySystem != nullptr) {
			delete pMySystem;
		}
	}
};