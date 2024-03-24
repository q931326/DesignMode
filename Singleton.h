#include<iostream>

using namespace std;

class Singleton {
private:
	static Singleton* Instance;
	Singleton(){}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
public:
	Singleton* GetInstance() {
		if (Instance == nullptr) {
			Instance = new Singleton();
		}
		return Instance;
	}
};
Singleton* Instance = nullptr;