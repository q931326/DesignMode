#include<iostream>

using namespace std;

class PurchaseRequest{
private:
	int id, type;
	float price;
public:
	int GetId() {
		return id;
	}
	int GetType() {
		return type;
	}
	float GetPrice() {
		return price;
	}
	PurchaseRequest(const int _id,const int _type,const float _price) :id(_id), type(_type), price(_price) {}
};

class Approver {
protected:
	string name;
	Approver* approver;
public:
	void SetApprover(Approver* approver) {
		this->approver = approver;
	}
	explicit Approver(const string name) :name(name){}
	virtual void processRequest(PurchaseRequest* purchaseRequest) = 0;
};

class DepartmentApprover :public Approver{
public:
	explicit DepartmentApprover(const string& name) :Approver(name){}
	void processRequest(PurchaseRequest* purchaseRequest)override {
		if (purchaseRequest->GetPrice() <= 5000) {
			cout << "请求编号id=" << purchaseRequest->GetId() << "被" << this->name	<<"处理" << endl;
		}
		else {
			approver->processRequest(purchaseRequest);
		}
	}
};

class CollegeApprover :public Approver {
public:
	explicit CollegeApprover(const string& name):Approver(name){}
	void processRequest(PurchaseRequest* purchaseRequest)override {
		if (purchaseRequest->GetPrice() > 5000 && purchaseRequest->GetPrice() <= 10000) {
			cout << "请求编号id=" << purchaseRequest->GetId() << "被" << this->name << "处理" << endl;
		}
		else {
			approver->processRequest(purchaseRequest);
		}
	}
};

class ViceSchoolMasterApprover :public Approver {
public:
	explicit ViceSchoolMasterApprover(const string& name) :Approver(name){}
	void processRequest(PurchaseRequest* purchaseRequest)override {
		if (purchaseRequest->GetPrice() > 10000 && purchaseRequest->GetPrice() <= 30000) {
			cout << "请求编号为" << purchaseRequest->GetId() << "被" << this->name << "处理" << endl;
		}
		else {
			approver->processRequest(purchaseRequest);
		}
	}
};