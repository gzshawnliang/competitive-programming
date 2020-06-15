#include<iostream>
#include<stdlib.h>
#define N 100000

using namespace std;
 
void GenerateRandomGraphs(int e)
{
   int i, j, edge[e][2], count;
 
   i = 0;
// generate a connection between two random numbers, for //sample a small case, limit the number of vertex to 10.

   while(i < e)
   {
	  edge[i][0] = rand()%N+1;
	  edge[i][1] = rand()%N+1;
	  i++;
   }
 
//Print all the connection of each vertex, irrespective of the //direction.

   for(i = 0; i < N; i++)
   {
	  count = 0;
	  //cout<<"\n\t"<<i+1<<"-> { ";
	  for(j = 0; j < e; j++) 
      {

	     if(edge[j][0] == i+1) 
         {
		    cout << i +1 << " "<<edge[j][1]<<"\n";
            count++;
		 }
		 else if(edge[j][1] == i+1) 
         {
		    cout << i +1 << " " <<edge[j][0]<<"\n";
			count++;
		 }
//Print “Isolated vertex” for the vertex having zero degree.
		 else if(j == e-1 && count == 0)
         {

         }
			//cout<<"Isolated Vertex!";
       }
//         cout<<" }";
   }	
}
 
 
int main()
{

   freopen("CF_1364D_EhabsLastCorollary.in", "w", stdout);

   int n, i ,e;
   e=199999;
   cout << N << " " << e << " 3\n";
   GenerateRandomGraphs(e);
}