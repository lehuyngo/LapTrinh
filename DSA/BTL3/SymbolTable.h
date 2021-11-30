#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"
enum Status{
     nil=0,
     deleted=-1,
     not_nil=1
    
};
class node {
        public:
            node()
            {
                ID="";
                type="";
                val="";
                next=nullptr;
                fun=false;
                block_=0; num_of_parameters=0;
            }
            void make_parameters(int n)
            {
                this->ThamSo=new string[n];
                for(int i=0;i<n;i++)
                {
                    this->ThamSo[i]="";
                }
            }
            
            ~node(){};
            string ID, type, val;
            node *next;
            node  *pre;
            string *ThamSo;
            bool fun;
            int block_,num_of_parameters;
    
    };
class SymbolTable
{
private: 
    
    class mang
    {
        public:
        node *head;
        Status *STATUS;
        string *key;
        int count;
        
            mang()
            {
                head=nullptr;
            }
            mang(int size)
            {
                this->count=size;
                this->STATUS=new Status[size];
                this->key=new string[size];
                for(int i=0;i<size;i++) this->key[i]="",this->STATUS[i]=nil;
                this->head=new node();
                node *p=this->head;
                for(int i=1;i<this->count;i++)
                {
                    p->next=new node();
                    p=p->next;

                }

            }
            node *get_index(int index)
            {
                if(index<0 || index>=this->count)
                {
                    return nullptr;

                    
                }
                node *p=this->head;
                for(int i=0;i<index;i++)
                p=p->next;
                return p;
            }
            void clear()
            {
                node *p=this->head;
                while(p!=nullptr)
                {
                    node *q=p;
                    p=p->next;
                    if(q->num_of_parameters!=0)
                    {
                        delete[] q->ThamSo;
                    }
                    delete q;
                }
                delete[] STATUS;
                delete[] key;
            }


    };
    mang arr;
    int block=0,count=0;
    int m,c1,c2;
    string pp,key;
public:
    SymbolTable() {}
    
    
    void Clear()
    {
        this->arr.clear();
    }
    void so_sanh_type(string s,string &a,string &b);
    int module(string s,int t);
    string make_key(string id,int block);
    int hashing(string s,string val,int &num_jump,bool check);
    bool cat_str(const string s,string lenh,string &x,string &val,int &num_thamso);
    node *call_fun(string s,string ham,int &num_jump);
    int search(string s,string id,int &num_jump);
    string check_str(string s);
    void phuong_phap(string s);
    void Insert(string s);
    void Assign(string s);
    void LookUp(string s);
    void Call(string s);
    void Begin();
    void End();
    void Print();
    void run(string filename);
    
};
#endif