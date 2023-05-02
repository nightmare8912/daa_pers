#include <iostream>
#define INF 99999
#define MAX 20
#define NIL -1
using namespace std;

void fw(int cost[MAX][MAX], int dist[MAX][MAX], int parent[MAX][MAX], int n)
{
    int D[n + 1][n + 1][n + 1];
    int P[n + 1][n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            D[0][i][j] = cost[i][j];
            if (cost[i][j] == 0 || cost[i][j] == INF)
                P[0][i][j] = NIL;
            else
                P[0][i][j] = i;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (D[k - 1][i][k] + D[k - 1][k][j] < D[k - 1][i][j])
                {
                    D[k][i][j] = D[k - 1][i][k] + D[k - 1][k][j]; 
                    P[k][i][j] = P[k - 1][k][j];
                }
                    
                else
                {
                    D[k][i][j] = D[k - 1][i][j];
                    P[k][i][j] = P[k - 1][i][j];
                }
                    
                
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = D[n][i][j];
            parent[i][j] = P[n][i][j];
        }
    }
}

int main()
{
    int n;
	int i,j;
	
	//Test Input-1
	n=5;
	//Cost Matrix for the input graph
	int Cost[][MAX]={	{0,0,0,0,0,0},
						{0,0,3,8,INF,-4},
						{0,INF,0,INF,1,7},
						{0,INF,4,0,INF,INF},
						{0,2,INF,-5,0,INF},
						{0,INF,INF,INF,6,0}	};

    int Dist[MAX][MAX], Parent[MAX][MAX];
	
	fw(Cost,Dist,Parent,n);
	
	cout<<"\n\nDistance Matrix: ";
	for(i=1;i<=n;i++)
	{
		cout<<"\n";
		for(j=1;j<=n;j++)
		{
			if(Dist[i][j]==INF)
				cout<<"INF\t\t";
			else
				cout<<Dist[i][j]<<"\t\t";
		}		
	}
	
	cout<<"\n\nParent Matrix: ";
	for(i=1;i<=n;i++)
	{
		cout<<"\n";
		for(j=1;j<=n;j++)
		{
			if(Parent[i][j]==NIL)
				cout<<"NIL\t\t";
			else
				cout<<Parent[i][j]<<"\t\t";
		}		
	}
}