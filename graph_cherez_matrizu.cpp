#include<iostream>
#include<vector>

using Vertex = size_t;

class IGraph{
public:
    virtual ~IGraph(){} //destructor
    virtual void AddEdge(Vertex from, Vertex to) = 0; //dobavit' vershinu
    virtual size_t size() const = 0; //chislo vershin v graphe
    virtual const std::vector<Vertex> GetAdj (Vertex v) const = 0; //vernet smezhnye vershyny
};

class OrientalMatrixGraph: public IGraph{

using OMG = OrientalMatrixGraph;

private:
        std::vector<std::vector<Vertex>> graph;
public:
        OMG(size_t vertexCount): graph(vertexCount, std::vector<Vertex>(vertexCount, 0)){} //конструируем граф от числа вершин

        size_t Size() const override{return graph.size()};

        void AddEdge(Vertex from, Vertex to) override{
            graph.at(from).at(to) = 1;
            graph.at(to).at(from) = -1;
        }

        const std::vector<Vertex>& GetAdj(Vertex v) const override{
            std::vector<Vertex> sv;
            for (Vertex i = 0; i < graph.size(); ++i){
                if (graph.at(v).at(i) == -1) sv.push_back(i);
            }
            return sv;
        }
};
