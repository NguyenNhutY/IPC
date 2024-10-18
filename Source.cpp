#include "Header.h"

void KhoiTao(qlst& s) {
	s = NULL;
}


int IsEmpty(qlst s) {
	return s == NULL ? 1 : 0;
}

void GiaiPhong(qlst& s) {
	qlst node = s;
	while (node != NULL) {
		s = s->link;
		delete node;
		node = s;
	}
}

qlst CreatNode(st x)
{
	qlst node = new QLST;
	node->data = x;
	node->link = NULL;
	return node;
}

qlst Them(qlst& s, st x) {
	qlst p = CreatNode(x);
	p->link = s;
	s = p;
	return p;
}
bool KT_TrungMa(qlst& s, char* mst) {
	qlst node = s;
	while (node != NULL) {
		if (strcmp(node->data.mst, mst) == 0) return true;
		node = node->link;
	} return false;
}
//Cau 1
void Nhap1ST(st& st)
{
	time_t t = time(0);
	cin.ignore();
	cout << "\nNhap ten sieu thi: ";
	cin.getline(st.tst, 30);
	do
	{
		cout << "\nNhap nam thanh lap: ";
		cin >> st.ntl;
		if (st.ntl < 0 || st.ntl > (localtime(&t)->tm_year + 1900))
		{
			cout << "\nNhap nam thanh lap qua nam hien tai or la am";
			cout << "\nVui long nhap lai";
		}
	} while (st.ntl < 0 || st.ntl > (localtime(&t)->tm_year + 1900));
	do
	{
		cout << "\nNhap doanh so co ban: ";
		cin >> st.dscb;
		if (st.dscb < 0)
		{
			cout << "\nNhap doanh so co ban am";
			cout << "\nVui long nhap lai";
		}
	} while (st.dscb < 0);
	do
	{
		cout << "\nNhap so luong nhan vien: ";
		cin >> st.slnv;
		if (st.slnv < 0)
		{
			cout << "\nNhap so luong nhan vien am";
			cout << "\nVui long nhap lai";
		}
	} while (st.slnv < 0);
	cin.ignore();
	system("pause");
};
void NhapDSST(qlst& list) {

	st st;
	while (true)
	{
		cout << "\nNhap thong tin 1 sieu thi: ";
		cout << "\nNhap ma sieu thi (Nhap -99 de dung): ";
		cin >> st.mst;
		while (KT_TrungMa(list, st.mst))
		{
			cout << "\nNhap lai ma sieu thi (Trung ma): ";
			cin >> st.mst;
		}
		if (strcmp(st.mst, "-99") == 0) break;
		Nhap1ST(st);
		Them(list, st);
	}
}
//Cau 2
void XuatDSST(qlst s)
{
	if (!IsEmpty(s))
	{
		cout << "\nDanh sach sieu thi\n";
		KhungXuat();
		qlst node = s;
		while (node != NULL)
		{
			Xuat1ST(node->data);
			node = node->link;
		}
	} else cout << "\nDanh sach sieu thi rong\n";
}
void KhungXuat()
{
	cout << endl			<< "Ma sieu thi"
		<< setw(20) << left << "Ten sieu thi"
		<< setw(20) << left << "Nam thanh lap"
		<< setw(20) << left << "Doanh thu co ban"
		<< setw(20) << left << "So luong nhan vien"
		<< endl;
}
void Xuat1ST(st s)
{
	cout << endl 
		<< setw(20) << left << s.mst
		<< setw(20) << left << s.tst
		<< setw(15) << left << s.ntl
		<< setw(20) << left << s.dscb
		<< setw(20) << left << s.slnv
		<< endl;
}
//Cau 3
void KT_MST(qlst s, char mstkt[50])
{
	if (!IsEmpty(s))
	{
		bool flag = false;
		do {
			if (strcmp(s->data.mst, mstkt) == 0)
			{
				KhungXuat();
				Xuat1ST(s->data);
				flag = true;
				return;
			}s = s->link;
		} while (s != NULL);
		if (flag == false) cout << "\nMa sieu thi vua nhap khong co trong sieu thi";
	} else cout << "\n Danh sach rong\n";
}
//Cau 4
void MaxDSCB(qlst s)
{
	if (!IsEmpty(s))
	{
		if (s->link != NULL)
		{
		qlst node = s; qlst kq = s;
		int max = s->data.dscb;
		while (node != NULL)
		{
			if (max < node->data.dscb)
			{
				max = node->data.dscb;
				kq = node;
			}node = node->link;
		} cout << "\nSieu thi co doanh so co ban lon nhat: ";
		KhungXuat();
		Xuat1ST(kq->data);
		}
		else
		{
			cout << "\nDanh sach chi co 1 nen xuat luon: ";
			KhungXuat();
			Xuat1ST(s->data);
		}
	} else cout << "\nDanh sach rong\n";
}
void MinDSCB(qlst s)
{
	if (!IsEmpty(s))
	{
		if (s->link != NULL)
		{
		qlst node = s; qlst kq = s;
		int min = s->data.dscb;
		while (node != NULL)
		{
			if (min > node->data.dscb)
			{
				min = node->data.dscb;
				kq = node;
			}node = node->link;
		} cout << "\nSieu thi co doanh so co ban nho nhat: ";
		KhungXuat();
		Xuat1ST(kq->data);
	}
	else
	{
		cout << "\nDanh sach chi co 1 nen xuat luon: ";
		KhungXuat();
		Xuat1ST(s->data);
	}
	} else cout << "\nDanh sach rong\n";
}
//Cau 5
void MaxSLNV(qlst s)
{
	if (!IsEmpty(s))
	{
		if (s->link != NULL)
		{
			qlst node = s; qlst kq = s;
			int max = s->data.dscb;
			while (node != NULL)
			{
				if (max < node->data.slnv)
				{
					max = node->data.slnv;
					kq = node;
				}node = node->link;
			} cout << "\nSieu thi co doanh so co ban lon nhat: ";
			KhungXuat();
			Xuat1ST(kq->data);
		}
		else
		{
			cout << "\nDanh sach chi co 1 nen xuat luon: ";
			KhungXuat();
			Xuat1ST(s->data);
		}
	} else cout << "\nDanh sach rong\n";
}
void MinSLNV(qlst s)
{
	if (!IsEmpty(s))
	{
		if (s->link != NULL)
		{
			qlst node = s; qlst kq = s;
			int min = s->data.slnv;
			while (node != NULL)
			{
				if (min > node->data.slnv)
				{
					min = node->data.slnv;
					kq = node;
				}node = node->link;
			} cout << "\nSieu thi co doanh so co ban nho nhat: ";
			KhungXuat();
			Xuat1ST(kq->data);
		}
		else
		{
			cout << "\nDanh sach chi co 1 nen xuat luon: ";
			KhungXuat();
			Xuat1ST(s->data);
		}
	} else cout << "\nDanh sach rong\n";
}
//Cau 6
int Xuat_FIle_TK_SLNV(qlst s)
{
	ofstream File;
	File.open("C:\\Users\\ACER\\OneDrive\\Máy tính\\output.txt", ios_base :: out);
	if (File.fail()) return 0;
	int dem100 = 0, dem200 = 0, dem = 0;
	while (s!=NULL)
	{
		if (s->data.dscb < 100) dem100++;
		else if(s->data.dscb <= 200) dem++;
		else dem200++;
		s = s->link;
	}
	File << "\n================ Xuat File thong ke so luong nhan vien ================";
	File << "\nDoanh so co ban duoi 100 la: " << dem100;
	File << "\nDoanh so co ban 100-200 la: " << dem;
	File << "\nDoanh so co ban tren 200 la: " << dem200;
	File << "\n================ Ket Thuc ================="; 
	File.close();
}
//Cau 7
void DoanhSo(qlst s, char mstds[50])
{
	if (!IsEmpty(s))
	{
		time_t t = time(0);
		qlst node = s;
		do
		{
			if (strcmp(s->data.mst, mstds) == 0)
			{
				cout << "\nDoanh so can tinh: " << s->data.dscb * ((localtime(&t)->tm_year + 1900) - s->data.ntl);
				break;
			}
			s = s->link;
		} while (s != NULL);
	} else cout <<"\nDanh sach sieu thi rong";
}
//Cau 8
int LoiNhuan(qlst s, int lcb, char mstds[50])
{
	if (!IsEmpty(s))
	{
		time_t t = time(0);
		qlst node = s;
		do
		{
			if (strcmp(s->data.mst, mstds) == 0)
			{
				return (s->data.dscb * ((localtime(&t)->tm_year + 1900) - s->data.ntl)) - ( lcb * s->data.slnv);
			}s = s->link;
		} while (s != NULL && (strcmp(s->data.mst, mstds) == 0));
	}
	else return -1;
}
//Cau 9
int CountNode(qlst s)
{
	int dem = 0;
	do
	{
		dem++;
		s = s->link;
	} while (s != NULL);
	return dem;
}
void ListsWithGreaterProfits(qlst s)
{
	int sln, lcb;
	if (!IsEmpty(s))
	{
		qlst node = s; qlst ln= s;
		int i = 1, a[10], z = 1,  j = 1;
		do
		{
			do 
			{
			cout << "\nNhap luong co ban nhan vien thu (" << i << "), de the vao cong thuc: ";
			cin >> lcb;
			a[i] = lcb;
			if (lcb < 0)
			{
				cout << "\nSo luong co ban, ban nhap duoi am ";
				cout << "\nXin vui long nhap lai";
			}
			} while (lcb < 0);
			i++;
		} while (i <= CountNode(s));
		do
		{
			cout << "\nLoi nhuan sieu thi thu (" << z << "): "<< LoiNhuan(ln, a[z],ln->data.mst);
			z++;
			ln = ln->link;
		} while (ln!=NULL);
		do
		{
			cout << "\n Nhap vao 1 con so loi nhuan: ";
			cin >> sln;
			if (sln < 0)
			{
				cout << "\nSo loi nhuan, ban nhap duoi am ";
				cout << "\nXin vui long nhap lai";
			}
		} while (sln < 0);
		cout << "\n================ Danh sach sieu thi co loi nhuan lon hon so loi nhuan da nhap  ================";
		KhungXuat();
		bool flag = false;
		do
		{
				if (sln < LoiNhuan(node, a[j], node->data.mst))
				{
					Xuat1ST(node->data);
					flag = true;
				} j++;
				node = node->link;
		} while (node != NULL);
		cout << "\n================ Danh sach sieu thi co loi nhuan lon hon so loi nhuan da nhap  ================\n";
		//cho co flag de check xem duyet toi NULL ko tim thay sln nhap lon hon moi loi nhuan tat ca sieu thi
		if (flag == false) cout << "\nSo loi nhuan vua nhap la lon nhat nen ko in ra duoc danh sach\n";
	}else cout << "\nDanh sach sieu thi rong\n";
}
//Cau 10
void Swap(qlst a, qlst b)
{
	st temp = a->data;
	a->data = b->data;
	b->data = temp;
}
void DSSTTangDan(qlst& s)
{
	time_t t = time(0);
	if (!IsEmpty(s))
	{
		qlst node = s; 
		qlst after = s->link; 
		qlst min = s; 
		cout << "\n================ Danh sach da sap xep tang dan ================";
		if (s->link != NULL)
		{
			do
			{
				min = node;
				after = node->link;
				do 
				{
					if (((localtime(&t)->tm_year + 1900) - after->data.ntl) < ((localtime(&t)->tm_year + 1900) - min->data.ntl))
						min = after;
					after = after->link;
				} while (after != NULL);
				if (strcmp(min->data.mst, node->data.mst) != 0)
					Swap(node, min);
				node = node->link;
			} while (node->link != NULL);
			XuatDSST(s);
		}
		else
		{
			cout << "\nDanh sach chi co 1 nen: ";
			KhungXuat();
			Xuat1ST(s->data);
		}
		cout << "\n================ Danh sach da sap xep tang dan ================\n";
	} else cout << "\nDanh sach rong\n";
}
void Menu()
{
	cout << "\n=================MENU================\n";
	cout << "0.  Thoat!!!\n";
	cout << "1.  Nhap danh sach sieu thi voi day du cac thong tin\n";
	cout << "2.  Xuat danh sach sieu thi voi day du cac thong tin\n";
	cout << "3.  Nhap vao 1 ma sieu thi va kiem tra ma sieu thi do co ton tai? Neu co thi xuat ra man hinh thong tin\n";
	cout << "4.  In ra man hinh thong tin sieu thi co doanh so lon nhat\n";
	cout << "5.  In ra man hinh thong tin sieu thi co doanh so nho nhat\n";
	cout << "6.  In ra man hinh thong tin sieu thi co so luong nhan vien lon nhat\n";
	cout << "7.  In ra man hinh thong tin sieu thi co so luong nhan vien nho nhat\n";
	cout << "8.  Xuat ra File Text: duoi 100 nhan vien, 100-200 nhan vien, tren 200 nhan vien \n";
	cout << "9.  Tinh doanh so cua sieu thi (DS) tu nam thanh lap den bay gio (Year)\n";
	cout << "10. Nhap luong co ban cua nhan vien trong 1 nam (LCB). Tinh loi nhuan cua sieu thi trong 1 nam (LN)\n";
	cout << "    DS = Doanh so co ban * (Year - Nam thanh lap)\n";
	cout << "11. Nhap vao 1 con so loi nhuan (SLN) va liet ke cac sieu thi co loi nhuan > SLN\n";
	cout << "    LN = Doanh so co ban - (LCB * So luong nhan vien)\n";
	cout << "12. Sap xep danh sach tang dan theo nam thanh lap\n";
	cout << "=================MENU================\n";
}
void DSMenu(qlst s)
{
	KhoiTao(s);
	do {
		int choose;
		Menu();
		cout << "\nNhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			NhapDSST(s);
			break;
		case 2:
			XuatDSST(s);
			break;
		case 3:
			char mstkt[50];
			cout << "\nNhap ma sieu thi can kiem tra: ";
			cin >> mstkt;
			KT_MST(s, mstkt);
			break;
		case 4:
			MaxDSCB(s);
			break;
		case 5:
			MinDSCB(s);
			break;
		case 6:
			MaxSLNV(s);
			break;
		case 7:
			MinSLNV(s);
			break;
		case 8:
			if (Xuat_FIle_TK_SLNV == 0) cout << "\nXuat File that bai\n";
			else
			{
				Xuat_FIle_TK_SLNV(s);
				cout << "\nXuat File thong ke so luong nhan vien thanh cong\n";
			}
			break;
		case 9:
			char mstds[50];
			cout << "\nNhap ma sieu thi can tim. De tinh doanh so: ";
			cin >> mstds;
			DoanhSo(s, mstds);
			break;
		case 10:
			int loinhuan;
			int lcb;
			char mstln[50];
			cout << "\nNhap ma sieu thi can tim. De tinh loi nhuan: ";
			cin >> mstln;

			do {
				cout << "\nNhap luong co ban cua nhan vien trong 1 nam: ";
				cin >> lcb;
				if (lcb < 0)
				{
					cout << "\nSo luong co ban, ban nhap duoi am ";
					cout << "\nXin vui long nhap lai";
				}
			} while (lcb < 0);
			loinhuan = LoiNhuan(s, lcb, mstln);
			if (loinhuan == -1) cout << "\nMa sieu thi can tim ko ton tai or Danh sach sieu thi rong";
			else
				cout << "\nLoi nhuan la: " << loinhuan << endl;
			break;
		case 11:
			ListsWithGreaterProfits(s);
			break;
		case 12:
			DSSTTangDan(s);
			break;
		case 0:
			cout << "\nCAM ON CO DA HUONG DAN EM LAM DO AN TIN HOC";
			cout << "\nKET THUC CHUONG TRINH. THOAT!!!\n";
			system("pause");
			GiaiPhong(s);
			exit(1);
			break;
		default:
			cout << "\nNHAP NGOAI PHAM VI MENU XINH VUI LONG NHAP LAI\n";
			break;
		}
	} while (1);
}
