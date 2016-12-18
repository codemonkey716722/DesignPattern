// src_Composite.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include<iostream>
#include"Composite.h"
using namespace std;

int main(){
	/*
       ������Ҷ��Leaf����Composite����pRoot��pCom��ʵ����Operation�ӿڣ����Կ���һ�¶Դ���ֱ�ӵ���Operation()
       �����ˡ�ʹ���û��Ե����������϶����ʹ�þ���һ���ԡ���
     */
	//����һ��Component���󣬱���Google��˾
	Component* Google=new Composite();
	//���������Ӳ��ţ����񲿣����²�������������Ӫ�������۲�������ӽ�Component����
	Leaf* FinancialDepart=new Leaf();
	Leaf* HumanResource=new Leaf();
	Leaf* TechDepart=new Leaf();
	Leaf* SupportDepart=new Leaf();
	Leaf* SalesDepart=new Leaf();
	//��Ӳ��������Ϊ��������
	Google->Add(FinancialDepart);
	Google->Add(HumanResource);
	Google->Add(TechDepart);
	Google->Add(SupportDepart);
	Google->Add(SalesDepart);
	//��ʾ������ϵ
	cout<<"   Google\n";
	Google->Operation();
	for(int i=0;i<5;i++){
		Google->GetChild(i);
		//cout

	}
	cout<<"\tFinancialDepart\n"<<"\tHumanResource\n"<<"\tTechDepart\n"<<"\tSupportDepart\n"<<"\tSalesDepart\n";cout<<"   TechDepart\n";
	//Ҷ�ӽڵ��Operation()����
	TechDepart->Operation();cout<<"   Google\n\n";

	//�������������
	Leaf* Architecture=new Leaf();
	Leaf* Algorithm=new Leaf();
	Leaf* UIDesign=new Leaf();
	Leaf* Database=new Leaf();
	TechDepart->Add(Architecture);
	TechDepart->Add(Algorithm);
	TechDepart->Add(UIDesign);
	TechDepart->Add(Database);
	/*��ʾ������ϵ /**/cout<<"     TechDepart\n";cout<<"     �ò��Ű��������Ӳ��� >>> "<<endl;
	TechDepart->Operation();
	/*GetChild*/ for(int i=0;i<3;i++){TechDepart->Operation();}
	for(int i=0;i<4;i++){
		TechDepart->GetChild(i);
		//cout<<

	}cout<<"\tArchitecture\n"<<"\tAlgorithm\n"<<"\tUIDesign\n"<<"\tDatabase\n";
	
	//�Ƴ����
	Google->Remove(SalesDepart);
	//�Ƴ�������
	cout<<"\n�Ƴ���\n   Google\n";
	Google->Operation();
	for(int i=0;i<4;i++){
		Google->GetChild(i);
		//cout

	}
	cout<<"\tFinancialDepart\n"<<"\tHumanResource\n"<<"\tTechDepart\n"<<"\tSupportDepart\n";

	//��������Ƴ����
	TechDepart->Remove(Algorithm);
	//�Ƴ�������/*��ʾ������ϵ /**/cout<<"     TechDepart\n";
	cout<<"\n�Ƴ���\n     TechDepart\n";   /*GetChild*/ cout<<"     �ò��Ű��������Ӳ��� >>> "<<endl;for(int i=0;i<2;i++){TechDepart->Operation();}
	TechDepart->Operation();
	for(int i=0;i<3;i++){
		TechDepart->GetChild(i);
		//cout

	}
	cout<<"\tArchitecture\n"<<"\tUIDesign\n"<<"\tDatabase\n";

	system("pause");
	return 0;
}

