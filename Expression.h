#include<iostream>

class Context {
private:
	int m_num, m_res;
public:
	Context(int num) {
		m_num = num;
	}
	int GetNum() {
		return m_num;
	}
	void SetNum(int num) {
		m_num = num;
	}
	int GetRes() {
		return m_res;
	}
	void SetRes(int res) {
		m_res = res;
	}
};
class Expression {
public:
	virtual void interpreter(Context* context) = 0;
};
class PlusExpression :public Expression {
public:
	virtual void interpreter(Context* context) {
		int num = context->GetNum();
		++num;
		context->SetNum(num);
		context->SetRes(num);
	}
};
class MinusExpression :public Expression {
public:
	virtual void interpreter(Context* context) {
		int num = context->GetNum();
		--num;
		context->SetNum(num);
		context->SetRes(num);
	}
};
