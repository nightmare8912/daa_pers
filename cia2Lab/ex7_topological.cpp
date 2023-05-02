#include "miniLibrary.h"

struct edge
{   
    int from, to;
    edge() {}
    edge(int from, int to) : from(from), to(to) {}
};

struct vertex
{
    int data;
    int pred;
    int minDist;
    int dTime, fTime;
    string color;
    LinkedList<edge> list;
};


class Graph
{
private:
    int count;
    vertex *v;
public:
    Graph(int count)
    {
        this->count = count;
        v = new vertex[count];
    }

    void addEdge(int from, int to)
    {
        v[from].list.insertFront(edge(from, to));
    }

    void reset(int src)
    {
        for (int i = 0; i < count; i++)
        {
            v[i].pred = -1;
            v[i].minDist = 999999;
            v[i].data = i;
            v[i].color = "WHITE";
            v[i].dTime = v[i].fTime = 0;
        }
        v[src].minDist = 0;
    }

    void dfsVisit(LinkedList<int> &list, int currVert, int &time)
    {
        time++;
        v[currVert].dTime = time;
        cout << currVert << " ";
        v[currVert].color = "GRAY";
        for (node<edge> *temp = v[currVert].list.head; temp != NULL; temp = temp->next)
        {
            if (v[temp->data.to].color == "WHITE")
            {
                v[temp->data.to].pred = currVert;
                dfsVisit(list, temp->data.to, time);
            }
        }
        time++;
        v[currVert].fTime = time;
        list.insertFront(currVert);
        v[currVert].color = "BLACK";
    }
    void dfs(int src = 0)
    {
        reset(src);
        LinkedList<int> list;
        int time = 0;
        cout << "DFS: ";
        for (int i = 0; i < count; i++)
        {
            if (v[i].color == "WHITE")
                dfsVisit(list, i, time);
        }
        cout << "\nTopological Order: ";
        for (node<int> *temp = list.head; temp != NULL; temp = temp->next)
            cout << temp->data << " ";
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(0, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.dfs();
}