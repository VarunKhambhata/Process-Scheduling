 #include<iostream>
 #include<math.h>
 using namespace std;
 
 class Process
 {
 	public:
	 	string p_id;
	 	int BT,WT=0,TaT=0,rBT;
	 	int totalSlice;
	 	
	 	int run(int qntm)
	 	{
			 int ret=0;
			if(rBT>qntm)
			{
				rBT-=qntm;
				ret=qntm;
			}
			else
			{
				ret=rBT;
				rBT=0;
			}
			return ret;
			//rBT>qntm?(rBT-=qntm):(rBT=0);
		}		
		void setBT(int n,int Q)
		{
			rBT=BT=n;
			totalSlice=ceil((float)BT/Q);
		}
		void wait(int qntm)
		{
			if(rBT!=0)
				WT+=qntm;
		}
 };
 
 class Slot
 {
	public:
	 int start,end, p_link=-1;
 };


 int main()
 {
 	cout<<"Enter no. of process: ";
 	int n,Q;
 	cin>>n;
 	cout<<"Enter Quantum/time slice: ";
 	cin>>Q;
 	Process P[n];
 	
 	int x,T=0;

 	for(int i=0;i<n;i++)
 	{
 		cout<<"\nEnter process id: ";cin>>P[i].p_id;
		cout<<"Enter "<<P[i].p_id<<" burst time: ";
		cin>>x;
		P[i].setBT(x,Q);
		T+=P[i].totalSlice;
	}
 	Slot Queue[T];
 	int Time=0;
	int top=0,run,len=0;
	for(int i=0,I=0;i<T;i++,I++)
	{
		if(I==n)	I=0;
		
		if(P[I].rBT > 0)
		{
			run=P[I].run(Q);
			len+=P[I].p_id.length();
			for(int z=0;z<n;z++)
			{
				if(z!=I)
					P[z].wait(run);
			}
			Queue[top].p_link=I;
			Queue[top].start=Time;
			Time+=run;
			Queue[top].end=Time;
			top++;
		}
		else i--;
	}


	
 	float tat=0,wt=0;
	cout<<"\nProcess\tB.T\tW.T\tT.A.T";
	for(int i=0;i<n;i++)
	{
		P[i].TaT=P[i].BT+P[i].WT;
		tat+=P[i].TaT;
		wt+=P[i].WT;
		cout<<"\n"<<P[i].p_id<<"\t"<<P[i].BT<<"\t"<<P[i].WT<<"\t"<<P[i].TaT;
	}
		
	 cout<<"\n\nAverage Waiting time: "<<wt/n<<"\nAverage T.A.T: "<<tat/n;

	cout<<"\n\nGantt Chart:\n";
	for(int i=0;i<T*8+(T+1+len);i++)	cout<<"-";
	cout<<"\n|";
	 for(int i=0;i<T;i++)
		cout<<"    "<<P[Queue[i].p_link].p_id<<"    |";
	cout<<"\n";
	for(int i=0;i<T*8+(T+1+len);i++)	cout<<"-";
	cout<<"\n"<<Queue[0].start;
	for(int i=0;i<T;i++)
		cout<<"          "<<Queue[i].end;
	cout<<"\n";
	return 0;
 }
