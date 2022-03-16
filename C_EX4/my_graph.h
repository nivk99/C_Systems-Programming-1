#include <stdlib.h>
#include <stdio.h>
#define True 1
#define False 0
typedef struct EdgeData
{
    int Dest;
    int Weight;
    struct EdgeData *Next_Edge;

}EdgeData, *PEdgeData;

typedef struct NodeData
{
    int distance;//DIJKSTRA;
    int parent;//DIJKSTRA;
    int Key;
    PEdgeData List_outDegree;
    struct NodeData *Next_Node;

}NodeData,*PNodeData;


typedef struct Graph
{
    int size_Node;
    PNodeData List_Node;

}Graph,*PGraph;

void NewList(int size,PGraph grap);
void AddEdge(int key,int dest,int w,PGraph grapg);
void Free_Graph(PGraph graph);
void AddNode(PGraph grapg,int key);
void DeleteNode(PGraph graph,int key);
int ShortPath(PGraph graph,int src,int dest);
void TCP(PGraph graph,int *arr,int size);
int ShortPath1(PGraph graph,int src,int dest);
