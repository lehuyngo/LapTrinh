#include "SymbolTable.h"
#define  linear() hp=(h+this->c1*i) % this->m;
#define  quadratic() hp=(h+this->c1*i+this->c2*i*i)%this->m;
#define  double() hp=(h1+i*h2)%this->m;

string SymbolTable::check_str(string s)
{   
    if(s=="number" || s=="string" || s=="false" || s=="true" || s=="static")
    {
        return "fail";
    }
    if((s=="ASSIGN")||(s=="PRINT")||(s=="INSERT")||(s=="BEGIN")||(s=="END")||(s=="LOOKUP"))
    {
        return "fail";
    }
    if(s=="")
    {
        return "fail";
    }
    if ((s[0]>='0') && (s[0]<='9') )
    {
        for (unsigned int i = 1; i < s.length(); i++)
        {
            if ((s[i] < '0') || (s[i] > '9'))
               { 
                   
                   return "fail";
                   }
        }
        return "number";
    }
    else if (s[0] == '\'' && s[s.length() - 1] == '\'')
    {
        for (unsigned int i = 1; i < s.length() - 1; i++)
        {
            bool check = !((s[i] == ' ') || ((s[i] >= '0') && (s[i] <= '9')) || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')));
            if (check)
                {
                     
                    return "fail";
                    }
        }
        return "string";
    }
    else if(s[0]<='z' && s[0]>='a')
    {
        for (unsigned int i = 1; i < s.length() - 1; i++)
        {
            bool check = !((s[i] == '_') || ((s[i] >= '0') && (s[i] <= '9')) || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')));
            if (check)
               {
                  
                   return "fail";
                }
        }
        return "ID";
    }
   
    return "fail";
}
string  SymbolTable::make_key(string id,int block)
{
    string ans="";
    ans+=to_string(block);
    for(unsigned int i=0;i<id.length();i++)
    {
        ans+=to_string((int)id[i]-48);
    }
    return ans;
}
bool  SymbolTable::cat_str(const string s,string lenh,string &x,string &val,int &num_thamso)
{
    x="";

    unsigned int i=lenh.length()+1;
    if(i>=s.length())
    {
        return false;
    }
    while(s[i]!='\0' &&s[i]!=' ' )
    {
        x+=s[i];
        i++;
    }
    string check=this->check_str(x);
    if(check=="fail") { 
         
        return false;    
    }
    if(lenh=="INSERT" && s[i]!='\0')
    {
        string temp=s.substr(i+1,s.length()-i-1);
        if(temp.find(" ")<temp.length())
            {
                return false;
            }
        num_thamso=stoi(temp) ;  ////
        return true;
    }
    if(lenh=="ASSIGN")
    {
        if(s[i]==' ')
        {
            val=s.substr(i+1,s.length()-i-1);
            if(val.find(" ")<val.length())
            {
                return false;
            }
            return true;
        
        
        }
        else { return false;}
    }
    return true;
    /*i++;
    int dem_dau_nhay=0;
    if(i>=s.length())
    {
        this->Clear();
        throw InvalidInstruction(s);

    }
    while(s[i]!='\0' )
    {
        if(s[i]==' ')
        {
            if(dem_dau_nhay==0)
            {
                break;
            }
        }
        if(s[i]=='\'')
        {
            dem_dau_nhay=1-dem_dau_nhay;
        }
        val_type+=s[i];
        i++;
    }
    if(!stic)   //. stic false thi khong can tinh static (ham assign)
    {
        if(s[i]!='\0'){ 
            this->Clear();
            throw InvalidInstruction(s);
            }
        return;
    }
    i++;
    if(i>=s.length())
    {
        this->Clear();

        throw InvalidInstruction(s);

    }


    string _stic="";
    while(s[i]!=' ' && s[i]!='\0')
    {
        _stic+=s[i];
        i++;
    }

    if(_stic=="false") 
    { 
        stic=false;
    }
    else if(_stic=="true")
    {
        stic=true;
    }
    else
    {
        this->Clear();
         throw InvalidInstruction(s);
    }

    if(s[i]!='\0'){ 
        this->Clear();
        throw InvalidInstruction(s);
        }
    */

}
int  SymbolTable::module(string s,int t)
{
    int res = 0;
    for (unsigned int i = 0; i < s.length(); i++)
        res = (res * 10 + (int)s[i] - '0') % t;
 
    return res;
}

int SymbolTable::hashing(string val,int &num_jump,bool insert)
{
    int h,h1,h2,hp,i=0;
    if(this->pp=="LINEAR")
    {
         h=this->module(val,this->m),hp=h,i=0;
    }
        
    if(this->pp=="QUADRATIC")
    {
         h=this->module(val,this->m),hp=h,i=0;
    }
    if(this->pp=="DOUBLE")
    {
         h1=this->module(val,this->m),h2=1+this->module(val,this->m-2),hp=h1,i=0;
    }
    while(!(this->arr.vail[hp]))
        {
            if(val==this->arr.key[hp])
            {
                if(insert)
                return -1;
                else return hp;
            }
            i++;
            num_jump++;
            if(this->pp=="LINEAR")
            {
                linear();
            }
            else if(this->pp=="QUADRTIC")
            {
                quadratic();
            }
            else if(this->pp=="DOUBLE")
            {
                double();
            }
        }
        if(insert)
            return hp;
            else return -1;
    return 0;
}
void SymbolTable::phuong_phap(string s)
{
    if(s.find("LINEAR")<s.length())
    {
        this->pp="LINEAR";
    }
    else if(s.find("QUADRATIC")<s.length())
    {
        this->pp="QUADRATIC";
    }
    else if(s.find("DOUBLE")<s.length())
    {
        this->pp="DOUBLE";
    }
    else 
    { 
        //cout<<1<<endl;
        throw InvalidInstruction(s);
    }
    this->m=0;
    this->c1=0;
    this->c2=0;
    unsigned int i=0;
    while (s[i]!=' ')
    i++;
    i++;
    while(s[i]!=' ')
    {
        if(s[i]<'0'|| s[i]>'9')
        //cout<<2<<endl,
        throw InvalidInstruction(s);
        this->m=this->m*10+(int)s[i]-48;
        i++;
    }
    i++;
    while(s[i]!=' ' && s[i]!='\0')
    {
        if(s[i]<'0'|| s[i]>'9')
        //cout<<"3"<<endl,
        throw InvalidInstruction(s);
        this->c1=this->c1*10+(int)s[i]-48;
        i++;
    }
    if(s[i]==' ')
    {
        i++;
        while(s[i]!=' ' && s[i]!='\0')
        {
        if(s[i]<'0'|| s[i]>'9')
        //cout<<4<<endl,
        throw InvalidInstruction(s);
        this->c2=this->c2*10+(int)s[i]-48;
        i++;
        }
    }
    this->arr=llist(this->m);
}
void SymbolTable::so_sanh_type(string s,string &a,string &b)
{
    if(a=="" && b=="")
    {
        this->Clear();
        throw TypeCannotBeInfered(s);
    }
    if(a!="" && b!="" && a!=b)
    {
        this->Clear();
        throw TypeMismatch(s);
    }
    a=a==""?b:a;
    b=b==""?a:b;

}
void SymbolTable::Insert(string s)
{
    if(this->count==this->m)
    {
        this->Clear();
        throw Overflow(s);
    }
    int num_thamso=0,num_jump=0;
    string val="",id="";
    this->cat_str(s,"INSERT",id,val,num_thamso);
    string key=make_key(id,this->block);
    int vt=this->hashing(key,num_jump,true);
    if(vt==-1)
    {
        this->Clear();
        throw Redeclared(s);
    }
    cout<<num_jump<<endl;
    this->arr.vail[vt]=false;
    this->arr.key[vt]=key;
    node *temp=this->arr.get_index(vt);
    temp->ID=id;
    temp->block_=this->block;
    if(num_thamso!=0)
    {
        if(this->block!=0)
        {
            this->Clear();
            throw InvalidDeclaration(s);
        }
        temp->fun=true;
        temp->num_of_parameters=num_thamso;
        temp->ThamSo=new string[num_thamso];
        for(int i=0;i<num_thamso;i++)
        temp->ThamSo[i]="";
    }
    this->count++;

}
int SymbolTable::search(string s,string id,int &num_jump)
{
    int vt=-1,i=this->block,jump=0;
    do
    {
        string key=this->make_key(id,i);
        vt=hashing(key,jump,false);
        i--;
    }
    while (i>=0 && vt==-1);
    if(vt==-1)
    {
        this->Clear();
       // cout<<id<<endl;
        throw Undeclared(s);
    }
    num_jump+=jump;
    return vt;
}
void SymbolTable::Assign(string s)
{
    
    string id,val;
    int num,num_jump=0;
    cat_str(s,"ASSIGN",id,val,num);
    if(check_str(id)!="ID")
    {
        this->Clear();
        throw InvalidInstruction(s);
    }
    if(val.find("(")<s.length() && val[val.length()-1]==')')
    {   
        node *node_fun=call_fun(s,val,num_jump);
        int vt_id=this->search(s,id,num_jump);
        node *node_id=this->arr.get_index(vt_id);
        if(node_id->fun)
        {
            this->Clear();
            throw TypeMismatch(s);
        }
        this->so_sanh_type(s,node_fun->type,node_id->type);
        node_id->val=val;
        cout<<num_jump<<endl;
        return;
    }

    string type_of_val=this->check_str(val);
    if(type_of_val=="ID")
    {
            node *node_id,*node_val;
            int vt=this->search(s,val,num_jump);
            if(vt==-1) 
            {
                this->Clear();
                throw Undeclared(s);
            }
            node_val=this->arr.get_index(vt);

            vt=this->search(s,id,num_jump);
            if(vt==-1) 
            {
                this->Clear();
                throw Undeclared(s);
            }
            node_id=this->arr.get_index(vt);
            this->so_sanh_type(s,node_id->type,node_val->type);
            node_id->val=node_val->val;
            cout<<num_jump<<endl;
            return;
    }
    if(type_of_val=="string" || type_of_val=="number")
    {
            int vt=this->search(s,id,num_jump);
            if(vt==-1) 
            {
                this->Clear();
                throw Undeclared(s);
            }
            node *node_id=this->arr.get_index(vt);
            if(node_id->type!="")
            {
                    if(node_id->type!=type_of_val)
                    {
                        this->Clear();
                        throw TypeMismatch(s);
                    }
            }
            else node_id->type=type_of_val;
            node_id->val=val;
            cout<<num_jump<<endl;
            return;
    }

}
node *SymbolTable::call_fun(string s,string ham,int &num_jump)
{
    int v=ham.find("(");
    int vt=0;

    string name_fun=ham.substr(0,v);
    vt=this->search(s,name_fun,num_jump);
    node *node_fun=this->arr.get_index(vt);
    if(node_fun->fun==false) 
    {
        this->Clear();
        throw TypeMismatch(s);
    }
    string cum_tham_so=ham.substr(v+1,s.length()-v-1),a_thamso="";
    //cout<<cum_tham_so<<endl;
    int i=0,vt_thamso=0;
    while(cum_tham_so[i]!='\0')   //kiem tra cac tham so co dung ko
    {
            if(vt_thamso>=node_fun->num_of_parameters)  // so luong tham so lon hon
            {
                this->Clear();
                throw Undeclared(s);
            }
            a_thamso=a_thamso+cum_tham_so[i];
            i++;
            if(cum_tham_so[i]==',' ||cum_tham_so[i]==')')
            {
                string type_a_thamso=check_str(a_thamso);
                if(type_a_thamso=="fail")
                {
                    this->Clear();
                    throw InvalidInstruction(s);
                }
                if(type_a_thamso=="ID")
                {
                    int chiso_thamso=this->search(s,a_thamso,num_jump);

                    if(chiso_thamso==-1)
                    {
                        this->Clear();
                        throw Undeclared(s);
                    }
                    node *node_thamso=this->arr.get_index(chiso_thamso);
                    if(node_thamso->fun==true)
                    {
                        this->Clear();
                        throw TypeMismatch(s);
                    }
                    this->so_sanh_type(s,node_thamso->type,node_fun->ThamSo[vt_thamso]);   
                }
                if(type_a_thamso=="string" || type_a_thamso=="number")
                {
                    this->so_sanh_type(s,type_a_thamso,node_fun->ThamSo[vt_thamso]);
                }
                if(cum_tham_so[i]==')')
                { 
                    if(vt<node_fun->num_of_parameters-1)
                    {
                        this->Clear();
                        throw TypeMismatch(s);
                    }
                    break; 
                }
                
                vt_thamso++;
                a_thamso="";
                i++;
                
            }
    }
    return node_fun;
}
void SymbolTable::Call(string s)
{
    int num_jump=0;
    string ham=s.substr(5,s.length()-5);
    call_fun(s,ham,num_jump);
    cout<<num_jump<<endl;
}
void SymbolTable::Begin()
{
    this->block++;
}
void SymbolTable::End()
{
    if(this->block==0)
    {
        this->Clear();
        throw UnknownBlock();
    }
    node *p=this->arr.head;
    for(int i=0;i<this->arr.count;i++)
    {
        if(p->block_==this->block && !(this->arr.vail[i]) )
        {
            this->arr.vail[i]=true;
            this->arr.key[i]="";
            p->fun=false;
            p->num_of_parameters=0;
            p->ID="";
            p->type="";
            p->val="";
            p->block_=0;
            this->count--;
            delete[] p->ThamSo;
        }
        p=p->next;
        
    }
    this->block--;
    
}
void SymbolTable::Print()
{

    node *p=this->arr.head;
    bool is_print=false;
    for(int i=0;i<this->m;i++)
    {
        if(!(this->arr.vail[i]))
        {
            if(is_print)
            cout<<" ";
            cout<<p->ID<<"//"<<p->block_;
            is_print=true;
            
        }
        p=p->next;
    }
    if(is_print) cout<<endl;
}
void SymbolTable::run(string filename)
{

    fstream f;

    f.open(filename,ios::in);
    string s;
    getline(f,s);
    this->phuong_phap(s);
    while(!f.eof())
    {
        getline(f,s);
        if(s.find("INSERT")<s.length())
        {
            this->Insert(s);
        }
        else if(s=="PRINT")
        {
            this->Print();
        }
        else if(s=="END")
        {
            this->End();
        }
        else if(s=="BEGIN")
        {
            this->Begin();
        }
        else if(s.find("ASSIGN")<s.length())
        {
            this->Assign(s);
        }
        else if(s.find("CALL")<s.length())
        {
            this->Call(s);
        }
        else 
        {
            this->Clear();
            throw InvalidInstruction(s);
        }
        
    }
    this->Clear();
    if(this->block!=0)
    {
        throw UnclosedBlock(this->block);
    }
   
   f.close();

}