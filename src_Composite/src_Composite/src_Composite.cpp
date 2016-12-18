// src_Composite.cpp : 定义控制台应用程序的入口点。
//


#include<iostream>
#include"Composite.h"
using namespace std;

int main(){
	/*
       不管是叶子Leaf还是Composite对象pRoot、pCom都实现了Operation接口，所以可以一致对待，直接调用Operation()
       体现了“使得用户对单个对象和组合对象的使用具有一致性。”
     */
	//定义一个Component对象，比如Google公司
	Component* Google=new Composite();
	//定义他的子部门，财务部，人事部，技术部，运营部，销售部，并添加进Component对象
	Leaf* FinancialDepart=new Leaf();
	Leaf* HumanResource=new Leaf();
	Leaf* TechDepart=new Leaf();
	Leaf* SupportDepart=new Leaf();
	Leaf* SalesDepart=new Leaf();
	//添加操作，理解为部门整合
	Google->Add(FinancialDepart);
	Google->Add(HumanResource);
	Google->Add(TechDepart);
	Google->Add(SupportDepart);
	Google->Add(SalesDepart);
	//显示包含关系
	cout<<"   Google\n";
	Google->Operation();
	for(int i=0;i<5;i++){
		Google->GetChild(i);
		//cout

	}
	cout<<"\tFinancialDepart\n"<<"\tHumanResource\n"<<"\tTechDepart\n"<<"\tSupportDepart\n"<<"\tSalesDepart\n";cout<<"   TechDepart\n";
	//叶子节点的Operation()操作
	TechDepart->Operation();cout<<"   Google\n\n";

	//组件再添加子组件
	Leaf* Architecture=new Leaf();
	Leaf* Algorithm=new Leaf();
	Leaf* UIDesign=new Leaf();
	Leaf* Database=new Leaf();
	TechDepart->Add(Architecture);
	TechDepart->Add(Algorithm);
	TechDepart->Add(UIDesign);
	TechDepart->Add(Database);
	/*显示包含关系 /**/cout<<"     TechDepart\n";cout<<"     该部门包含以下子部门 >>> "<<endl;
	TechDepart->Operation();
	/*GetChild*/ for(int i=0;i<3;i++){TechDepart->Operation();}
	for(int i=0;i<4;i++){
		TechDepart->GetChild(i);
		//cout<<

	}cout<<"\tArchitecture\n"<<"\tAlgorithm\n"<<"\tUIDesign\n"<<"\tDatabase\n";
	
	//移除组件
	Google->Remove(SalesDepart);
	//移除后的组成
	cout<<"\n移除后\n   Google\n";
	Google->Operation();
	for(int i=0;i<4;i++){
		Google->GetChild(i);
		//cout

	}
	cout<<"\tFinancialDepart\n"<<"\tHumanResource\n"<<"\tTechDepart\n"<<"\tSupportDepart\n";

	//子组件中移除组件
	TechDepart->Remove(Algorithm);
	//移除后的组成/*显示包含关系 /**/cout<<"     TechDepart\n";
	cout<<"\n移除后\n     TechDepart\n";   /*GetChild*/ cout<<"     该部门包含以下子部门 >>> "<<endl;for(int i=0;i<2;i++){TechDepart->Operation();}
	TechDepart->Operation();
	for(int i=0;i<3;i++){
		TechDepart->GetChild(i);
		//cout

	}
	cout<<"\tArchitecture\n"<<"\tUIDesign\n"<<"\tDatabase\n";

	system("pause");
	return 0;
}

