 #include<iostream>
 using namespace std;
 
 class Process
 {
 	public:
	 	string p_id;
	 	int BT,WT=0,TaT=0;
	 	bool sel=false;
 };
 
 int main()
 {
 	cout<<"Enter no. of process:";
 	int n;
 	cin>>n;
 	Process P[n];
 	int len=0;
 	for(int i=0;i<n;i++)
 	{
 		cout<<"\nEnter process id:";
		cin>>P[i].p_id;
		len+=P[i].p_id.length();
		cout<<"Enter "<<P[i].p_id<<" burst time:";
		cin>>P[i].BT; 
	}
	
	int Queue[n],wait=0;
	int srt,idx;
	for(int i=0;i<n;i++)
	{	
		srt=99999;
		for(int j=0;j<n;j++)
		{
			if(!P[j].sel && P[j].BT < srt)
			{
				srt=P[j].BT;
				idx=j;
			}
		}
		P[idx].sel=true;
		Queue[i]=idx;
		P[idx].WT=wait;
		wait+=P[idx].BT;
		P[idx].TaT=P[idx].BT+P[idx].WT;
	}
	
	cout<<"\n\nProcess\tB.T\tW.t\tT.A.T";
	
	float wt=0,tat=0;
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<P[i].p_id<<"\t"<<P[i].BT<<"\t"<<P[i].WT<<"\t"<<P[i].TaT;
		wt+=P[i].WT;
		tat+=P[i].TaT;
	}
		
	cout<<"\n\nAverage Waiting time: "<<wt/n<<"\nAverage T.A.T: "<<tat/n<<"\n\nGantt Chart:\n";
	for(int i=0;i<n*8+(n+1+len);i++)
		cout<<"-";
	cout<<"\n|";
	for(int i=0;i<n;i++)
	{
		cout<<"    "<<P[Queue[i]].p_id<<"    |";
	}
	cout<<"\n";
	for(int i=0;i<n*8+(n+1+len);i++)
		cout<<"-";
	cout<<"\n0";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<P[Queue[i]].p_id.length()+8;j++)	
			cout<<" ";
		cout<<P[Queue[i]].TaT;
	}
    cout<<"\n";
 	return 0;
 	
 }
 
 
