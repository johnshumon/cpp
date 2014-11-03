#include <iostream>
#include <queue> 
#include <vector>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int d[1010][1010];
int d2[1010][1010];

int min(int a,int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int main () 
{

	int tcase;
	queue<int> q;
	int N,X,Y,x1,y1,x2,y2,x,y,a,b,i,nx,ny;
  
	cin>>tcase;

	while (tcase--) 
	{
		

		cin>>N>>X>>Y;
		
		cin>>x1>>y1>>x2>>y2;
		
		// all position of d is set to -1
		for(a=0;a<=1000;a++)
			for(b =0;b<=1000;b++)
				d[a][b]=-1;

		// enemy locations are set to zero in d.
		for (i=0; i<N; i++) 
		{  
			cin>>x>>y;
			d[x][y]=0;
			q.push(x); // putting those location value into queue.
			q.push(y);
		}

		while (!q.empty()) 
		{
			x=q.front();
			q.pop();

			y=q.front(); 
			q.pop();
			
			for (i=0; i<4; i++) 
			{ // distance 
				nx=x+dx[i];
				ny=y+dy[i];

				if (nx<0 || nx>=X || ny<0 || ny>=Y) 
					continue;

				if (d[nx][ny]!=-1) 
					continue;

				d[nx][ny]=d[x][y]+1;
				q.push(nx);
				q.push(ny);
			}
		}

		// for(i=0;i<X;i++)
		// {
			// for(j=0;j<Y;j++)
			// {
				// cout <<  d[i][j] << endl;
			// }
			// cout << "\n" << endl;
		// }

		//int min;
		int lo=-1;
		int hi=min(d[x1][y1],d[x2][y2]); // ditsnce of enemy location from starting and ending.
		int sol=-1;
		
		while (lo!=hi) 
		{
			int mid=(lo+hi+1)/2;

			for(a=0;a<=1000;a++)
				for(b =0;b<=1000;b++)
					d2[a][b]=-1;

			d2[x1][y1]=0;
			q.push(x1);
			q.push(y1);

			while (!q.empty()) 
			{
				x=q.front(); q.pop();
				y=q.front(); q.pop();

				for (i=0; i<4; i++) 
				{
					nx=x+dx[i];
					ny=y+dy[i];
			   
					if (nx<0 || nx>=X || ny<0 || ny>=Y) 
						continue;

					if (d[nx][ny]<mid) 
						continue;
			   
					if (d2[nx][ny]!=-1) 
						continue;
			   
					d2[nx][ny]=d2[x][y]+1;
					q.push(nx);
					q.push(ny);
				}

			} // distance calculation from enemy location

			if (d2[x2][y2]==-1) 
				hi=mid-1; 
			else
			{
				lo=mid;
				sol=d2[x2][y2];
			}
			
			for(a=0;a<=X;a++)
				for(b =0;b<=Y;b++)
					cout << "d2: " << d2[a][b] << endl;
			
		}

		cout<<lo<<" "<<sol<<endl;
	}
  
	return 0;  
}
