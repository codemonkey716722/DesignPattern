#include"Observer.h"
#include<iostream>
using namespace std;
int main(){

	 //创建被观察对象Observer对象
	 Observer *p1 = new ConcreateObserver;
     Observer *p2 = new ConcreateObserver;
     Observer *p3 = new ConcreateObserver;
     Observer *p4 = new ConcreateObserver;
     Observer *p5 = new ConcreateObserver;

     //创建一个观察主体Subject对象
     Subject* p = new ConcreateSubject;
	 //绑定Observer
     p->Attach(p1);
     p->Attach(p3);
     p->Attach(p4);
     p->Attach(p2);
     p->Attach(p5);cout<<endl;

	 /*改变观察者的状态*/cout<<"  Subject State Changed!\n";
     p->SetState(6666);					cout<<endl;
	 //Notify()操作，让每一个Observer被观察者都响应
     p->Notify();
	 //输出结果
	 cout<<endl;
     //移除观察器


     p->Detach(p1);
     p->SetState(10);cout<<endl;
     p->Notify();
 
     delete p;

	 system("pause");
	 return 0;
}