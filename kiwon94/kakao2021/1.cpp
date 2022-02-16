#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct r_data{
    bool is_del=false;
    int r_num;
    struct r_data* next=nullptr;
    struct r_data* prev=nullptr;
};


r_data* cur;

void command_U(int X)
{
    cout<<"cur num: "<<cur->r_num<<endl;
    for(int i=0;i<X;i++)
    {
        cur=cur->prev;
    }
    
}

void command_D(int X)
{
    cout<<"cur num: "<<cur->r_num<<endl;
    for(int i=0;i<X;i++)
    {
        cur=cur->next;
    }
}

void command_C(vector<r_data*>* last_del_list)
{
    cout<<"cur num: "<<cur->r_num<<endl;
    cur->is_del=true;
    cout<<"delete num: "<<cur->r_num<<endl;
    last_del_list->push_back(cur);
    if(cur->next!=nullptr)
    {
        cur->prev->next=cur->next;
        cur->next->prev=cur->prev;
        cur=cur->next;
    }
    else
    {
        cur->prev->next=nullptr;
        cur=cur->prev;
    }
}

void command_Z(vector<r_data*>* last_del_list)
{
    cout<<"cur num: "<<cur->r_num<<endl;
    r_data* last_del=last_del_list->back();
    cout<<"restore num: "<<last_del->r_num<<endl;
    last_del->is_del=false;
    last_del->prev->next=last_del;
    if(last_del->next!=nullptr)
    {
        last_del->next->prev=last_del;
    }
    last_del_list->pop_back();
}


string solution(int n, int k, vector<string> cmd) {
    vector<r_data*>* last_del_list;
    r_data* head=new r_data;
    r_data* end=head;
    for(int i=0;i<n;i++)
    {
        r_data* x = new r_data;
        x->r_num=i;
        while(end->next!=nullptr)
        {
            end=end->next;
        }
        end->next=x;
        x->prev=end;       
    }
    
    cur=head;
    
    for(int i=0;i<k;i++)
    {
        cur=cur->next;
    }
    
    for(int i=0;i<cmd.size();i++)
    {
        if(cmd[i][0]=='U')
        {
            char a=cmd[i][2];
            int b=int(a)-48;
            command_U(b);
        }
        
        else if(cmd[i][0]=='D')
        {
            char a=cmd[i][2];
            int b=int(a)-48;
            command_U(b);
        }
        
        else if(cmd[i][0]=='C')
        {
            command_C(last_del_list);
        }
        
        else if(cmd[i][0]=='Z')
        {
            command_Z(last_del_list);
        }
    }
    
    r_data* imsi=head;
    while(imsi->next!=nullptr)
    {
        imsi=imsi->next;
        cout<<imsi->r_num<<endl;
    }
    

    string answer = "";
    return answer;
}

int main()
{
    string s;
    cin>>s;
    int n,k;
    cin>>n>>k;
    vector<string>s_set;
    s_set.push_back(s);
    solution(n,k,s_set);
}