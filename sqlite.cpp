// sqlite.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "sqlite.h"
#include "sqlite3.h"
#include <iostream>
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

//open a database with its name
void open(sqlite3 *db, char *name);
//close database connect
void close(sqlite3 *db);
//create a table in a database
void create(sqlite3 *db, char *tbName);
//deal the commond
void excute(sqlite3 *db,const char *commond, char *errMsg = 0);
//insert all ctrl infomation into its table,one to one
void insert(sqlite3 *db, char *tbName);

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO:  ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����:  MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO:  �ڴ˴�ΪӦ�ó������Ϊ��д���롣
			sqlite3 *db;
			sqlite3_open("WMS.db",&db);
			create(db, "a");
			close(db);
		}
	}
	else
	{
		// TODO:  ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����:  GetModuleHandle ʧ��\n"));
		nRetCode = 1;
	}
	system("pause");
	return nRetCode;
}
//open a database with its name
//void open(sqlite3 *db, char *name)
//{
//	bool op = sqlite3_open(name, &db);
//	if (op == true)
//		cout << "open database success!" << endl;
//	else
//		cout << "open database faild!" << sqlite3_errmsg(db) << endl;
//}
//close database connect
void close(sqlite3 *db)
{
	int err = sqlite3_close(db);
	if (err == SQLITE_OK)
		cout << "exit!" << endl;
	else
	{
		cout << "some err happend !" << sqlite3_errmsg(db) << endl;
		//exit(0);
	}
	
		
}
//create a table in a database
void create(sqlite3 *db, char *tbName)
{
	string tb = tbName;
	tb = "CREATE TABLE " + tb + "(ID INT PRIMARY KEY NOT NULL,\
								ctrName	TEXT NOT NULL,\
								ctrText	TEXT NULL,\
								l	INT NOT NULL,\
								t	INT NOT NULL,\
								r	INT NOT NULL,\
								b	INT NOT NULL);";
	excute(db, tb.c_str());
	tb.empty();
}
//deal the commond
void excute(sqlite3 *db,const char *commond,char *errMsg)
{
	int err = sqlite3_exec(db, commond, NULL, NULL, &errMsg);
	if (err == SQLITE_OK)
		cout << "commond run success" << endl;
	else
		cout << "error in commond run!-->" << errMsg << endl;
	sqlite3_free(errMsg);
}
//insert all ctrl infomation into its table,one to one
void insert(sqlite3 *db, char *tbName)
{

}