// sqlite.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "sqlite3.h"
#include <iostream>
#include <string>
#include <Windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

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
void insert(sqlite3 *db, char *tbName);
void insert(sqlite3 *db);
//combin the commond
string combin_Create(string s);
string combin_Insert(string tbName, string value);
string getName(int i);
string getData(int i);
string string_To_UTF8(const string & str);
string UTF8_To_string(const string & str);
int a = 0;
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO:  更改错误代码以符合您的需要
			_tprintf(_T("错误:  MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO:  在此处为应用程序的行为编写代码。
			//cout << sqlite3_mprintf("%s", "大好河山角度看");
			sqlite3 *db;
			sqlite3_open("DataBase.db",&db);
			insert(db);
			close(db);
		}
	}
	else
	{
		// TODO:  更改错误代码以符合您的需要
		_tprintf(_T("错误:  GetModuleHandle 失败\n"));
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
void insert(sqlite3 *db, char *tbName)
{

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
//直接用循环的方式插入所有数据，现在需要的是获得这些数据
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
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,30),(4,'time','',470,10,590,35),(5,'text','供应商类别',610,10,700,30),(6,'combo','',720,10,810,30),(7,'text','供应商',830,10,885,30),(8,'combo','',905,10,995,30),(9,'bt','查询',1015,10,1095,35),(10,'text','',0,60,150,80),(11,'bt','列表设置',615,50,695,75),(12,'bt','新增',715,50,795,75),(13,'bt','导出',815,50,895,75),(14,'bt','打印',915,50,995,75),(15,'bt','删除',1015,50,1095,75),(16,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,30),(4,'time','',470,10,590,35),(5,'text','供应商类别',610,10,700,30),(6,'combo','',720,10,810,30),(7,'text','供应商',830,10,885,30),(8,'combo','',905,10,995,30),(9,'bt','查询',1015,10,1095,35),(10,'text','',0,60,150,80),(11,'bt','列表设置',705,50,785,75),(12,'bt','导出',805,50,885,75),(13,'bt','打印',915,50,995,75),(14,'bt','删除',1015,50,1095,75),(15,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,20),(4,'time','',470,10,590,35),(5,'text','供应商类别',610,10,700,30),(6,'combo','',720,10,810,30),(7,'text','供应商',830,10,885,30),(8,'combo','',905,10,995,30),(9,'bt','查询',1015,10,1095,35),(10,'text','',0,60,150,80),(11,'bt','列表设置',730,50,810,75),(12,'bt','导出',815,50,895,75),(13,'bt','打印',915,50,995,75),(14,'bt','删除',1015,50,1095,75),(15,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,20),(4,'time','',470,10,590,35),(5,'text','供应商类别',610,10,700,30),(6,'combo','',720,10,810,30),(7,'text','供应商',830,10,885,30),(8,'combo','',905,10,995,30),(9,'bt','查询',1015,10,1095,35),(10,'text','',0,60,150,80),(11,'bt','列表设置',615,50,695,75),(12,'bt','新增',715,50,795,75),(13,'bt','导出',815,50,895,75),(14,'bt','打印',915,50,995,75),(15,'bt','删除',1015,50,1095,75),(16,'ls','',0,80,1120,600);",
		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'text','商品类别',145,10,215,30),(3,'combo','',235,10,325,30),(4,'text','商品名称',345,10,415,30),(5,'combo','',435,10,525,30),(6,'bt','查询',545,10,625,35),(7,'bt','设置公式',645,10,725,35),(8,'bt','列表设置',745,10,825,35),(9,'bt','下发采购任务',845,10,935,35),(10,'ls','',0,60,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,20),(4,'time','',470,10,590,35),(5,'text','客户类别',610,10,680,30),(6,'combo','',700,10,790,30),(7,'text','客户',810,10,840,30),(8,'combo','',860,10,950,30),(9,'bt','查询',970,10,1050,35),(10,'text','',0,60,150,80),(11,'bt','列表设置',570,50,650,75),(12,'bt','新增',670,50,750,75),(13,'bt','导出',770,50,850,75),(14,'bt','打印',870,50,950,75),(15,'bt','删除',970,50,1050,75),(16,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,20),(4,'time','',470,10,590,35),(5,'text','客户类别',610,10,680,30),(6,'combo','',700,10,790,30),(7,'text','客户',810,10,840,30),(8,'combo','',860,10,950,30),(9,'bt','查询',970,10,1050,35),(10,'text','',0,60,150,80),(11,'bt','列表设置',660,50,740,75),(12,'bt','导出',760,50,840,75),(13,'bt','打印',870,50,950,75),(14,'bt','删除',970,50,1050,75),(15,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,30),(4,'time','',470,10,590,35),(5,'text','客户类别',610,10,680,30),(6,'combo','',700,10,790,30),(7,'text','客户',810,10,840,30),(8,'combo','',860,10,950,30),(9,'bt','查询',970,10,1050,35),(10,'text','',0,60,150,80),(11,'bt','列表设置',660,50,740,75),(12,'bt','导出',760,50,840,75),(13,'bt','打印',870,50,950,75),(14,'bt','删除',970,50,1050,75),(15,'ls','',0,80,1120,600);",
		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'text','商品类别',145,10,215,30),(3,'combo','',235,10,325,30),(4,'text','商品名称',345,10,415,30),(5,'combo','',435,10,525,30),(6,'bt','添加',545,10,625,35),(7,'ls','',0,50,1120,300),(8,'text','',0,310,30,330),(9,'combo','',50,310,125,330),(10,'bt','导出',640,310,720,335),(11,'bt','打印',740,310,820,335),(12,'bt','删除',840,310,920,335),(13,'bt','确认',940,310,1020,335),(14,'ls','',0,350,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,30),(3,'text','-',440,10,460,30),(4,'time','',470,10,590,30),(5,'bt','查询',610,10,690,35),(6,'text','',0,60,150,75),(7,'bt','列表设置',210,50,290,75),(8,'bt','新增',310,50,390,75),(9,'bt','导出',410,50,490,75),(10,'bt','打印',510,50,590,75),(11,'bt','删除',610,50,690,75),(12,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,30),(3,'text','-',440,10,460,30),(4,'time','',470,10,590,30),(5,'text','',0,60,150,80),(6,'bt','列表设置',540,50,620,75),(7,'bt','新增',640,50,720,75),(8,'bt','导出',740,50,820,75),(9,'bt','打印',840,50,920,75),(10,'bt','删除',940,50,1020,75),(11,'ls','',0,80,1120,600);",
		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'text','商品类别',145,10,215,30),(3,'combo','',235,10,325,30),(4,'bt','查询',345,10,425,35),(5,'bt','导出',445,10,525,35),(6,'bt','打印',545,10,625,35),(7,'ls','',0,60,1120,600);",
		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'text','商品类别',145,10,215,30),(3,'combo','',235,10,325,30),(4,'text','商品名称',345,10,415,30),(5,'combo','',435,10,525,30),(6,'text','商品编号',545,10,615,30),(7,'combo','',635,10,725,30),(8,'bt','查询',745,10,825,35),(9,'bt','修改',845,10,925,35),(10,'bt','确定',945,10,1025,35),(11,'ls','',0,40,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','商品类别',220,10,290,30),(2,'combo','',310,10,400,30),(3,'text','商品名称',420,10,490,30),(4,'combo','',510,10,600,30),(5,'text','商品编号',620,10,690,30),(6,'combo','',710,10,800,30),(7,'bt','查询',820,10,900,35),(8,'bt','列表设置',740,50,820,75),(9,'bt','导出',840,50,920,75),(10,'bt','打印',940,50,1020,75),(11,'ls','',0,80,1120,600);",
		"(0,'text','客户类别',0,10,70,30),(1,'combo','',90,10,180,30),(2,'bt','新增',740,10,820,35),(3,'bt','禁用',840,10,920,35),(4,'bt','删除',940,10,1020,35),(5,'ls','',0,60,1120,600);",
		"(0,'text','供应商类别',0,10,90,30),(1,'combo','',110,10,200,30),(2,'bt','新增',740,10,820,35),(3,'bt','禁用',840,10,920,35),(4,'bt','删除',940,10,1020,35),(5,'ls','',0,40,1120,600);",
		"(0,'text','商品类别',0,10,70,30),(1,'combo','',90,10,180,30),(2,'bt','新增',740,10,820,35),(3,'bt','禁用',840,10,920,35),(4,'bt','删除',940,10,1020,35),(5,'ls','',0,40,1120,600);",
		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'bt','新增',740,10,820,35),(3,'bt','禁用',840,10,920,35),(4,'bt','删除',940,10,1020,35),(5,'ls','',0,40,1120,600);",
		"(0,'bt','新增',740,10,820,35),(1,'bt','禁用',840,10,920,35),(2,'bt','删除',940,10,1020,35),(3,'ls','',0,40,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,420,35),(3,'text','-',430,10,450,20),(4,'time','',460,10,580,35),(5,'text','供应商类别',600,10,690,30),(6,'combo','',710,10,800,30),(7,'text','供应商',820,10,875,30),(8,'combo','',895,10,985,30),(9,'bt','查询',1005,10,1085,35),(10,'text','',0,60,150,80),(11,'bt','列表设置',605,50,685,75),(12,'bt','新增',705,50,785,75),(13,'bt','导出',805,50,885,75),(14,'bt','打印',905,50,985,75),(15,'bt','删除',1005,50,1085,75),(16,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,30),(3,'text','-',440,10,460,30),(4,'time','',470,10,590,30),(5,'text','供应商类别',610,10,700,30),(6,'combo','',720,10,810,30),(7,'text','供应商',830,10,885,30),(8,'combo','',905,10,995,30),(9,'bt','查询',1015,10,1095,35),(10,'text','',0,60,150,80),(11,'bt','列表设置',615,50,695,75),(12,'bt','新增',715,50,795,75),(13,'bt','导出',815,50,895,75),(14,'bt','打印',915,50,995,75),(15,'bt','删除',1015,50,1095,75),(16,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,20),(4,'time','',470,10,590,35),(5,'text','客户',610,10,640,30),(6,'combo','',660,10,750,30),(7,'text','供应商',770,10,825,30),(8,'combo','',845,10,935,30),(9,'bt','查询',955,10,1035,35),(10,'text','',0,60,150,80),(11,'ls','',0,80,1120,300),(12,'text','',0,300,150,320),(13,'bt','打印',840,310,920,330),(14,'bt','确定',940,310,1020,330),(15,'ls','',0,350,1120,580),(16,'text','',0,580,150,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,30),(3,'text','-',440,10,460,30),(4,'time','',470,10,590,30),(5,'bt','查询',610,10,690,35),(6,'bt','新增',710,10,790,35),(7,'bt','导出',810,10,890,35),(8,'bt','打印',910,10,990,35),(9,'bt','删除',1010,10,1090,35),(10,'text','',0,60,150,80),(11,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,20),(4,'time','',470,10,590,35),(5,'bt','查询',610,10,690,35),(6,'bt','新增',710,10,790,35),(7,'bt','导出',810,10,890,35),(8,'bt','打印',910,10,990,35),(9,'bt','删除',1010,10,1090,35),(10,'text','',0,60,150,80),(11,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,20),(4,'time','',470,10,590,35),(5,'bt','查询',610,10,690,35),(6,'bt','新增',710,10,790,35),(7,'bt','导出',810,10,890,35),(8,'bt','打印',910,10,990,35),(9,'bt','确认',1010,10,1090,35),(10,'text','',0,60,150,80),(11,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,20),(4,'time','',470,10,590,35),(5,'bt','查询',610,10,690,35),(6,'bt','导出',710,10,790,35),(7,'bt','打印',810,10,890,35),(8,'text','',0,60,150,80),(9,'ls','',0,80,1120,600);",
		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,290,30),(2,'time','',310,10,430,35),(3,'text','-',440,10,460,20),(4,'time','',470,10,590,35),(5,'bt','查询',610,10,690,35),(6,'bt','导出',710,10,790,35),(7,'bt','打印',810,10,890,35),(8,'text','',0,60,150,80),(9,'ls','',0,80,1120,600);",
		"(0,'text','单据日期',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','-',220,10,240,20),(3,'time','',250,10,370,35),(4,'text','供应商类别',390,10,480,30),(5,'combo','',500,10,590,30),(6,'text','供应商',610,10,665,30),(7,'combo','',685,10,775,30),(8,'bt','查询',795,10,875,35),(9,'bt','打印',840,50,920,75),(10,'bt','导出',940,50,1020,75),(11,'text','',0,60,150,80),(12,'ls','',0,80,1120,580),(13,'text','',0,580,150,600);",
		"(0,'text','单据日期',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','-',220,10,240,20),(3,'time','',250,10,370,35),(4,'text','客户类别',390,10,460,30),(5,'combo','',480,10,570,30),(6,'text','客户',590,10,620,30),(7,'combo','',640,10,730,30),(8,'bt','查询',750,10,830,35),(9,'bt','打印',840,40,920,65),(10,'bt','导出',940,40,1020,65),(11,'text','',0,50,150,65),(12,'ls','',0,70,1120,580),(13,'text','',0,580,150,600);",
		"(0,'text','单据日期',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','-',220,10,240,20),(3,'time','',250,10,370,35),(4,'text','客户类别',390,10,460,30),(5,'combo','',480,10,570,30),(6,'text','客户',590,10,620,30),(7,'combo','',640,10,730,30),(8,'bt','查询',750,10,830,35),(9,'bt','打印',840,50,920,75),(10,'bt','导出',940,50,1020,75),(11,'text','',0,60,150,80),(12,'ls','',0,80,1120,580),(13,'text','',0,580,150,600);",
		"(0,'text','单据日期',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','-',220,10,240,20),(3,'time','',250,10,370,35),(4,'text','供应商类别',390,10,480,30),(5,'combo','',500,10,590,30),(6,'text','供应商',610,10,665,30),(7,'combo','',685,10,775,30),(8,'bt','查询',795,10,875,35),(9,'bt','打印',840,50,920,75),(10,'bt','导出',940,50,1020,75),(11,'text','',0,60,150,80),(12,'ls','',0,80,1120,580),(13,'text','',0,580,150,600);",
		"(0,'text','单据日期',0,10,70,30),(1,'time','',90,10,210,35),(2,'text','-',220,10,240,20),(3,'time','',250,10,370,35),(4,'bt','查询',390,10,470,35),(5,'bt','导出',490,10,570,35),(6,'bt','打印',590,10,670,35),(7,'text','',0,60,150,80),(8,'ls','',0,80,1120,600);",
		"(0,'text','季度',0,10,30,30),(1,'combo','',50,10,150,30),(2,'bt','导出',170,10,250,35),(3,'bt','打印',270,10,350,35),(4,'ls','',0,60,1120,600);",
		"(0,'text','员工类别',0,10,70,30),(1,'combo','',90,10,190,30),(2,'text','员工类别',210,10,280,30),(3,'combo','',300,10,400,30),(4,'bt','新增',420,10,500,35),(5,'ls','',0,60,1120,600);",
		"(0,'text','日期',0,10,30,30),(1,'time','',50,10,170,35),(2,'text','-',180,10,200,20),(3,'time','',210,10,330,35),(4,'text','员工',350,10,380,30),(5,'combo','',400,10,490,30),(6,'text','操作类型',510,10,570,30),(7,'combo','',590,10,680,30),(8,'bt','查询',700,10,780,35),(9,'text','',0,60,150,80),(10,'ls','',0,80,1120,600);"

	};
	return str[i];

}

string string_To_UTF8(const string & str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
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

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
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
