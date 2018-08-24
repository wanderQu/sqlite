// sqlite.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "sqlite3.h"
#include <iostream>
#include <string>
#include <Windows.h>
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
void create(sqlite3 *db, string tbName);
//deal the commond
bool excute(sqlite3 *db,const char *commond, char *errMsg = 0);
//insert all ctrl infomation into its table,one to one
void insert(sqlite3 *db, string tbName);
void insert(sqlite3 *db);
//combin the commond
string combin_Create(string s);
string combin_Create(string s,string s2);

string combin_Insert(string tbName, string value);
string getName(int i);
string getData(int i);
string GetTbName(int i);
string string_To_UTF8(const string & str);
string UTF8_To_string(const string & str);
int a = 0;
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
			//cout << sqlite3_mprintf("%s", "��ú�ɽ�Ƕȿ�");
			sqlite3 *db;
			int type;
			cout << "CTRL 0,LIST 1:";
			cin >> type;
			cout << endl;
			switch (type)
			{
			case 0:
				sqlite3_open("DataBase.db", &db);
				insert(db); break;
			case 1:
				sqlite3_open("Data.db", &db);
				string s,s2;
				char *err;
				for (int i = 0; i < 33; i++)
				{
					s2 = getName(i);
					s = combin_Create(s2, GetTbName(i));
					s = string_To_UTF8(s);

					if (excute(db, s.c_str(), err) == true)
					{
						cout << "create table " << s2 << " successed!" << endl;
					}
					else
						cout << err << endl;
				}
			}
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
		cout <<"some err happend !" << sqlite3_errmsg(db) << endl;
		//exit(0);
	}
	
		
}
//create a table in a database
void create(sqlite3 *db, string tbName)
{
	string tb;
	tb = combin_Create(tbName);
	if (excute(db, tb.c_str()))
		cout << "\ncreate " << tbName << " success!" << endl;
	else
		cout << "\ncreate" << tbName << " failed" << endl;
	tb.empty();
}
//deal the commond
bool excute(sqlite3 *db,const char *commond,char *errMsg)
{
	int err = sqlite3_exec(db, commond, NULL, NULL, &errMsg);
	if (err == SQLITE_OK)
		return true;
	else
	{
		cout << errMsg << "->";
		sqlite3_free(errMsg);
		return false;
	}
	sqlite3_free(errMsg);
}
//insert all ctrl infomation into its table,one to one
void insert(sqlite3 *db, string tbName)
{

}
string combin_Create(string s, string s2)
{
	s = "CREATE TABLE " + s + "(" + s2 + ");";
	return s;
}
string combin_Create(string tbName)
{
	string tb;
	tb = "CREATE TABLE " + tbName + "(ID INT PRIMARY KEY NOT NULL,\
								ctrName	TEXT NOT NULL,\
								ctrText	TEXT NULL,\
								l	INT NOT NULL,\
								t	INT NOT NULL,\
								r	INT NOT NULL,\
								b	INT NOT NULL);";
	return tb;
}
string combin_Insert(string tbName, string value)
{
	string str;
	str = "INSERT INTO " + tbName + "(ID,ctrName,ctrText,l,t,r,b)VALUES" + value;
	return str;
}
string getName(int i)
{
	switch (i)
	{
	case 0:return "proOrder"; break;
	case 1:return "proQuery"; break;
	case 2:return "proTrack"; break;
	case 3:return "proReturn"; break;
	case 4:return "proIntel"; break;

	case 5:return "distriLs"; break;
	case 6:return "distriQuery"; break;
	case 7:return "distriTrack"; break;

	case 8:return "wareRequis"; break;
	case 9:return "wareIn"; break;
	case 10:return "wareOut"; break;
	case 11:return "wareStock"; break;
	case 12:return "wareChng"; break;
	case 13:return "wareQuery"; break;

	case 14:return "manaCus"; break;
	case 15:return "manaSup"; break;
	case 16:return "manaGoods"; break;
	case 17:return "manaWare"; break;
	case 18:return "manaAddress"; break;

	case 19:return "dataVoucher"; break;
	case 20:return "dataPayment"; break;
	case 21:return "dataVerification"; break;
	case 22:return "dataOtherIncome"; break;
	case 23:return "dataOtherExpend"; break;
	case 24:return "dataTransfer"; break;

	case 25:return "assIncome"; break;
	case 26:return "assExpense"; break;
	case 27:return "assPayable"; break;
	case 28:return "assReceive"; break;
	case 29:return "assCusState"; break;
	case 30:return "assVendorState"; break;
	case 31:return "assOtherInOut"; break;
	case 32:return "assIncomeState"; break;

	case 33:return "setPermis"; break;
	case 34:return "setLog"; break;

	}
	return NULL;
}
//ֱ����ѭ���ķ�ʽ�����������ݣ�������Ҫ���ǻ����Щ����
void insert(sqlite3 *db)
{
	string str,str2;
	for (a; a < 35; a++)
	{
		str2 = getName(a);
		create(db, str2);
		str = combin_Insert(str2, getData(a));
		str = string_To_UTF8(str);
		if (excute(db, str.c_str()))
			cout << "insert data into TABLE " << str2 << " successed!" << endl;
		else
			cout << "insert data into TABLE " << str2 << " failed!" << endl;
	}
	str.empty();
	str2.empty();
}
void UpdateData(char *tbName = 0, char *key = 0)
{
	////ID,ctrNamee,ctrText,l,t,r,b
	//string s;
	//if (tbName == 0)
	//	for (int i = 0; i < 35; i++)
	//		s = "UPDATE " + getName(i) + "SET ";
}
string getData(int i)
{
	string str[] =
	{
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,570,35),(5,'text','��Ӧ�����',590,10,680,30),(6,'combo','',690,10,800,110),(7,'text','��Ӧ��',820,10,875,30),(8,'combo','',885,10,1005,110),(9,'bt','��ѯ',1025,10,1105,35),(10,'text','',0,60,150,80),(11,'bt','����',725,50,805,75),(12,'bt','����',825,50,905,75),(13,'bt','��ӡ',925,50,1005,75),(14,'bt','ɾ��',1025,50,1105,75),(15,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'text','��Ӧ�����',600,10,690,30),(6,'combo','',700,10,810,110),(7,'text','��Ӧ��',830,10,885,30),(8,'combo','',895,10,1005,110),(9,'bt','��ѯ',1025,10,1105,35),(10,'text','',0,60,150,80),(11,'bt','����',805,50,885,75),(12,'bt','��ӡ',925,50,1005,75),(13,'bt','ɾ��',1025,50,1105,75),(14,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'text','��Ӧ�����',600,10,690,30),(6,'combo','',700,10,810,110),(7,'text','��Ӧ��',830,10,885,30),(8,'combo','',895,10,1005,110),(9,'bt','��ѯ',1025,10,1105,35),(10,'text','',0,60,150,80),(11,'bt','����',825,50,905,75),(12,'bt','��ӡ',925,50,1005,75),(13,'bt','ɾ��',1025,50,1105,75),(14,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'text','��Ӧ�����',600,10,690,30),(6,'combo','',700,10,810,110),(7,'text','��Ӧ��',830,10,885,30),(8,'combo','',895,10,1005,110),(9,'bt','��ѯ',1025,10,1105,35),(10,'text','',0,60,150,80),(11,'bt','����',725,50,805,75),(12,'bt','����',825,50,905,75),(13,'bt','��ӡ',925,50,1005,75),(14,'bt','ɾ��',1025,50,1105,75),(15,'ls','',0,80,1120,600);",
		"(0,'text','�ֿ�',0,10,30,30),(1,'combo','',50,10,125,110),(2,'text','��Ʒ���',145,10,215,30),(3,'combo','',225,10,335,110),(4,'text','��Ʒ����',355,10,425,30),(5,'combo','',435,10,545,110),(6,'bt','��ѯ',565,10,645,35),(7,'bt','���ù�ʽ',665,10,745,35),(8,'bt','�·��ɹ�����',765,10,875,35),(9,'ls','',0,60,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'text','�ͻ����',600,10,670,30),(6,'combo','',680,10,790,110),(7,'text','�ͻ�',810,10,840,30),(8,'combo','',850,10,960,110),(9,'bt','��ѯ',980,10,1060,35),(10,'text','',0,60,150,80),(11,'bt','����',680,50,760,75),(12,'bt','����',780,50,860,75),(13,'bt','��ӡ',880,50,960,75),(14,'bt','ɾ��',980,50,1060,75),(15,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'text','�ͻ����',600,10,670,30),(6,'combo','',680,10,790,110),(7,'text','�ͻ�',810,10,840,30),(8,'combo','',850,10,960,110),(9,'bt','��ѯ',980,10,1060,35),(10,'text','',0,60,150,80),(11,'bt','����',760,50,840,75),(12,'bt','��ӡ',880,50,960,75),(13,'bt','ɾ��',980,50,1060,75),(14,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'text','�ͻ����',600,10,670,30),(6,'combo','',680,10,790,110),(7,'text','�ͻ�',810,10,840,30),(8,'combo','',850,10,960,110),(9,'bt','��ѯ',980,10,1060,35),(10,'text','',0,60,150,80),(11,'bt','����',760,50,840,75),(12,'bt','��ӡ',880,50,960,75),(13,'bt','ɾ��',980,50,1060,75),(14,'ls','',0,80,1120,600);",
		"(0,'text','�ֿ�',0,10,30,30),(1,'combo','',50,10,125,110),(2,'text','��Ʒ���',145,10,215,30),(3,'combo','',225,10,335,110),(4,'text','��Ʒ����',355,10,425,30),(5,'combo','',435,10,545,110),(6,'bt','���',565,10,645,35),(7,'ls','',0,50,1120,300),(8,'text','�ֿ�',0,310,30,330),(9,'combo','',50,310,125,410),(10,'bt','����',690,310,770,335),(11,'bt','��ӡ',790,310,870,335),(12,'bt','ɾ��',890,310,970,335),(13,'bt','ȷ��',990,310,1070,335),(14,'ls','',0,350,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'bt','��ѯ',600,10,680,35),(6,'text','',0,60,150,75),(7,'bt','����',300,50,380,75),(8,'bt','����',400,50,480,75),(9,'bt','��ӡ',500,50,580,75),(10,'bt','ɾ��',600,50,680,75),(11,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'text','',0,60,150,80),(6,'bt','����',690,50,770,75),(7,'bt','����',790,50,870,75),(8,'bt','��ӡ',890,50,970,75),(9,'bt','ɾ��',990,50,1070,75),(10,'ls','',0,80,1120,600);",
		"(0,'text','�ֿ�',0,10,30,30),(1,'combo','',40,10,115,110),(2,'text','��Ʒ���',135,10,205,30),(3,'combo','',215,10,325,110),(4,'bt','��ѯ',345,10,425,35),(5,'bt','����',445,10,525,35),(6,'bt','��ӡ',545,10,625,35),(7,'ls','',0,60,1120,600);",
		"(0,'text','�ֿ�',0,10,30,30),(1,'combo','',40,10,115,110),(2,'text','��Ʒ���',135,10,205,30),(3,'combo','',215,10,325,110),(4,'text','��Ʒ����',345,10,415,30),(5,'combo','',425,10,535,110),(6,'text','��Ʒ���',555,10,625,30),(7,'combo','',635,10,745,110),(8,'bt','��ѯ',765,10,845,35),(9,'bt','�޸�',865,10,945,35),(10,'bt','ȷ��',965,10,1045,35),(11,'ls','',0,40,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��Ʒ���',220,10,290,30),(2,'combo','',300,10,410,110),(3,'text','��Ʒ����',430,10,500,30),(4,'combo','',510,10,620,110),(5,'text','��Ʒ���',640,10,710,30),(6,'combo','',720,10,830,110),(7,'bt','��ѯ',850,10,930,35),(8,'bt','����',890,50,970,75),(9,'bt','��ӡ',990,50,1070,75),(10,'ls','',0,80,1120,600);",
		"(0,'text','�ͻ����',0,10,70,30),(1,'combo','',80,10,190,110),(2,'bt','����',790,10,870,35),(3,'bt','����',890,10,970,35),(4,'bt','ɾ��',990,10,1070,35),(5,'ls','',0,60,1120,600);",
		"(0,'text','��Ӧ�����',0,10,90,30),(1,'combo','',100,10,210,110),(2,'bt','����',790,10,870,35),(3,'bt','����',890,10,970,35),(4,'bt','ɾ��',990,10,1070,35),(5,'ls','',0,40,1120,600);",
		"(0,'text','��Ʒ���',0,10,70,30),(1,'combo','',80,10,190,110),(2,'bt','����',790,10,870,35),(3,'bt','����',890,10,970,35),(4,'bt','ɾ��',990,10,1070,35),(5,'ls','',0,40,1120,600);",
		"(0,'text','�ֿ�',0,10,30,30),(1,'combo','',40,10,115,110),(2,'bt','����',790,10,870,35),(3,'bt','����',890,10,970,35),(4,'bt','ɾ��',990,10,1070,35),(5,'ls','',0,40,1120,600);",
		"(0,'bt','����',790,10,870,35),(1,'bt','����',890,10,970,35),(2,'bt','ɾ��',990,10,1070,35),(3,'ls','',0,40,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,280,30),(2,'time','',300,10,420,35),(3,'text','��',430,10,440,30),(4,'time','',450,10,570,35),(5,'text','��Ӧ�����',590,10,680,30),(6,'combo','',690,10,800,110),(7,'text','��Ӧ��',820,10,875,30),(8,'combo','',885,10,995,110),(9,'bt','��ѯ',1015,10,1095,35),(10,'text','',0,60,150,80),(11,'bt','����',715,50,795,75),(12,'bt','����',815,50,895,75),(13,'bt','��ӡ',915,50,995,75),(14,'bt','ɾ��',1015,50,1095,75),(15,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'text','��Ӧ�����',600,10,690,30),(6,'combo','',700,10,810,110),(7,'text','��Ӧ��',830,10,885,30),(8,'combo','',895,10,1005,110),(9,'bt','��ѯ',1025,10,1105,35),(10,'text','',0,60,150,80),(11,'bt','����',725,50,805,75),(12,'bt','����',825,50,905,75),(13,'bt','��ӡ',925,50,1005,75),(14,'bt','ɾ��',1025,50,1105,75),(15,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'text','�ͻ�',600,10,630,30),(6,'combo','',640,10,750,110),(7,'text','��Ӧ��',770,10,825,30),(8,'combo','',835,10,945,110),(9,'bt','��ѯ',965,10,1045,35),(10,'text','',0,60,150,80),(11,'ls','',0,80,1120,300),(12,'text','',0,300,150,320),(13,'bt','��ӡ',890,310,970,335),(14,'bt','ȷ��',990,310,1070,335),(15,'ls','',0,350,1120,580),(16,'text','',0,580,150,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'bt','��ѯ',600,10,680,35),(6,'bt','����',700,10,780,35),(7,'bt','����',800,10,880,35),(8,'bt','��ӡ',900,10,980,35),(9,'bt','ɾ��',1000,10,1080,35),(10,'text','',0,60,150,80),(11,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'bt','��ѯ',600,10,680,35),(6,'bt','����',700,10,780,35),(7,'bt','����',800,10,880,35),(8,'bt','��ӡ',900,10,980,35),(9,'bt','ɾ��',1000,10,1080,35),(10,'text','',0,60,150,80),(11,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'bt','��ѯ',600,10,680,35),(6,'bt','����',700,10,780,35),(7,'bt','����',800,10,880,35),(8,'bt','��ӡ',900,10,980,35),(9,'bt','ȷ��',1000,10,1080,35),(10,'text','',0,60,150,80),(11,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'bt','��ѯ',600,10,680,35),(6,'bt','����',700,10,780,35),(7,'bt','��ӡ',800,10,880,35),(8,'text','',0,60,150,80),(9,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','��������',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','��',440,10,450,30),(4,'time','',460,10,580,35),(5,'bt','��ѯ',600,10,680,35),(6,'bt','����',700,10,780,35),(7,'bt','��ӡ',800,10,880,35),(8,'text','',0,60,150,80),(9,'ls','',0,80,1120,600);",
		"(0,'text','��������',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','��',220,10,230,30),(3,'time','',240,10,360,35),(4,'text','��Ӧ�����',380,10,470,30),(5,'combo','',480,10,590,110),(6,'text','��Ӧ��',610,10,665,30),(7,'combo','',675,10,785,110),(8,'bt','��ѯ',805,10,885,35),(9,'bt','��ӡ',890,50,970,75),(10,'bt','����',990,50,1070,75),(11,'text','',0,60,150,80),(12,'ls','',0,80,1120,580),(13,'text','',0,580,150,600);",
		"(0,'text','��������',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','��',220,10,230,30),(3,'time','',240,10,360,35),(4,'text','�ͻ����',380,10,450,30),(5,'combo','',460,10,570,110),(6,'text','�ͻ�',590,10,620,30),(7,'combo','',630,10,740,110),(8,'bt','��ѯ',760,10,840,35),(9,'bt','��ӡ',890,40,970,65),(10,'bt','����',990,40,1070,65),(11,'text','',0,50,150,65),(12,'ls','',0,70,1120,580),(13,'text','',0,580,150,600);",
		"(0,'text','��������',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','��',220,10,230,30),(3,'time','',240,10,360,35),(4,'text','�ͻ����',380,10,450,30),(5,'combo','',460,10,570,110),(6,'text','�ͻ�',590,10,620,30),(7,'combo','',630,10,740,110),(8,'bt','��ѯ',760,10,840,35),(9,'bt','��ӡ',890,50,970,75),(10,'bt','����',990,50,1070,75),(11,'text','',0,60,150,80),(12,'ls','',0,80,1120,580),(13,'text','',0,580,150,600);",
		"(0,'text','��������',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','��',220,10,230,30),(3,'time','',240,10,360,35),(4,'text','��Ӧ�����',380,10,470,30),(5,'combo','',480,10,590,110),(6,'text','��Ӧ��',610,10,665,30),(7,'combo','',675,10,785,110),(8,'bt','��ѯ',805,10,885,35),(9,'bt','��ӡ',890,50,970,75),(10,'bt','����',990,50,1070,75),(11,'text','',0,60,150,80),(12,'ls','',0,80,1120,580),(13,'text','',0,580,150,600);",
		"(0,'text','��������',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','��',220,10,230,30),(3,'time','',240,10,360,35),(4,'bt','��ѯ',380,10,460,35),(5,'bt','����',480,10,560,35),(6,'bt','��ӡ',580,10,660,35),(7,'text','',0,60,150,80),(8,'ls','',0,80,1120,600);",
		"(0,'text','����',0,10,30,30),(1,'combo','',50,10,150,110),(2,'bt','����',170,10,250,35),(3,'bt','��ӡ',270,10,350,35),(4,'ls','',0,60,1120,600);",
		"(0,'text','Ա�����',0,10,70,30),(1,'combo','',80,10,190,110),(2,'text','Ա�����',210,10,280,30),(3,'combo','',290,10,400,110),(4,'bt','����',420,10,500,35),(5,'ls','',0,60,1120,600);",
		"(0,'text','����',0,10,30,30),(1,'time','',50,10,170,35),(2,'text','��',180,10,190,30),(3,'time','',200,10,320,35),(4,'text','Ա��',340,10,370,30),(5,'combo','',380,10,490,110),(6,'text','��������',510,10,570,30),(7,'combo','',580,10,690,110),(8,'bt','��ѯ',710,10,790,35),(9,'text','',0,60,150,80),(10,'ls','',0,80,1120,600);"
	};
	return str[i];

}
string GetTbName(int i)
{

	string str[] =
	{
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ɹ����� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,Ԥ�Ƶ���ʱ�� TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ɹ����� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,Ԥ�Ƶ���ʱ�� TEXT NOT NULL,�ɹ�״̬ TEXT NOT NULL,����״̬ TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,�ɹ����� TEXT NOT NULL,�ɹ�������� TEXT NOT NULL,��Ӧ�� TEXT NOT NULL,�ɹ�״̬ TEXT NOT NULL,���� TEXT NOT NULL,���� TEXT NOT NULL,�ɹ��� TEXT NOT NULL,δ������� TEXT NOT NULL,Ԥ�Ƶ���ʱ�� TEXT NOT NULL,������ʱ�� TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�˻�ʱ�� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒԭ�������� TEXT NOT NULL,��Ʒ��� TEXT NOT NULL,�˻�ԭ�� TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,��Ʒ TEXT NOT NULL,�ڿ��� TEXT NOT NULL,��Ϳ�� TEXT NOT NULL,����ɹ��� TEXT NOT NULL,�ɹ��ڶ��� TEXT NOT NULL",

		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�������� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,Ԥ�ƽ���ʱ�� TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�������� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,Ԥ�ƽ���ʱ�� TEXT NOT NULL,����״̬ TEXT NOT NULL,�տ�״̬ TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,�������� TEXT NOT NULL,���Ͷ������ TEXT NOT NULL,��Ӧ�� TEXT NOT NULL,����״̬ TEXT NOT NULL,���� TEXT NOT NULL,���� TEXT NOT NULL,�ɹ��� TEXT NOT NULL,δ�������� TEXT NOT NULL,Ԥ�ƽ���ʱ�� TEXT NOT NULL,������ʱ�� TEXT NOT NULL",

		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�������� TEXT NOT NULL,��Ʒ��� TEXT NOT NULL,���� TEXT NOT NULL,��� TEXT NOT NULL,��λ TEXT NOT NULL,�����ֿ� TEXT NOT NULL,����ֿ� TEXT NOT NULL,�Ƶ��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�������� TEXT NOT NULL,�ֿ� TEXT NOT NULL,��Ʒ��� TEXT NOT NULL,��Ʒ TEXT NOT NULL,���� TEXT NOT NULL,��� TEXT NOT NULL,��Ӧ�� TEXT NOT NULL,�Ƶ��� TEXT NOT NULL,��ע TEXT NULL,��ӡ���� TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�������� TEXT NOT NULL,�ֿ� TEXT NOT NULL,��Ʒ��� TEXT NOT NULL,��Ʒ TEXT NOT NULL,���� TEXT NOT NULL,��� TEXT NOT NULL,�ͻ� TEXT NOT NULL,�Ƶ��� TEXT NOT NULL,��ע TEXT NULL,��ӡ���� TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�������� TEXT NOT NULL,�ֿ� TEXT NOT NULL,��Ʒ��� TEXT NOT NULL,��Ʒ TEXT NOT NULL,��� TEXT NOT NULL,��λ TEXT NOT NULL,���� TEXT NOT NULL,�Ƶ��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�������� TEXT NOT NULL,�ֿ� TEXT NOT NULL,��Ʒ��� TEXT NOT NULL,��Ʒ TEXT NOT NULL,���� TEXT NOT NULL,�Ƶ��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���� TEXT NOT NULL,�ֿ� TEXT NOT NULL,��Ʒ��� TEXT NOT NULL,��Ʒ TEXT NOT NULL,��� TEXT NOT NULL,��λ TEXT NOT NULL,���� TEXT NOT NULL",

		"ID INT PRIMARY KEY NOT NULL,�ͻ���� TEXT NOT NULL,�ͻ���� TEXT NOT NULL,�ͻ����� TEXT NOT NULL,��ϵ�� TEXT NOT NULL,��ϵ��ʽ TEXT NOT NULL,�˻� TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,��Ӧ�̱�� TEXT NOT NULL,��Ӧ����� TEXT NOT NULL,��Ӧ������ TEXT NOT NULL,��ϵ�� TEXT NOT NULL,��ϵ��ʽ TEXT NOT NULL,�˻� TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,��Ʒ��� TEXT NOT NULL,��Ʒ��� TEXT NOT NULL,��Ʒ TEXT NOT NULL,�ֿ� TEXT NOT NULL,��Ʒ���� TEXT NOT NULL,���� TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,�ֿ��� TEXT NOT NULL,�ֿ����� TEXT NOT NULL,�ֿ�״̬ TEXT NOT NULL",
		"ID INT PRIMARY KEY NOT NULL,���͵�ַ TEXT NOT NULL,��ϵ�� TEXT NOT NULL,��ϵ��ʽ TEXT NOT NULL,�������� TEXT NOT NULL",

		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ͻ� TEXT NOT NULL,�ʽ���� TEXT NOT NULL,�տ��� TEXT NOT NULL,�Żݽ�� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,��Ӧ�� TEXT NOT NULL,�ʽ���� TEXT NOT NULL,������ TEXT NOT NULL,�Żݽ�� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�������� TEXT NOT NULL,�Ѻ������ TEXT NOT NULL,δ������� TEXT NOT NULL,���κ������ TEXT NOT NULL,�ʽ���� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ʽ���� TEXT NOT NULL,��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ʽ���� TEXT NOT NULL,��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,ת���˻� TEXT NOT NULL,ת���˻� TEXT NOT NULL,��� TEXT NOT NULL,��ע TEXT NULL",

		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ʽ���� TEXT NOT NULL,��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ʽ���� TEXT NOT NULL,��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,��Ӧ�� TEXT NOT NULL,Ӧ���˿��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ͻ� TEXT NOT NULL,Ӧ���˿��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ͻ� TEXT NOT NULL,�������� TEXT NOT NULL,���ս�� TEXT NOT NULL,Ӧ���˿���� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,��Ӧ�� TEXT NOT NULL,�������� TEXT NOT NULL,�Ѹ���� TEXT NOT NULL,Ӧ���˿���� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,���ݱ�� TEXT NOT NULL,�ʽ���� TEXT NOT NULL,��� TEXT NOT NULL,��ע TEXT NULL",
		"ID INT PRIMARY KEY NOT NULL,�������� TEXT NOT NULL,��Ŀ TEXT NOT NULL,�д� TEXT NOT NULL,��� TEXT NOT NULL"
	};
	return str[i];
}
string string_To_UTF8(const string & str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//һ��Ҫ��1����Ȼ�����β�� 
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}
string UTF8_To_string(const string & str)
{
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//һ��Ҫ��1����Ȼ�����β�� 
	memset(pwBuf, 0, nwLen * 2 + 2);

	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	memset(pBuf, 0, nLen + 1);

	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr = pBuf;

	delete[]pBuf;
	delete[]pwBuf;

	pBuf = NULL;
	pwBuf = NULL;

	return retStr;
}
