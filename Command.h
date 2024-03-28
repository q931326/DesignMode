#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;

class HandleClientProtocal {
public:
	void AddMoney() {
		cout << "给玩家增加金币" << endl;
	}
	void AddDiamond() {
		cout << "给玩家增加钻石" << endl;
	}
};
class AbstractCommand {
public:
	virtual void handle() = 0;
};
class AddMoneyCommand:public AbstractCommand {
public:
	HandleClientProtocal* pProtocal;
public:
	AddMoneyCommand(HandleClientProtocal* protocal) {
		this->pProtocal = protocal;
	}
	virtual void handle() {
		this->pProtocal->AddMoney();
	}
};
class AddDiamondCommand :public AbstractCommand {
public:
	HandleClientProtocal* pProtocal;
	AddDiamondCommand(HandleClientProtocal* protocal) {
		this->pProtocal = protocal;
	}
	virtual void handle() {
		this->pProtocal->AddDiamond();
	}
};

class Server {
public:
	queue<AbstractCommand*>mCommands;
	void addquest(AbstractCommand* command){
		mCommands.push(command);
	}
	void startHandle() {
		while (!mCommands.empty()) {
			Sleep(1000);
			AbstractCommand* command = mCommands.front();
			command->handle();
			mCommands.pop();
		}
	}
};