#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// a)
struct NV
{
    char MaNV[40];
    char TenNV[40];
    float Luong;
};
struct Node
{
    NV info;
    Node *next;
};
struct List
{
    Node *Head;
    Node *Tail;
};

//b)
float MaxLuong(List l)
{
    float maxLuong = 0.0;
    for(Node *p = l.Head; p!= nullptr; p= p->next)
    {
        if(p->info.Luong > maxLuong)
        {
            maxLuong = p->info.Luong;
        }
    }
    return maxLuong;
}
Node* timMaNV(List l, char ma[])
{
    for(Node *p = l.Head; p!= nullptr; p=p->next)
    {
        if(strcmp(p->info.MaNV, ma) == 0)
        {
            return p;
        }
    }
    return nullptr;
}
void SapXepTangDan(List l)
{
    for(Node *i= l.Head; i!= l.Tail; i=i->next)
    {
        for(Node* j =i->next; j!= nullptr; j=j->next)
        {
            if(i->info.Luong > j->info.Luong)
            {
                swap(i->info,j->info);
            }
        }
    }
}
void PrintNv(List l)
{
    for(Node* p=l.Head; p!=nullptr; p=p->next)
    {
        cout<< p->info.MaNV<<"\t"<<p->info.TenNV<<"\t"<<p->info.Luong<<endl;
    }
}

int main()
{
    List NhanVienList;
    NhanVienList.Head = NhanVienList.Tail = nullptr;

    NV NV1 = {"001", "John Doe", 5000.0};
    NV NV2 = {"002", "Jane Doe", 6000.0};
    NV NV3 = {"003", "Bob Smith", 4500.0};

    Node *node1 = new Node{NV1, nullptr};
    Node *node2 = new Node{NV2, nullptr};
    Node *node3 = new Node{NV3, nullptr};

    NhanVienList.Head = node1;
    node1->next = node2;
    node2->next = node3;
    NhanVienList.Tail = node3;

    // Test your functions
    float maxSalary = MaxLuong(NhanVienList);
    cout << "Luong cao nhat: " << maxSalary << endl;

    Node *foundEmployee = timMaNV(NhanVienList, "002");
    if (foundEmployee != nullptr)
    {
        cout << "Tim nv: " << foundEmployee->info.TenNV << endl;
    }
    else
    {
        cout << "Khong tim thay" << endl;
    }

    SapXepTangDan(NhanVienList);
    cout << "Sap xep:" << endl;
    PrintNv(NhanVienList);

    return 0;
}
