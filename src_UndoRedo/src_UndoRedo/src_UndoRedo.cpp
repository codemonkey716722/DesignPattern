// src_UndoRedo.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include "Command.cpp"  
  
using namespace std;
//模拟输入字符串,然后对输入的字符串进行undo redo操作  
//这里记录的是完整记录,即:即便在undo 或 redo 过程中又发生数据改变也会记录,如果不想这样在undo 或者 redo 输入新字符串时 将redo清空即可  
//即认为在历史记录中修改值被认为是最新的值，不需要再redo  
int main()  
{  
    //默认没有输入字符串可以是空，这里为了演示赋值一个特殊的字符串  
    Commander *p = new Commander( new InputCommand( "  【起始状态】\n" ) );  
  
    //输入 
    p->ExecuteCommand( new InputCommand( "    静夜思 李白\n" ) );  
    //输入  
    p->ExecuteCommand( new InputCommand( "  窗 前 明 月 光，\n" ) );  
    //输入  
    p->ExecuteCommand( new InputCommand( "  疑 似 地 上 霜。\n" ) );  
	//输入  
    p->ExecuteCommand( new InputCommand( "  举 头 望 明 月，\n" ) );  
	//输入  
    p->ExecuteCommand( new InputCommand( "  低 头 思 故 乡。\n" ) );  
  
    //执行一次undo 撤销到第三句
    p->Undo();  
    //执行一次undo 撤销到第二句
    p->Undo();  
	//执行一次undo 撤销到第一句
    p->Undo();   
  
    //执行一次undo 撤销到第一句
    p->Undo();  
  
    //执行一次undo 撤销到最初情况 【起始状态】  
    p->Undo();  
  
    //执行失败，因为已经undo 到最原始情况，不能再 Redo() 
    p->Undo();cout<<endl;  
  
    //执行一次redo 重做到开头 
    p->Redo();  
    //执行一次redo 重做到第一句  
    p->Redo();  
    //执行一次redo 重做到第二句
    p->Redo(); 
	//执行一次redo 重做到第三句
    p->Redo();  
	
	cout<<"   添加新的Undo和Redo记录\n";
    //redo后中间输入新字符串 “  低 头 思 故 乡。” 覆盖当前字符串  
    p->ExecuteCommand( new InputCommand( "  低 头 思 故 乡。\n" ) );  
  
    //执行一次undo 撤销
    p->Undo();  
  
    //执行一次redo 重做
    p->Redo();  
  
    //执行一次redo 重做
    p->Redo();  
  
    // Redo执行失败，已经到最新情况  
    p->Redo();  



	cout<<endl;
    delete p;  
	system("pause");
    return 0;  
}  

