#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct ThiSinh
{
    string MaTS;
    string TenTS;
    float DiemToan;
    float DiemLy;
    float DiemHoa;
    float tongDiem = DiemToan + DiemLy + DiemHoa;
};
struct Node
{
    ThiSinh Info;
    Node* Next;
};
struct List
{
    Node* Head;
    Node* Tail;
};
void ThiSinhTongDiemCao(List l)
{
    float diemCaoNhat = 0;
    for(Node* p=l.Head ; p != nullptr; p=p->Next)
    {
        if(p->Info.tongDiem > diemCaoNhat)
        {
            diemCaoNhat = p->Info.tongDiem;
        }
    }
    cout <<"Nhung thi sinh co diem cao nhat"<< endl;
    for(Node* p=l.Head ; p != nullptr; p=p->Next)
    {
        if(diemCaoNhat == p->Info.tongDiem)
        {
            cout<<p->Info.TenTS<<endl;
        }
    }
}
Node* timThiSinh(List l, string tenTS)
{
    for(Node* p = l.Head; p!= nullptr; p=p->Next)
    {
        if(p->Info.TenTS == tenTS)
        {
            return p;
        }
    }
    return nullptr;
}
void SapXepThiSinhTheoDiem(List l)
{
    for(Node* i=l.Head ; i != nullptr; i=i->Next)
    {
        for(Node* j =i->Next ; j != nullptr; j=j->Next)
        {
            if(i->Info.tongDiem > j->Info.tongDiem)
            {
                swap(i->Info, j->Info);
            }
        }
    }
}
void XoaThiSinhCuoiCung(List l)
{
    if (l.Head == nullptr)
    {
        cout << "Danh sach rong. Khong co thi sinh de xoa." << endl;
        return;
    }

    if (l.Head == l.Tail)
    {
        delete l.Head;
        l.Head = l.Tail = nullptr;
    }
    else
    {
        Node* thiSinhGanCuoi = nullptr;
        for (Node* p = l.Head; p != nullptr; p = p->Next)
        {
            if (p->Next == l.Tail)
            {
                thiSinhGanCuoi = p;
                break;
            }
        }

        delete l.Tail;

        l.Tail = thiSinhGanCuoi;
        l.Tail->Next = nullptr;
    }
}
void PrintTS(List l)
{
    for(Node* p=l.Head; p!=nullptr; p=p->Next)
    {
        cout<< p->Info.MaTS<<"\t"<<p->Info.TenTS<<"\t"<<p->Info.DiemToan<<"\t"<<p->Info.DiemLy<<"\t"<<p->Info.DiemHoa<<"\t"<<p->Info.tongDiem<<endl;
    }
}

int main()
{
    List DanhSachThiSinh;
    DanhSachThiSinh.Head = DanhSachThiSinh.Tail = nullptr;


    Node* ThiSinh1 = new Node{{"001", "Hong Phat", 8.5, 7.0, 9.5}, nullptr};
    Node* ThiSinh2 = new Node{{"002", "Hong Phat 1", 9.0, 8.0, 8.5}, nullptr};
    Node* ThiSinh3 = new Node{{"003", "Hong Phat 3", 9.0, 8.0, 7.5}, nullptr};
    Node* ThiSinh4 = new Node{{"004", "Hong Phat 4", 9.0, 8.0, 8.5}, nullptr};
    Node* ThiSinh5 = new Node{{"005", "Hong Phat 5", 8.3, 6.5, 8.5}, nullptr};

    DanhSachThiSinh.Head = ThiSinh1;
    ThiSinh1->Next = ThiSinh2;
    ThiSinh2->Next = ThiSinh3;
    ThiSinh3->Next = ThiSinh4;
    ThiSinh4->Next = ThiSinh5;
    DanhSachThiSinh.Tail = ThiSinh5;
    cout<<"Danh sach cac thi sinh: "<<endl;
    PrintTS(DanhSachThiSinh);
    cout<<"Danh sach thi sinh sau khi xoa thi sinh cuoi cung"<<endl;
    XoaThiSinhCuoiCung(DanhSachThiSinh);
    PrintTS(DanhSachThiSinh);

    ThiSinhTongDiemCao(DanhSachThiSinh);
    cout<<"Tim thi sinh co ten: Hong Phat"<<endl;
    Node* timTS = timThiSinh(DanhSachThiSinh, "Hong Phat");
    if(timTS != nullptr)
    {
        cout<<"Co tim thay"<<endl;
    }
    else
    {
        cout<<"Khong co"<< endl;
    }
    SapXepThiSinhTheoDiem(DanhSachThiSinh);
    cout<<"Danh sach thi sinh sau khi sap xep theo tong diem"<<endl;
    PrintTS(DanhSachThiSinh);

    return 0;
}
