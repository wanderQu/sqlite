//// sqlite.cpp : 定义控制台应用程序的入口点。
////
//
//#include "stdafx.h"
//#include "sqlite.h"
//#include "sqlite3.h"
//#include <iostream>
//#include <string>
//#include <Windows.h>
//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif
//
//
//// 唯一的应用程序对象
//
//CWinApp theApp;
//
//using namespace std;
//
////open a database with its name
//void open(sqlite3 *db, char *name);
////close database connect
//void close(sqlite3 *db);
////create a table in a database
//void create(sqlite3 *db, string tbName);
////deal the commond
//bool excute(sqlite3 *db,const char *commond, char *errMsg = 0);
////insert all ctrl infomation into its table,one to one
//void insert(sqlite3 *db, char *tbName);
//void insert(sqlite3 *db);
////combin the commond
//string combin_Create(string s);
//string combin_Insert(string tbName, string value);
//string getName(int i);
//string getData(int i);
//string string_To_UTF8(const string & str);
//string UTF8_To_string(const string & str);
//int a = 0;
//int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
//{
//	int nRetCode = 0;
//
//	HMODULE hModule = ::GetModuleHandle(NULL);
//
//	if (hModule != NULL)
//	{
//		// 初始化 MFC 并在失败时显示错误
//		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
//		{
//			// TODO:  更改错误代码以符合您的需要
//			_tprintf(_T("错误:  MFC 初始化失败\n"));
//			nRetCode = 1;
//		}
//		else
//		{
//			// TODO:  在此处为应用程序的行为编写代码。
//			//cout << sqlite3_mprintf("%s", "大好河山角度看");
//			sqlite3 *db;
//			sqlite3_open("DataBase.db",&db);
//			insert(db);
//			close(db);
//		}
//	}
//	else
//	{
//		// TODO:  更改错误代码以符合您的需要
//		_tprintf(_T("错误:  GetModuleHandle 失败\n"));
//		nRetCode = 1;
//	}
//	system("pause");
//	return nRetCode;
//}
////open a database with its name
////void open(sqlite3 *db, char *name)
////{
////	bool op = sqlite3_open(name, &db);
////	if (op == true)
////		cout << "open database success!" << endl;
////	else
////		cout << "open database faild!" << sqlite3_errmsg(db) << endl;
////}
////close database connect
//void close(sqlite3 *db)
//{
//	int err = sqlite3_close(db);
//	if (err == SQLITE_OK)
//		cout << "exit!" << endl;
//	else
//	{
//		cout <<"some err happend !" << sqlite3_errmsg(db) << endl;
//		//exit(0);
//	}
//	
//		
//}
////create a table in a database
//void create(sqlite3 *db, string tbName)
//{
//	string tb;
//	tb = combin_Create(tbName);
//	if (excute(db, tb.c_str()))
//		cout << "\ncreate " << tbName << " success!" << endl;
//	else
//		cout << "\ncreate" << tbName << " failed" << endl;
//	tb.empty();
//}
////deal the commond
//bool excute(sqlite3 *db,const char *commond,char *errMsg)
//{
//	int err = sqlite3_exec(db, commond, NULL, NULL, &errMsg);
//	if (err == SQLITE_OK)
//		return true;
//	else
//	{
//		cout << errMsg << "->";
//		sqlite3_free(errMsg);
//		return false;
//	}
//	sqlite3_free(errMsg);
//}
////insert all ctrl infomation into its table,one to one
//void insert(sqlite3 *db, char *tbName)
//{
//
//}
//string combin_Create(string tbName)
//{
//	string tb;
//	tb = "CREATE TABLE " + tbName + "(ID INT PRIMARY KEY NOT NULL,\
//								ctrName	TEXT NOT NULL,\
//								ctrText	TEXT NULL,\
//								l	INT NOT NULL,\
//								t	INT NOT NULL,\
//								r	INT NOT NULL,\
//								b	INT NOT NULL);";
//	return tb;
//}
//string combin_Insert(string tbName, string value)
//{
//	string str;
//	str = "INSERT INTO " + tbName + "(ID,ctrName,ctrText,l,t,r,b)VALUES" + value;
//	return str;
//}
//string getName(int i)
//{
//	switch (i)
//	{
//	case 0:return "proOrder"; break;
//	case 1:return "proQuery"; break;
//	case 2:return "proTrack"; break;
//	case 3:return "proReturn"; break;
//	case 4:return "proIntel"; break;
//
//	case 5:return "distriLs"; break;
//	case 6:return "distriQuery"; break;
//	case 7:return "distriTrack"; break;
//
//	case 8:return "wareRequis"; break;
//	case 9:return "wareIn"; break;
//	case 10:return "wareOut"; break;
//	case 11:return "wareStock"; break;
//	case 12:return "wareChng"; break;
//	case 13:return "wareQuery"; break;
//
//	case 14:return "manaCus"; break;
//	case 15:return "manaSup"; break;
//	case 16:return "manaGoods"; break;
//	case 17:return "manaWare"; break;
//	case 18:return "manaAddress"; break;
//
//	case 19:return "dataVoucher"; break;
//	case 20:return "dataPayment"; break;
//	case 21:return "dataVerification"; break;
//	case 22:return "dataOtherIncome"; break;
//	case 23:return "dataOtherExpend"; break;
//	case 24:return "dataTransfer"; break;
//
//	case 25:return "assIncome"; break;
//	case 26:return "assExpense"; break;
//	case 27:return "assPayable"; break;
//	case 28:return "assReceive"; break;
//	case 29:return "assCusState"; break;
//	case 30:return "assVendorState"; break;
//	case 31:return "assOtherInOut"; break;
//	case 32:return "assIncomeState"; break;
//
//	case 33:return "setPermis"; break;
//	case 34:return "setLog"; break;
//
//	}
//	return NULL;
//}
////直接用循环的方式插入所有数据，现在需要的是获得这些数据
//void insert(sqlite3 *db)
//{
//	string str,str2;
//	for (a; a < 35; a++)
//	{
//		str2 = getName(a);
//		create(db, str2);
//		str = combin_Insert(str2, getData(a));
//		str = string_To_UTF8(str);
//		if (excute(db, str.c_str()))
//			cout << "insert data into TABLE " << str2 << " successed!" << endl;
//		else
//			cout << "insert data into TABLE " << str2 << " failed!" << endl;
//	}
//	str.empty();
//	str2.empty();
//}
//string getData(int i)
//{
//	string str[] =
//	{
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','供应商类别',590,10,665,30),(6,'combo','',685,10,775,30),(7,'text','供应商',795,10,840,30),(8,'combo','',860,10,950,30),(9,'bt','查询',970,10,1050,35),(10,'text','',0,50,150,65),(11,'bt','列表设置',570,40,650,65),(12,'bt','新增',670,40,750,65),(13,'bt','导出',770,40,850,65),(14,'bt','打印',870,40,950,65),(15,'bt','删除',970,40,1050,65),(16,'ls','',0,70,1120,600); ",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','供应商类别',590,10,665,30),(6,'combo','',685,10,775,30),(7,'text','供应商',795,10,840,30),(8,'combo','',860,10,950,30),(9,'bt','查询',970,10,1050,35),(10,'text','',0,50,150,65),(11,'bt','列表设置',695,40,775,65),(12,'bt','导出',760,40,840,65),(13,'bt','打印',870,40,950,65),(14,'bt','删除',970,40,1050,65),(15,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','供应商类别',590,10,665,30),(6,'combo','',685,10,775,30),(7,'text','供应商',795,10,840,30),(8,'combo','',860,10,950,30),(9,'bt','查询',970,10,1050,35),(10,'text','',0,50,150,65),(11,'bt','列表设置',695,40,775,65),(12,'bt','导出',760,40,840,65),(13,'bt','打印',870,40,950,65),(14,'bt','删除',970,40,1050,65),(15,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','供应商类别',590,10,665,30),(6,'combo','',685,10,775,30),(7,'text','供应商',795,10,840,30),(8,'combo','',860,10,950,30),(9,'bt','查询',970,10,1050,35),(10,'text','',0,50,150,65),(11,'bt','列表设置',570,40,650,65),(12,'bt','新增',670,40,750,65),(13,'bt','导出',770,40,850,65),(14,'bt','打印',870,40,950,65),(15,'bt','删除',970,40,1050,65),(16,'ls','',0,70,1120,600);",
//		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'text','商品类别',145,10,205,30),(3,'combo','',225,10,315,30),(4,'text','商品名称',335,10,395,30),(5,'combo','',415,10,505,30),(6,'bt','查询',525,10,605,35),(7,'bt','设置公式',625,10,705,35),(8,'bt','列表设置',725,10,805,35),(9,'bt','下发采购任务',825,10,905,35),(10,'ls','',0,40,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','客户类别',590,10,650,30),(6,'combo','',670,10,760,30),(7,'text','客户',780,10,810,30),(8,'combo','',830,10,920,30),(9,'bt','查询',940,10,1020,35),(10,'text','',0,50,150,65),(11,'bt','列表设置',540,40,620,65),(12,'bt','新增',640,40,720,65),(13,'bt','导出',740,40,820,65),(14,'bt','打印',840,40,920,65),(15,'bt','删除',940,40,1020,65),(16,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','客户类别',590,10,650,30),(6,'combo','',670,10,760,30),(7,'text','客户',780,10,810,30),(8,'combo','',830,10,920,30),(9,'bt','查询',940,10,1020,35),(10,'text','',0,50,150,65),(11,'bt','列表设置',680,40,760,65),(12,'bt','导出',730,40,810,65),(13,'bt','打印',840,40,920,65),(14,'bt','删除',940,40,1020,65),(15,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','客户类别',590,10,650,30),(6,'combo','',670,10,760,30),(7,'text','客户',780,10,810,30),(8,'combo','',830,10,920,30),(9,'bt','查询',940,10,1020,35),(10,'text','',0,50,150,65),(11,'bt','列表设置',680,40,760,65),(12,'bt','导出',730,40,810,65),(13,'bt','打印',840,40,920,65),(14,'bt','删除',940,40,1020,65),(15,'ls','',0,70,1120,600);",
//		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'text','商品类别',145,10,205,30),(3,'combo','',225,10,315,30),(4,'text','商品名称',335,10,395,30),(5,'combo','',415,10,505,30),(6,'bt','添加',525,10,605,35),(7,'ls','',0,40,1120,300),(8,'text','',0,310,30,330),(9,'combo','',50,310,125,330),(10,'bt','导出',640,310,720,335),(11,'bt','打印',740,310,820,335),(12,'bt','删除',840,310,920,335),(13,'bt','确认',940,310,1020,335),(14,'ls','',0,340,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'bt','查询',590,10,670,35),(6,'text','',0,50,150,65),(7,'bt','列表设置',190,40,270,65),(8,'bt','新增',290,40,370,65),(9,'bt','导出',390,40,470,65),(10,'bt','打印',490,40,570,65),(11,'bt','删除',590,40,670,65),(12,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','',0,50,150,65),(6,'bt','列表设置',540,40,620,65),(7,'bt','新增',640,40,720,65),(8,'bt','导出',740,40,820,65),(9,'bt','打印',840,40,920,65),(10,'bt','删除',940,40,1020,65),(11,'ls','',0,70,1120,600);",
//		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'text','商品类别',145,10,205,30),(3,'combo','',225,10,315,30),(4,'bt','查询',335,10,415,35),(5,'bt','导出',435,10,515,35),(6,'bt','打印',535,10,615,35),(7,'ls','',0,50,1120,600);",
//		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'text','商品类别',145,10,205,30),(3,'combo','',225,10,315,30),(4,'text','商品名称',335,10,395,30),(5,'combo','',415,10,505,30),(6,'text','商品编号',525,10,585,30),(7,'combo','',605,10,695,30),(8,'bt','查询',715,10,795,35),(9,'bt','修改',815,10,895,35),(10,'bt','确定',915,10,995,35),(11,'ls','',0,40,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','商品类别',220,10,280,30),(2,'combo','',300,10,390,30),(3,'text','商品名称',410,10,470,30),(4,'combo','',490,10,580,30),(5,'text','商品编号',600,10,660,30),(6,'combo','',680,10,770,30),(7,'bt','查询',790,10,870,35),(8,'bt','列表设置',740,40,820,65),(9,'bt','导出',840,40,920,65),(10,'bt','打印',940,40,1020,65),(11,'ls','',0,70,1120,600);",
//		"(0,'text','客户类别',0,10,60,30),(1,'combo','',80,10,170,30),(2,'bt','新增',740,10,820,35),(3,'bt','禁用',840,10,920,35),(4,'bt','删除',940,10,1020,35),(5,'ls','',0,40,1120,600);",
//		"(0,'text','供应商类别',0,10,75,30),(1,'combo','',95,10,185,30),(2,'bt','新增',740,10,820,35),(3,'bt','禁用',840,10,920,35),(4,'bt','删除',940,10,1020,35),(5,'ls','',0,40,1120,600);",
//		"(0,'text','商品类别',0,10,60,30),(1,'combo','',80,10,170,30),(2,'bt','新增',740,10,820,35),(3,'bt','禁用',840,10,920,35),(4,'bt','删除',940,10,1020,35),(5,'ls','',0,40,1120,600);",
//		"(0,'text','仓库',0,10,30,30),(1,'combo','',50,10,125,30),(2,'bt','新增',740,10,820,35),(3,'bt','禁用',840,10,920,35),(4,'bt','删除',940,10,1020,35),(5,'ls','',0,40,1120,600);",
//		"(0,'bt','新增',740,10,820,35),(1,'bt','禁用',840,10,920,35),(2,'bt','删除',940,10,1020,35),(3,'ls','',0,40,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','供应商类别',590,10,665,30),(6,'combo','',685,10,775,30),(7,'text','供应商',795,10,840,30),(8,'combo','',860,10,950,30),(9,'bt','查询',970,10,1050,35),(10,'text','',0,50,150,65),(11,'bt','列表设置',570,40,650,65),(12,'bt','新增',670,40,750,65),(13,'bt','导出',770,40,850,65),(14,'bt','打印',870,40,950,65),(15,'bt','删除',970,40,1050,65),(16,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','供应商类别',590,10,665,30),(6,'combo','',685,10,775,30),(7,'text','供应商',795,10,840,30),(8,'combo','',860,10,950,30),(9,'bt','查询',970,10,1050,35),(10,'text','',0,50,150,65),(11,'bt','列表设置',570,40,650,65),(12,'bt','新增',670,40,750,65),(13,'bt','导出',770,40,850,65),(14,'bt','打印',870,40,950,65),(15,'bt','删除',970,40,1050,65),(16,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'text','客户',590,10,620,30),(6,'combo','',640,10,730,30),(7,'text','供应商',750,10,795,30),(8,'combo','',815,10,905,30),(9,'bt','查询',925,10,955,35),(10,'text','',0,50,150,65),(11,'ls','',0,70,1120,300),(12,'text','',0,300,150,320),(13,'bt','打印',840,310,920,330),(14,'bt','确定',940,310,1020,330),(15,'ls','',0,335,1120,580),(16,'text','',0,580,150,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'bt','查询',590,10,620,35),(6,'bt','新增',640,10,670,35),(7,'bt','导出',690,10,720,35),(8,'bt','打印',740,10,770,35),(9,'bt','删除',790,10,820,35),(10,'text','',0,50,150,65),(11,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'bt','查询',590,10,620,35),(6,'bt','新增',640,10,670,35),(7,'bt','导出',690,10,720,35),(8,'bt','打印',740,10,770,35),(9,'bt','删除',790,10,820,35),(10,'text','',0,50,150,65),(11,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'bt','查询',590,10,620,35),(6,'bt','新增',640,10,670,35),(7,'bt','导出',690,10,720,35),(8,'bt','打印',740,10,770,35),(9,'bt','确认',790,10,820,35),(10,'text','',0,50,150,65),(11,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'bt','查询',590,10,670,35),(6,'bt','导出',690,10,770,35),(7,'bt','打印',790,10,870,35),(8,'text','',0,50,150,65),(9,'ls','',0,70,1120,600);",
//		"(0,'edit','',0,10,200,30),(1,'text','单据日期',220,10,280,30),(2,'time','',300,10,400,30),(3,'text','-',420,10,450,30),(4,'time','',470,10,570,30),(5,'bt','查询',590,10,670,35),(6,'bt','导出',690,10,770,35),(7,'bt','打印',790,10,870,35),(8,'text','',0,50,150,65),(9,'ls','',0,70,1120,600);",
//		"(0,'text','单据日期',0,10,60,30),(1,'time','',80,10,180,30),(2,'text','-',200,10,230,30),(3,'time','',250,10,350,30),(4,'text','供应商类别',370,10,445,30),(5,'combo','',465,10,555,30),(6,'text','供应商',575,10,620,30),(7,'combo','',640,10,730,30),(8,'bt','查询',750,10,830,35),(9,'bt','打印',840,40,920,65),(10,'bt','导出',940,40,1020,65),(11,'text','',0,50,150,65),(12,'ls','',0,70,1120,580),(13,'text','',0,580,150,600);",
//		"(0,'text','单据日期',0,10,60,30),(1,'time','',80,10,180,30),(2,'text','-',200,10,230,30),(3,'time','',250,10,350,30),(4,'text','客户类别',370,10,430,30),(5,'combo','',450,10,540,30),(6,'text','客户',560,10,590,30),(7,'combo','',610,10,700,30),(8,'bt','查询',720,10,800,35),(9,'bt','打印',840,40,920,65),(10,'bt','导出',940,40,1020,65),(11,'text','',0,50,150,65),(12,'ls','',0,70,1120,580),(13,'text','',0,580,150,600);",
//		"(0,'text','单据日期',0,10,60,30),(1,'time','',80,10,180,30),(2,'text','-',200,10,230,30),(3,'time','',250,10,350,30),(4,'text','客户类别',370,10,430,30),(5,'combo','',450,10,540,30),(6,'text','客户',560,10,590,30),(7,'combo','',610,10,700,30),(8,'bt','查询',720,10,800,35),(9,'bt','打印',840,40,920,65),(10,'bt','导出',940,40,1020,65),(11,'text','',0,50,150,65),(12,'ls','',0,70,1120,580),(13,'text','',0,580,150,600);",
//		"(0,'text','单据日期',0,10,60,30),(1,'time','',80,10,180,30),(2,'text','-',200,10,230,30),(3,'time','',250,10,350,30),(4,'text','供应商类别',370,10,445,30),(5,'combo','',465,10,555,30),(6,'text','供应商',575,10,620,30),(7,'combo','',640,10,730,30),(8,'bt','查询',750,10,830,35),(9,'bt','打印',840,40,920,65),(10,'bt','导出',940,40,1020,65),(11,'text','',0,50,150,65),(12,'ls','',0,70,1120,580),(13,'text','',0,580,150,600);",
//		"(0,'text','单据日期',0,10,60,30),(1,'time','',80,10,180,30),(2,'text','-',200,10,230,30),(3,'time','',250,10,350,30),(4,'bt','查询',370,10,450,35),(5,'bt','导出',470,10,550,35),(6,'bt','打印',570,10,650,35),(7,'text','',0,50,150,65),(8,'ls','',0,70,1120,600);",
//		"(0,'text','季度',0,10,30,30),(1,'combo','',50,10,150,30),(2,'bt','导出',170,10,250,35),(3,'bt','打印',270,10,350,35),(4,'ls','',0,50,1120,600);",
//		"(0,'text','员工类别',0,10,60,30),(1,'combo','',80,10,180,30),(2,'text','员工类别',200,10,230,30),(3,'combo','',250,10,350,30),(4,'bt','新增',370,10,450,35),(5,'ls','',0,50,1120,600);",
//		"(0,'text','日期',0,10,30,30),(1,'time','',50,10,150,30),(2,'text','-',170,10,200,30),(3,'time','',220,10,320,30),(4,'text','员工',340,10,370,30),(5,'combo','',390,10,480,30),(6,'text','操作类型',500,10,560,30),(7,'combo','',580,10,670,30),(8,'bt','查询',690,10,770,35),(9,'text','',0,50,150,65),(10,'ls','',0,70,1120,600);"
//	};
//	return str[i];
//
//}
//
//string string_To_UTF8(const string & str)
//{
//	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
//
//	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
//	ZeroMemory(pwBuf, nwLen * 2 + 2);
//
//	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
//
//	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
//
//	char * pBuf = new char[nLen + 1];
//	ZeroMemory(pBuf, nLen + 1);
//
//	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
//
//	std::string retStr(pBuf);
//
//	delete[]pwBuf;
//	delete[]pBuf;
//
//	pwBuf = NULL;
//	pBuf = NULL;
//
//	return retStr;
//}
//string UTF8_To_string(const string & str)
//{
//	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
//
//	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
//	memset(pwBuf, 0, nwLen * 2 + 2);
//
//	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);
//
//	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
//
//	char * pBuf = new char[nLen + 1];
//	memset(pBuf, 0, nLen + 1);
//
//	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
//
//	std::string retStr = pBuf;
//
//	delete[]pBuf;
//	delete[]pwBuf;
//
//	pBuf = NULL;
//	pwBuf = NULL;
//
//	return retStr;
//}
// sqlite_dll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "sqlite3.h"
#include <Windows.h>
using namespace std;

bool DB_open(sqlite3 **db, char *name)
{
	sqlite3_open(name, db);
	return true;
}
char* getTbName(int i)
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
//UTF-8到GB2312的转换
char* U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

//GB2312到UTF-8的转换
char* G2U(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

bool selectDB(sqlite3 *db, char *tbName, char *key)
{
	return true;
}
bool DB_excuteNoCall(sqlite3 *db, const char *commond, char *errMsg = 0)
{

	char *t = G2U(commond);
	if (sqlite3_exec(db, t, 0, 0, &errMsg) == SQLITE_OK)
		return true;

	cout << errMsg << endl;
		return false;

}
bool DB_excute(sqlite3 *db, const char *commond, sqlite3_callback callback, void *data, char *errMsg)
{
	char *t = G2U(commond);

	if (sqlite3_exec(db, t, callback, data, &errMsg) == SQLITE_OK)		
		return true;


	cout << errMsg << endl;
	return false;

}
bool DB_close(sqlite3 *db)
{
	if (sqlite3_close(db) == SQLITE_OK)
		return true;
	else
		return false;
}

bool DB_insertName(sqlite3 *db, char *tbName, char *key, char *value)
{
	//	str = "INSERT INTO " + tbName + "(ID,ctrName,ctrText,l,t,r,b)VALUES" + value;

	char *commond = sqlite3_mprintf("INSERT INTO %s(%s)VALUES (%s)", tbName, key, value);
	DB_excuteNoCall(db, commond);
	return true;
}
bool DB_insert(sqlite3 *db, int tbID, char *key, char *value)
{
	char *tbName = getTbName(tbID);
	if (DB_insertName(db, tbName, key, value))
		return true;
	else
		return false;
}
bool DB_create(sqlite3 *db, char *tbName, char *Key)
{
	char *sql = sqlite3_mprintf("CREATE TABLE %s (%s)", tbName, Key);
	if (DB_excuteNoCall(db, sql))
		return true;
	else
		return false;
}

int main()
{
	sqlite3 *db;
	DB_open(&db, "ad.db");

	DB_create(db, "a", "ID PRIMARY KEY NOT NULL,NAME TEXT NOT NULL");
	DB_insertName(db, "a", "ID,NAME", "0,'我'");
	DB_close(db);
	system("pause");
	return 0;
}