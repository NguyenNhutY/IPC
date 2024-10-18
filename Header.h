#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <Windows.h>

using namespace std;

struct st
{
	char mst[50]; //na sieu thi
	char tst[50]; // ten sieu thi
	int ntl; // nam thanh lap
	int dscb; // danh so co ban ( trung binh trong 1 nam )
	int slnv; // so luong nhan vien
};

struct QLST
{
	st data;
	QLST* link;
};

typedef struct QLST* qlst;
void Nhap1ST(st& st);
void KhoiTao(qlst& s);
int IsEmpty(qlst s);
void GiaiPhong(qlst& s);
qlst CreatNode(st x);
qlst Them(qlst& s, st x);
bool KT_TrungMa(qlst& s, char* mst);
void XuatDSST(qlst s);
void KhungXuat();
void Xuat1ST(st s);
void NhapDSST(qlst& list);
void KT_MST(qlst s, char mstkt[50]);
void MinDSCB(qlst s);
void MaxDSCB(qlst s);
void MinSLNV(qlst s);
void MaxSLNV(qlst s);
int Xuat_FIle_TK_SLNV(qlst s);
void DoanhSo(qlst s, char mstds[50]);
int LoiNhuan(qlst s, int lcb, char mstds[50]);
void ListsWithGreaterProfits(qlst s);
void Swap(qlst a, qlst b);
void DSSTTangDan(qlst& s);
void Menu();
int CountNode(qlst s);
void DSMenu(qlst s);
