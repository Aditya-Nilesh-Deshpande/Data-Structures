#include <iostream>
using namespace std;

class Stack{
    Stack *top;
    int data;
    Stack* next;

    public:
        Stack(){
            data=0;
            top=NULL;
        }
        Stack(int x){
            data=x;
            next=NULL;
        }
        void push(int x){
            Stack * newnode=new Stack(x);

            //Insert at beg
            if(top==NULL){
                top=newnode;
            }
            else{
                newnode->next=top;
                top=newnode;
            }
        }
        int pop(){
            if(!empty()){
                Stack* temp =top;
                int value=top->data;

                top=top->next;
                temp->next=NULL;
                delete temp;
                return value;
            }
        }
        bool empty(){
            if(top==NULL){
                return true;
            }
            return false;
        }
};

class Queue{

    int data;
    Queue* front;
    Queue* rear;
    Queue* next;

    public:
        Queue(){
            data=0;
            front=rear=NULL;
        }
        Queue(int x){
            data=x;
            next=NULL;
            front=rear=NULL;
        }
        void enqueue(int x){
            Queue* newnode=new Queue(x);

            //Insertion from rear
            if(front==NULL){
                front=rear=newnode;
            }
            else{
                rear->next=newnode;
                rear=newnode;
            }
        }

        int dequeue(){

            if(!empty()){
                Queue* temp=front;
                front=front->next;

                int value=temp->data;

                temp->next=NULL;
                delete temp;
                return value;
            }
        }
        bool empty(){
            if(front==NULL){
                return true;
            }
            return false;
        }
        
};

class Node{
    int vertex;
    Node* next;

    public:
        Node(){
            vertex=0;
            next=NULL;
        }
        Node(int x){
            vertex=x;
            next=NULL;
        }
        friend class Graph;
};

class Graph{

    int vertices;
    int edges;
    Node** header;

    public:
        Graph(){
            vertices=edges=0;
            header=NULL;
        }
        Graph(int v,int e){
            vertices=v;
            edges=e;

            header=new Node*[v];
            for(int i=1;i<=v;i++){
                header[i]=NULL;
            }
        }

        bool acceptGraph();
        void insert(int,int,char);
        void displayAdjacencyList();
        void BFS_Traversal(int);
        void DFS_Traversal(int);

};

bool Graph::acceptGraph(){
    
    bool flag=false;
    int source;
    int destination;

    char ans;
    cout<<"\nIs the graph Directed or Undirected?(D/U): ";
    cin>>ans;

    for(int i=1;i<=edges;i++){
        cout<<"\nEnter the source and destination of your edge: ";
        cin>>source>>destination;

        if(source>vertices || destination>vertices){
            cout<<"\nCannot insert as input exceeds the total number of vertices!!!";
            return false;
        }
        else{
            insert(source,destination,ans);
            if(i==edges){
                return true;
            }
        }

    }
}

void Graph::insert(int source,int destination,char ans){

    Node* temp;
    Node* newnode;

    newnode=new Node(destination);
    temp=header[source];

    //First entry
    if(temp==NULL){
        header[source]=newnode;
    }

    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }

    if(ans=='D' || ans=='d'){
        return;
    }
    else{
        //Creating Link from destination to source
        Node *p;
        p=new Node(source);
        temp=header[destination];

        //First entry
        if(temp==NULL){
            header[destination]=p;
        }

        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        } 
    }

}

void Graph::displayAdjacencyList(){

    Node* ptr;
    for(int i=1;i<=vertices;i++){
        ptr=header[i];

        cout<<i<<" : ";
        while(ptr!=NULL){
            cout<<ptr->vertex<<" ";
            ptr=ptr->next;
        }
        cout<<"\n";
    }
}

void Graph::BFS_Traversal(int start){

    Node* temp;
    Queue q;

    bool visited[vertices];  //making visited array
    for(int i=1;i<=vertices;i++){
        visited[i]=false;
    }

    q.enqueue(start);
    visited[start]=true;
    
    int v;
    while(!q.empty()){
        v=q.dequeue();

        // if(visited[v]==false){
        //     cout<<v<<" ";
        //     visited[v]=true;
        // }
        cout<<v<<" ";

        temp=header[v];
        while(temp!=NULL){
            if(visited[temp->vertex]==false){
                q.enqueue(temp->vertex);
                visited[temp->vertex]=true;
            }
            temp=temp->next;
        }   
    }
}

void Graph::DFS_Traversal(int start){

    bool visited[vertices];  //making visited array
    for(int i=1;i<=vertices;i++){
        visited[i]=false;
    }

    Node* temp;
    Stack s;
    s.push(start);
    visited[start]=true;

    int v;
    
    while(!s.empty()){
        v=s.pop();

        cout<<v<<" ";
         
        temp=header[v];
        while(temp!=NULL){
            if(visited[temp->vertex]==false){
                s.push(temp->vertex);
                visited[temp->vertex]=true;
            }
            temp=temp->next;
        }

    }
}
int main(){

    int v,e;
    cout<<"Enter The Number of Vertices and Edges You want in the Graph: ";
    cin>>v>>e;

    bool get;
    int start;
    Graph g(v,e);
    int ch;

    do
    {
        cout << "\n---------------------------------------------------------";
        cout << "\n0.Exit" << endl;
        cout << "1.Create a Graph - " << endl;
        cout << "2.Display Adjacency List - " << endl;
        cout << "3.BFS Traversal " << endl;
        cout << "4.DFS Traversal " << endl;
        cout << "---------------------------------------------------------\n";

        cout << "\nEnter choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            get=g.acceptGraph();
            if(!get){
             cout<<"Exited Abrubtly!!!";
            }
            break;
        case 2:
            g.displayAdjacencyList();
            break;
        case 3:
            cout<<"\nEnter the starting vertex for BFS Traversal ";
            cin>>start;

            g.BFS_Traversal(start);
            
            break;

        case 4:

           cout<<"\nEnter the starting vertex for DFS Traversal ";
           cin>>start;
           g.DFS_Traversal(start);
           cout<<"\n";
           break;

        default:
            break;
        }

    } while (ch != 0);

    return 0;
}