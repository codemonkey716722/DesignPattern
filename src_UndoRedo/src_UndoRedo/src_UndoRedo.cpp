// src_UndoRedo.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include<iostream>
#include "Command.cpp"  
  
using namespace std;
//ģ�������ַ���,Ȼ���������ַ�������undo redo����  
//�����¼����������¼,��:������undo �� redo �������ַ������ݸı�Ҳ���¼,�������������undo ���� redo �������ַ���ʱ ��redo��ռ���  
//����Ϊ����ʷ��¼���޸�ֵ����Ϊ�����µ�ֵ������Ҫ��redo  
int main()  
{  
    //Ĭ��û�������ַ��������ǿգ�����Ϊ����ʾ��ֵһ��������ַ���  
    Commander *p = new Commander( new InputCommand( "  ����ʼ״̬��\n" ) );  
  
    //���� 
    p->ExecuteCommand( new InputCommand( "    ��ҹ˼ ���\n" ) );  
    //����  
    p->ExecuteCommand( new InputCommand( "  �� ǰ �� �� �⣬\n" ) );  
    //����  
    p->ExecuteCommand( new InputCommand( "  �� �� �� �� ˪��\n" ) );  
	//����  
    p->ExecuteCommand( new InputCommand( "  �� ͷ �� �� �£�\n" ) );  
	//����  
    p->ExecuteCommand( new InputCommand( "  �� ͷ ˼ �� �硣\n" ) );  
  
    //ִ��һ��undo ������������
    p->Undo();  
    //ִ��һ��undo �������ڶ���
    p->Undo();  
	//ִ��һ��undo ��������һ��
    p->Undo();   
  
    //ִ��һ��undo ��������һ��
    p->Undo();  
  
    //ִ��һ��undo ������������ ����ʼ״̬��  
    p->Undo();  
  
    //ִ��ʧ�ܣ���Ϊ�Ѿ�undo ����ԭʼ����������� Redo() 
    p->Undo();cout<<endl;  
  
    //ִ��һ��redo ��������ͷ 
    p->Redo();  
    //ִ��һ��redo ��������һ��  
    p->Redo();  
    //ִ��һ��redo �������ڶ���
    p->Redo(); 
	//ִ��һ��redo ������������
    p->Redo();  
	
	cout<<"   ����µ�Undo��Redo��¼\n";
    //redo���м��������ַ��� ��  �� ͷ ˼ �� �硣�� ���ǵ�ǰ�ַ���  
    p->ExecuteCommand( new InputCommand( "  �� ͷ ˼ �� �硣\n" ) );  
  
    //ִ��һ��undo ����
    p->Undo();  
  
    //ִ��һ��redo ����
    p->Redo();  
  
    //ִ��һ��redo ����
    p->Redo();  
  
    // Redoִ��ʧ�ܣ��Ѿ����������  
    p->Redo();  



	cout<<endl;
    delete p;  
	system("pause");
    return 0;  
}  

