#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int graph[100][100],dist[100],p,mini_Idx,minimum_dist;
#define inf 9999
bool visited[100];
int main(){
	int n,source;
	printf("Enter no of nodes : ");
	scanf("%d",&n);
	printf("Enter the ajucent matrix :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) scanf("%d",&graph[i][j]);
		dist[i] = inf;
		visited[i] = false;
	}
	printf("Enter the source : ");
	scanf("%d",&source);
	dist[source] = 0;
	// Dijekstra algorithm starts here
	for(p=0;p<n-1;p++){
		minimum_dist=inf;
		for(int q=0;q<n;q++){
			if(minimum_dist > dist[q] && !visited[q]){
				minimum_dist = dist[q] ;
				mini_Idx = q;
			}
		}
		visited[mini_Idx] = true;
		for(int i = 0;i<n;i++){
			if((!visited[i] )&&(graph[mini_Idx][i]) && (dist[mini_Idx] != inf)&& (dist[mini_Idx] + graph[mini_Idx][i] < dist[i])){
				dist[i] = dist[mini_Idx] + graph[mini_Idx][i];
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("\n%d -> %d => %d",source,i,dist[i]);
	}
	return 0;
}
