#include"Observer.h"
#include<iostream>
using namespace std;
int main(){

	 //�������۲����Observer����
	 Observer *p1 = new ConcreateObserver;
     Observer *p2 = new ConcreateObserver;
     Observer *p3 = new ConcreateObserver;
     Observer *p4 = new ConcreateObserver;
     Observer *p5 = new ConcreateObserver;

     //����һ���۲�����Subject����
     Subject* p = new ConcreateSubject;
	 //��Observer
     p->Attach(p1);
     p->Attach(p3);
     p->Attach(p4);
     p->Attach(p2);
     p->Attach(p5);cout<<endl;

	 /*�ı�۲��ߵ�״̬*/cout<<"  Subject State Changed!\n";
     p->SetState(6666);					cout<<endl;
	 //Notify()��������ÿһ��Observer���۲��߶���Ӧ
     p->Notify();
	 //������
	 cout<<endl;
     //�Ƴ��۲���


     p->Detach(p1);
     p->SetState(10);cout<<endl;
     p->Notify();
 
     delete p;

	 system("pause");
	 return 0;
}