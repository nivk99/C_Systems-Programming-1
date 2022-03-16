
#include "my_graph.h"
int main(int argc, char *argv[]) 
{

char c =0;
Graph graph;
graph.size_Node=0;
if(scanf(" %c", &c)==EOF){
      return 0;
}
while(c=='A'||c=='B'||c=='D'||c=='S'||c=='T')
{

      if (c=='A')
      {
            Free_Graph(&graph);//free graph
             if(scanf(" %c", &c)==EOF){//scanf size nodes
             Free_Graph(&graph);
            return 0;
             }
            if(!(c>='0'&&'9'>=c)){
                  continue;
            }
            int size=c-0x30;
            NewList(size,&graph);
            if(scanf(" %c", &c)==EOF){//scanf n
            Free_Graph(&graph);
            return 0;
             }
            while (c=='n')
            {
                   if(scanf(" %c", &c)==EOF){//scanf key
                   Free_Graph(&graph);
                  return 0;
                   }
                  if(!(c>='0'&&'9'>=c)){
                  continue;
                  }
                  int key=c-0x30;
                   if(scanf(" %c", &c)==EOF){
                         Free_Graph(&graph);
                         return 0;
                  }
                  if(!(c>='0'&&'9'>=c)){
                  continue;
                  }
                  while (c>='0'&&'9'>=c)
                  {
                        int dest=c-0x30;
                         if(scanf(" %c", &c)==EOF){
                               Free_Graph(&graph);
                              return 0;
                         }
                          if(!(c>='0'&&'9'>=c)){
                          continue;
                           }
                        int wi =c-0x30;
                        AddEdge(key,dest,wi,&graph);
                         if(scanf(" %c", &c)==EOF){
                               Free_Graph(&graph);
                               return 0;
                         }
                  }
            

            }
            
            continue;
                    
      }
      ///////////////////////////
      if (c=='B')
      {
            if(scanf(" %c", &c)==EOF){
                  Free_Graph(&graph);
                  return 0;
            }
            int key=c-0x30;
            if(!(c>='0'&&'9'>=c)){
                  continue;
            }
            AddNode(&graph,key);
            if(scanf(" %c", &c)==EOF){
                  Free_Graph(&graph);
                  return 0;
            }
            while (c>='0'&&'9'>=c)
            {
                  int dest=c-0x30;
                  if(scanf(" %c", &c)==EOF){
                        Free_Graph(&graph);
                         return 0;
                  }
                  if(!(c>='0'&&'9'>=c)){
                  continue;
                  }
                  int wi =c-0x30;
                  AddEdge(key,dest,wi,&graph);
                  if(scanf(" %c", &c)==EOF){
                        Free_Graph(&graph);
                        return 0;
                  }
            }
            continue;
            
      }
      /////////////////////////////////
      if (c=='D')
      {
            if(scanf(" %c", &c)==EOF){
                  Free_Graph(&graph);
                  return 0;
            }
            if(!(c>='0'&&'9'>=c)){
             continue;
            }
            int key=c-0x30;
            DeleteNode(&graph,key);
            if(scanf(" %c", &c)==EOF){
                  Free_Graph(&graph);
                  return 0;
            }
            continue;
            
      }
      ////////////////////////////////////
      if (c=='S')
      {

            if(scanf(" %c", &c)==EOF){
                  Free_Graph(&graph);
                  return 0;
            }
            if(!(c>='0'&&'9'>=c)){
                  continue;
             }
            while (c>='0'&&'9'>=c)
            {
                  int src=c-0x30;
                  if(scanf(" %c", &c)==EOF){
                        Free_Graph(&graph);
                          return 0;
                   }
                  if(!(c>='0'&&'9'>=c)){
                  continue;
                  }
                  int dest =c-0x30;
                  printf("Dijsktra shortest path: %d \n",ShortPath(&graph,src,dest));
                   if(scanf(" %c", &c)==EOF){
                         Free_Graph(&graph);
                         return 0;
                  }

            }
            continue;
            
            
      }
      //////////////////////////////////////////
      if (c=='T')
      {

            int bo=1;
           if(scanf(" %c", &c)==EOF){
                 Free_Graph(&graph);
                  return 0;
            }
            while (c>='0'&&'9'>=c)
            {
                  int size=c-0x30;
                  int arr[size];
                  for (int i = 0; i <size; i++)
                  {
                        if(scanf(" %c", &c)==EOF){
                              Free_Graph(&graph);
                              return 0;
                        }
                        if(!(c>='0'&&'9'>=c)){
                        bo=0;
                        break;
                         }
                        arr[i]=c-0x30;

                  }
                  if(bo){
                  TCP(&graph,arr,size);  
                  } 
                  if(scanf(" %c", &c)==EOF){
                        Free_Graph(&graph);
                        return 0;
                  }

            }
            continue;
            
          
      }
}    
Free_Graph(&graph);
return 0;
}

////the prinf Graph///////////////////////////////////
void print(PGraph g){
      PNodeData p= g->List_Node;
      while (p)
      {
            printf("key:%d ",p->Key);
            if(p->List_outDegree){
                  PEdgeData e=p->List_outDegree;
                  while (e)
                  {
                        printf("dest:%d",e->Dest);
                        printf(" Weight:%d ",e->Weight);
                         printf(" ");
                        e=e->Next_Edge;
                  }
                  
            }

          printf("\n");

            p=p->Next_Node;
      }
      

}
