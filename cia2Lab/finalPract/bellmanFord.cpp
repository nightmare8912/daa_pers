#include "minLib.h"
#define INT_MAX 999999
struct edge
{
    int from, to, weight;
    edge() {}
    edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

struct vertex
{
    int data, pred, minDist;
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

    void addEdge(int from, int to, int weight)
    {
        v[from].list.insertFront(edge(from, to, weight));
    }

    void initializeSingleSource(int src)
    {
        for (int i = 0; i < count; i++)
        {
            v[i].data = i;
            v[i].pred = -1;
            v[i].minDist = INT_MAX;
        }
        v[src].minDist = 0;
    }

    bool relax(int from, int to, int weight)
    {
        if (v[to].minDist > v[from].minDist + weight)
        {
            v[to].minDist = v[from].minDist + weight;
            v[to].pred = from;
            return true;
        }
        return false;
    }

    void printLines(int n = 49)
    {
        for (int i = 0; i < n; i++)
            cout << "-";
    }

    void printRes() 
    {
        cout << endl;
        printLines();
        cout << "\n|\tDATA\t|\tPRED\t|\tMINDIST\t|\n";
        for (int i = 0; i < count; i++)
        {
            cout << "|\t" <<v[i].data << "\t|\t" << v[i].pred << "\t|\t";
            if (v[i].minDist == INT_MAX)
                cout << "INF";
            else
                cout << v[i].minDist;
            cout << "\t|" << endl;
        }
           
        printLines();
    }

    bool bellmanFord(int src = 0)
    {
        initializeSingleSource(src);
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count; j++)
            {
                for (node<edge> *temp = v[j].list.head; temp != NULL; temp = temp->next)
                    relax(j, temp->data.to, temp->data.weight);
            }
        }

        for (int j = 0; j < count; j++)
        {
            for (node<edge> *temp = v[j].list.head; temp != NULL; temp = temp->next)
                if (relax(j, temp->data.to, temp->data.weight))
                    return false;
        }
        return true;
    }
};

int main()
{
    Graph g(8);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);
    if (g.bellmanFord())
        g.printRes();
    else
        cout << "A negative weight cycle exists!";
}