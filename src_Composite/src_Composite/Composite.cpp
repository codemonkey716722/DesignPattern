//Composite.h

#include"Composite.h"
#include<iostream>
using namespace std;

Component::Component(){}
Component::~Component(){}
void Component::Add(Component* com){
	cout<<"  Component Added Successfully!"<<endl;
}
void Component::Remove(Component*com){
	cout<<"  Component Removed Successfully!"<<endl;
}
void Component::Operation(){
	cout<<"    该部门隶属于 >>> "<<endl;
}
Component* Component::GetChild(int index){
	return NULL;
}
Leaf::Leaf(){
	//
}
Leaf::~Leaf(){
	//
}
void Leaf::Operation(){
	cout<<"      该子部门隶属于 >>>"<<endl;
}
Composite::Composite(){
	//
}
Composite::~Composite(){
	//
}
void Composite::Add(Component* com){
	this->m_ComVec.push_back(com);
	cout<<"  Composite Added Succesfully!"<<endl;
}
void Composite::Remove(Component* com){
	vector<Component*>::iterator itr=this->m_ComVec.begin();
	vector<Component*>::iterator temp_itr=this->m_ComVec.begin();
	while(itr!=this->m_ComVec.end()){
		if(*itr==com)break;
		else itr++;
	}
	temp_itr=itr;
	this->m_ComVec.erase(temp_itr);
	cout<<"  Composite Removed Succesfully!"<<endl;
}
void Composite::Operation(){
	cout<<"    该部门包含以下子部门 >>> "<<endl;
	vector<Component*>::iterator iter=this->m_ComVec.begin();
	for(;iter!=this->m_ComVec.end();iter++){
		(*iter)->Operation();
	}
}
Component* Composite::GetChild(int index){
	if(index<0 || index>this->m_ComVec.size()){
		return NULL;
	}
	return this->m_ComVec[index];
	//cout<<"  Get "<<index<<" ChildNode Successfully!"<<endl;
}