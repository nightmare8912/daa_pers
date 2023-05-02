#include "minLib.h"

struct edge
{
    int from, to;
    edge() {}
    edge(int from, int to) : from(from), to(to) {}
};

struct vertex
{
    int data, pred, dTime, fTime;
    string color;
    LinkedList<edge> list;
};

class Graph
{
private:
    vertex *v;
    int count;

public:
    Graph(int count)
    {
        this->count = count;
        v = new vertex[count];
    }

    void addEdge(int from, int to)
    {
        v[from].list.insertFront(edge(from ,to));
    }

    void initialize()
    {
        for (int i = 0; i < count; i++)
        {
            v[i].data = i;
            v[i].pred = -1;
            v[i].color = "WHITE";
            v[i].dTime = v[i].fTime = 0;
        }
    }

    void dfsVisit(LinkedList<int> &list, int currVert, int &time)
    {   
        v[currVert].color = "GRAY";
        time += 1;
        v[currVert].dTime = time;
        cout << currVert << " ";
        for (node<edge> *temp = v[currVert].list.head; temp != NULL; temp = temp->next)
        {
            if (v[temp->data.to].color == "WHITE")
            {
                v[temp->data.to].pred = currVert;
                dfsVisit(list, temp->data.to, time);
            }
                
        }
        time += 1;
        v[currVert].color = "BLACK";
        list.insertFront(currVert);
        v[currVert].fTime = time;
    }

    void dfs(LinkedList<int> &list)
    {
        initialize();
        int time = 0;
        for (int i = 0; i < count; i++)
        {
            if (v[i].color == "WHITE")
                dfsVisit(list, i, time);
        }
    }

    void printLines(int n = 65)
    {
        for (int i = 0; i < n; i++)
            cout << "-";
    }

    void printRes() 
    {
        cout << endl;
        printLines();
        cout << "\n|\tDATA\t|\tDTIME\t|\tFTIME\t|\tPRED\t|\n";
        for (int i = 0; i < count; i++)
            cout << "|\t" <<v[i].data << "\t|\t" << v[i].dTime << "\t|\t" << v[i].fTime << "\t|\t" << v[i].pred << "\t|" << endl;
        printLines();
    }
    void topological()
    {
        LinkedList<int> list;
        dfs(list);
        cout << "\nTopological: ";
        for (node<int> *temp = list.head; temp != NULL; temp = temp->next)
            cout << temp->data << " ";
        printRes();
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
    g.topological();
}