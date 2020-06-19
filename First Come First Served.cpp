#include<iostream>
using namespace std;

class Process
{
    public:
        int WaitTM,BT,TaT;
        string p_id;
       // bool set=false;
};

int main()
{
    if(system("cls")!=0)
            system("clear");
    cout<<"Enter no. of process:";
    int n;
    cin>>n;
    Process Pcs[n];
    int wait=0;
    for(int i=0;i<n;i++)
    {
        cout<<"\n\nEnter p_id: ";
        cin>>Pcs[i].p_id;
        cout<<"Enter Burst time:";
        cin>>Pcs[i].BT;
        Pcs[i].WaitTM=wait;
        wait+=Pcs[i].BT;        
        Pcs[i].TaT=Pcs[i].WaitTM+Pcs[i].BT;
    }
   
    
    cout<<"\n\nProcess\tB.T\tW.t\tT.A.T\n";
    float avgW=0,avgT=0;
    for(int i=0; i<n; i++)
    {
        cout<<Pcs[i].p_id<<"\t"<<Pcs[i].BT<<"\t"<<Pcs[i].WaitTM<<"\t"<<Pcs[i].TaT<<"\n";
        avgW+=Pcs[i].WaitTM;
        avgT+=Pcs[i].TaT;
    }

    cout<<"\nAverage Waiting Time: "<<avgW/n<<"\nAverage Turn-Around-Time: "<<avgT/n;

    cout<<"\n\nGantt Chart:\n";
    int len=0;
    for(int i=0; i<n; i++)
        len+=Pcs[i].p_id.length();
    len+=n+1;
    string L;
    for(int i=1; i<=n*8+len;i++)
        L+='-';
    cout<<L<<"\n|";
    for(int i=0; i<n; i++)
        cout<<"    "<<Pcs[i].p_id<<"    |";
    cout<<"\n"<<L<<"\n0";
    for(int i=0; i<n; i++)
        cout<<"          "<<Pcs[i].TaT;
    cout<<"\n";
    return 0;
}   
