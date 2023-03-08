// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int vertex;
//     string location_name;
//     Node *next;
//     Node()
//     {
//         vertex = -1;
//         location_name = "";
//         next = NULL;
//     }
//     Node(int v, string loc_name)
//     {
//         vertex = v;
//         location_name = loc_name;
//         next = NULL;
//     }
// };
// class Graph
// {
//     int no_vertices;
//     int no_edges;
//     Node **header;
//     string *indexs;

// public:
//     Graph()
//     {
//         no_vertices = 0;
//         no_edges = 0;
//         header = NULL;
//         indexs = NULL;
//     }
//     Graph(int vertices, int edges)
//     {
//         no_vertices = vertices;
//         no_edges = edges;
//         header = new Node *[vertices];

//         indexs = new string[vertices];
//         cout << "Enter the vertex names" << endl;
//         for (int i = 0; i < vertices; i++)
//         {
//             cout << "Enter the vertex name" << endl;
//             header[i] = NULL;
//             string vertex_name;
//             cin >> vertex_name;

//             indexs[i] = vertex_name;
//         }
//     }
//     void Create_Graph()
//     {
//         cout << "Enter the edges" << endl;

//         for (int i = 0; i < no_edges; i++)
//         {
//             string vertex1, vertex2;
//             cout << "Enter the first vertex of edge name " << i + 1 << endl;
//             cin >> vertex1;

//             int index1;
//             for (int j = 0; j < no_vertices; j++)
//             {
//                 if (indexs[j] == vertex1)
//                 {
//                     index1 = j;
//                     break;
//                 }
//             }
//             cout << "Enter the adjacent vertex of first vertex of edge name " << i + 1 << endl;
//             cin >> vertex2;

//             int index2;
//             for (int j = 0; j < no_vertices; j++)
//             {
//                 if (indexs[j] == vertex2)
//                 {
//                     index2 = j;
//                     break;
//                 }
//             }

//             Node *v1 = new Node(index1, vertex1);
//             Node *v2 = new Node(index2, vertex2);

//             if (header[index1] == NULL)
//             {
//                 header[index1] = v2;
//             }
//             else
//             {
//                 Node *temp = header[index1];
//                 while (temp->next != NULL)
//                 {
//                     temp = temp->next;
//                 }
//                 temp->next = v2;
//             }

//             if (header[index2] == NULL)
//             {
//                 header[index2] = v1;
//             }
//             else
//             {
//                 Node *temp = header[index2];
//                 while (temp->next != NULL)
//                 {
//                     temp = temp->next;
//                 }
//                 temp->next = v1;
//             }
//         }
//     }
//     void PrintGraph()
//     {
//         for (int i = 0; i < no_vertices; i++)
//         {
//             Node *temp = header[i];
//             cout << indexs[i] << " ---->";
//             while (temp->next != NULL)
//             {
//                 cout << temp->location_name << " ---> ";
//                 temp = temp->next;
//             }
//             cout << temp->location_name;
//             cout << endl;
//         }
//     }
//     void PerformDfs()
//     {
//         stack<Node *> s;
//         bool visited[no_vertices] = {false};

//         s.push(header[0]);
//         visited[header[0]->vertex] = true;
//         while (!s.empty())
//         {
//             Node *val = s.top();
//             s.pop();
//             cout << val->location_name << " ";
//             Node *temp = header[val->vertex];
//             while (temp != NULL)
//             {
//                 if (visited[temp->vertex] == false)
//                 {
//                     s.push(temp);
//                     visited[temp->vertex] = true;
//                 }
//                 temp = temp->next;
//             }
//         }
//         cout << endl;
//     }
//     void PerformBfs()
//     {
//         queue<Node *> q;
//         bool visited[no_vertices] = {false};
//         q.push(header[0]);
//         visited[header[0]->vertex] = true;
//         while (!q.empty())
//         {
//             Node *val = q.front();
//             q.pop();
//             cout << val->location_name << " ";
//             Node *temp = header[val->vertex];
//             while (temp != NULL)
//             {
//                 if (visited[temp->vertex] == false)
//                 {
//                     q.push(temp);
//                     visited[temp->vertex] = true;
//                 }
//                 temp = temp->next;
//             }
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     cout << "!!! Hello World" << endl;
//     int edges, vertices;
//     cout << "Enter the number of vertices that will have " << endl;
//     cin >> vertices;
//     cout << "Enter the number of edges that will have " << endl;
//     cin >> edges;

//     Graph g(vertices, edges);
//     cout << "You have to create graph structure" << endl;

//     g.Create_Graph();
//     g.PrintGraph();
//     g.PerformDfs();
//     g.PerformBfs();
// }



// #include <bits/stdc++.h>
#include<iostream>
using namespace std;
class Node
{
public:
    int vertex;
    string location_name;
    Node *next;
    Node()
    {
        vertex = -1;
        location_name = "";
        next = NULL;
    }
    Node(int v, string loc_name)
    {
        vertex = v;
        location_name = loc_name;
        next = NULL;
    }
    friend class Stack;
    friend class Queue;
};
class Stack
{
    Node *s[50];
    int top = -1;

public:
    void push(Node *t)
    {
        top++;
        s[top] = t;
    }
    void pop()
    {
        top--;
    }

    Node *Top()
    {
        return s[top];
    }
    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    friend class Node;
    friend class Graph;
};
class Queue
{
    Node *q[50];
    int front = -1;
    int rear = -1;

public:
    void push(Node *t)
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        q[rear] = t;
    }
    void pop()
    {
        front++;
    }
    Node *Front()
    {
        return q[front];
    }
    bool empty()
    {
        if ((front == (rear + 1)) || front == -1)
        {
            return true;
        }
        return false;
    }
};
class Graph
{
    int no_vertices;
    int no_edges;
    Node **header;
    string *indexs;

public:
    Graph()
    {
        no_vertices = 0;
        no_edges = 0;
        header = NULL;
        indexs = NULL;
    }
    Graph(int vertices, int edges)
    {
        no_vertices = vertices;
        no_edges = edges;
        header = new Node *[vertices];

        indexs = new string[vertices];
        cout << "Enter the vertex names" << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << "Enter the vertex name" << endl;
            header[i] = NULL;
            string vertex_name;
            cin >> vertex_name;

            indexs[i] = vertex_name;
        }
    }
    void Create_Graph()
    {
        cout << "Enter the edges" << endl;

        for (int i = 0; i < no_edges; i++)
        {
            string vertex1, vertex2;
            cout << "Enter the first vertex of edge name " << i + 1 << endl;
            cin >> vertex1;

            int index1;
            for (int j = 0; j < no_vertices; j++)
            {
                if (indexs[j] == vertex1)
                {
                    index1 = j;
                    break;
                }
            }
            cout << "Enter the adjacent vertex of first vertex of edge name " << i + 1 << endl;
            cin >> vertex2;

            int index2;
            for (int j = 0; j < no_vertices; j++)
            {
                if (indexs[j] == vertex2)
                {
                    index2 = j;
                    break;
                }
            }

            Node *v1 = new Node(index1, vertex1);
            Node *v2 = new Node(index2, vertex2);

            if (header[index1] == NULL)
            {
                header[index1] = v2;
            }
            else
            {
                Node *temp = header[index1];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = v2;
            }

            if (header[index2] == NULL)
            {
                header[index2] = v1;
            }
            else
            {
                Node *temp = header[index2];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = v1;
            }
        }
    }
    void PrintGraph()
    {
        for (int i = 0; i < no_vertices; i++)
        {
            Node *temp = header[i];
            cout << indexs[i] << " ---->";
            while (temp->next != NULL)
            {
                cout << temp->location_name << " ---> ";
                temp = temp->next;
            }
            cout << temp->location_name;
            cout << endl;
        }
    }
    void PerformDfs()
    {

        Stack s;
        bool visited[no_vertices] = {false};

        s.push(header[0]);
        visited[header[0]->vertex] = true;
        while (!s.empty())
        {
            Node *val = s.Top();
            s.pop();
            cout << val->location_name << " ";
            Node *temp = header[val->vertex];
            while (temp != NULL)
            {
                if (visited[temp->vertex] == false)
                {
                    s.push(temp);
                    visited[temp->vertex] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
    void PerformBfs()
    {

        Queue q;
        bool visited[no_vertices] = {false};
        q.push(header[0]);
        visited[header[0]->vertex] = true;
        
        while (!q.empty())
        {
            Node *val = q.Front();
            q.pop();
            cout << val->location_name << " ";
            Node *temp = header[val->vertex];
            while (temp != NULL)
            {
                if (visited[temp->vertex] == false)
                {
                    q.push(temp);
                    visited[temp->vertex] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    // cout << "!!! Hello World" << endl;
    int edges, vertices;
    cout << "Enter the number of vertices that will have " << endl;
    cin >> vertices;
    cout << "Enter the number of edges that will have " << endl;
    cin >> edges;

    Graph g(vertices, edges);
    cout << "You have to create graph structure" << endl;

    g.Create_Graph();
    g.PrintGraph();
    g.PerformDfs();
    g.PerformBfs();
}