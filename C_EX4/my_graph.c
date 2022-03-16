#include "my_graph.h"
#define INF 999
void FreeEdge(PEdgeData head);
PNodeData FindingNode(PGraph grapg,int key);

void NewList(int size,PGraph grap)
{
    PNodeData *node=&(grap->List_Node);
    grap->size_Node=size;
    for(int i=0;i<size;i++)
    {
        *node=(PNodeData)calloc(1,sizeof(NodeData));
        if(!node)
        {
            exit(1);
        }
        (*node)->Key=i;
        (*node)->Next_Node=NULL;
        (*node)-> List_outDegree=NULL;
        node=&((*node)->Next_Node);
    }
}
void DeleteNode(PGraph graph,int key)
{
    PNodeData head=graph->List_Node->Next_Node;
    PNodeData tail=graph->List_Node;
    if(tail->Key==key)
    {
        if(tail->List_outDegree)
        {
            FreeEdge(tail->List_outDegree);
        }
        free(tail);
        graph->List_Node=head;
        graph->size_Node--;
    }
    else
    {
        while (head)
        {
            if(head->Key==key)
            {
                if(head->List_outDegree)
                {
                     FreeEdge(head->List_outDegree);
                }
                tail->Next_Node=head->Next_Node;
                free(head);
                 graph->size_Node--;
                 break;
            }
            head =head->Next_Node;
            tail=tail->Next_Node;
        }

    }

     PNodeData list=graph->List_Node;
    while(list)
    {
        if(list->List_outDegree)
        {
            PEdgeData head_=graph->List_Node->List_outDegree->Next_Edge;
            PEdgeData tail_=graph->List_Node->List_outDegree;
            if(tail_->Dest==key)
            {
                list->List_outDegree=head_;
                free(tail_);
            }
            else
            {
                while(head_)
                {
                    if(head_->Dest==key)
                    {
                        tail_=tail_->Next_Edge->Next_Edge;
                        free(head_);
                        break;
                    }
                     head_=head_->Next_Edge;
                     tail_=tail_->Next_Edge;
                }

            } 
        }
        list=list->Next_Node;  
     
    }
}


void FreeEdge(PEdgeData head){
  PEdgeData next;
 // PEdgeData kill=head;
  while(head){
      next=head->Next_Edge;
      free(head);
      head=next;
  }
  //kill=NULL;
}

void AddEdge(int key,int dest,int w,PGraph grapg){
    PNodeData *list=&(grapg->List_Node);
    while((*list)){
        if((*list)->Key==key){
            PEdgeData e=(PEdgeData)calloc(1,sizeof(EdgeData));
            e->Dest=dest;
            e->Weight=w;
            if(!(*list)->List_outDegree){
                e->Next_Edge=NULL;
                  (*list)->List_outDegree=e;
                  return;
            }
            e->Next_Edge=(*list)->List_outDegree;
            (*list)->List_outDegree=e;
            return;
        }
        list=&((*list)->Next_Node);
    }
    
}
void AddNode(PGraph grapg,int key){
    PNodeData *list=&(grapg->List_Node);
    while((*list)){
        if((*list)->Key==key){
            if((*list)->List_outDegree){
                  FreeEdge((*list)->List_outDegree);
                  (*list)->List_outDegree=NULL;
            }
            return;
        }
        list=&((*list)->Next_Node);
    }
    PNodeData v=(PNodeData)calloc(1,sizeof(NodeData));
    v->Key=key;
    grapg->size_Node++;
    v->Next_Node=grapg->List_Node;
    grapg->List_Node=v;
}

void Free_Graph(PGraph graph)
{
    if(graph->size_Node==0||graph->List_Node==NULL)
    {
        return;
    }
    PNodeData v=graph->List_Node;
    int size=graph->size_Node;
  for(int i=0;i<size;i++)
  {
      if(v){
          if(v->List_outDegree)
          {

            PEdgeData next;
            PEdgeData head=v->List_outDegree;
            while(head)
            {
                next=head->Next_Edge;
                free(head);
                head=next;
            }
              
          }
          PNodeData kill =v;
           v=v->Next_Node;
          free(kill);
          continue;

      }
      v=v->Next_Node;
  }
  graph->size_Node=0;
    
}

void Recursion(PNodeData V,int w,int dist,int parent,PGraph *grapg){
    if(!V){
        return;
    }
    int sum=w+dist;
    if((V->distance)>sum){
        V->distance=sum;
        V->parent=parent;
    PEdgeData e=V->List_outDegree;
     PNodeData next;
    while (e)
    {
        next=FindingNode(*grapg,e->Dest);
         if(!next){
            return;
         }
        Recursion(next,e->Weight,V->distance,V->Key,grapg);
        e=e->Next_Edge;
    }
    }

}

int ShortPath1(PGraph graph,int src,int dest){
    int *arr=(int*)calloc(graph->size_Node,sizeof(int));
    if(!arr){
        exit(1);
    }
    PNodeData v=graph->List_Node;
    int j=0;
    while (v)
    {   arr[j]=INF;
        v->distance=j;
        v=v->Next_Node;
        j++;
    }
    
    arr[FindingNode(graph,src)->distance]=0;
    PNodeData node =graph->List_Node;
    while (node)
    {
        PEdgeData edge=node->List_outDegree;
        while (edge)
        {
            int i=FindingNode(graph,edge->Dest)->distance;
            if(arr[i]>arr[node->distance]+edge->Weight){
                arr[i]=arr[node->distance]+edge->Weight;
            }
           edge=edge->Next_Edge;
        }
        

        node=node->Next_Node;
    }
    int ans=arr[FindingNode(graph,dest)->distance];
    free(arr);
    return ans;
}

int ShortPath(PGraph graph,int src,int dest){
    if(src==dest){
        return 0;
    }
    if(!FindingNode(graph,src)||!FindingNode(graph,dest)){
        return -1;
    }
    if(!graph){
        return -1;
    }
    PNodeData node=graph->List_Node;
    PNodeData start;
    while (node)
    {
        if(node->Key==src){
            start=node;
        }
        node->distance=INF;
        node->parent=INF;
        node=node->Next_Node;
    }
    start->distance=0;
    start->parent=src;
    PEdgeData e=start->List_outDegree;
    if(!e){
        return -1;
    }
    while (e)
    {
        PNodeData next=FindingNode(graph,e->Dest);
        Recursion(next,e->Weight,0,src,&graph);
      e=e->Next_Edge;
    }
    
    Recursion(start,INF,0,INF,&(graph));
    PNodeData sr =FindingNode(graph,dest);
    if(sr->distance>=INF){
        return -1;
    }
    
    return sr->distance;

}

PNodeData FindingNode(PGraph grapg,int key){
PNodeData list=grapg->List_Node;
while (list)
{
    if(list->Key==key){
        return list;
    }
    list=list->Next_Node;
}
return NULL;

}

void TCP(PGraph graph,int *arr,int size){
    printf("TSP shortest path: ");
    int mat[size][size];
    int temp[size];
    for (int i = 0; i < size; i++)
    {
        temp[i]=0;
        mat[i][0]=arr[i];
      
    }
    for (int k = 0; k < size; k++)
    {
        for(int i=0;i<size-1;){
            int sum=INF;
            int min=INF;
            int key=-1;
            for(int j=0;j<size;j++){
                if(arr[j]==mat[k][i]){
                    continue;
                }
                sum=ShortPath(graph,mat[k][i],arr[j]);
                if(sum==-1){
                    sum=INF;
                }
                if(sum<min){
                key=arr[j];
                min=sum;
                }
                
            }
            temp[k]= temp[k]+min;
            i++;
            mat[k][i]=key;
        }
    }
    int min1=INF;
    int key1=0;
    for(int i=0;i<size;i++){
        if(temp[i]<min1){
            min1=temp[i];
            key1=i;
        }

    }
    if(min1==INF){
        printf("%d \n",-1);
        return;
    }
    printf("%d \n",temp[key1]);
    
}

