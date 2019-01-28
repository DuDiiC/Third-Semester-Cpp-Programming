#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int beveragesNumber;
    int testNumber = 1;

    while(cin >> beveragesNumber) {

        /// load data into the map
        map < int, string > beverages;
        for(int i = 0; i < beveragesNumber; i++) {
            cin >> beverages[i];
        }

        /// create graph
        vector < vector < int > > graph;
        for(int i = 0; i < beveragesNumber; i++) {
            vector < int > temp;
            graph.push_back(temp);
        }

        int pairNumber;
        cin >> pairNumber;
        for(int i = 0; i < pairNumber; i++) {
            string bev1, bev2;
            cin >> bev1 >> bev2;

            /// graph as a adjacency list - for each vertex list of incoming (?) vertexes
            for(int j = 0; j < beveragesNumber; j++) {
                if(beverages[j] == bev2) {
                    for(int k = 0; k < beveragesNumber; k++) {
                        if(beverages[k] == bev1) {
                            /// don't add the same twice
                            bool absent = true;
                            for(int m = 0; m < graph[j].size(); m++) {
                                if(graph[j][m] == k) {
                                    absent = false;
                                    break;
                                }
                            }
                            if(absent) graph[j].push_back(k);
                            break;
                        }
                    }
                    break;
                }
            }
        }

        cout << "Case #" << testNumber++ << ": Dilbert should drink beverages in this order:";

        /// TOPOLOGICAL SORT OF GRAPH - IMPLEMENTATION WITH QUEUE
        queue < int > zeroDegree;
        bool visited[beveragesNumber];
        bool inQueue[beveragesNumber];
        for(int i = 0; i < beveragesNumber; i++) {
            visited[i] = false;
            inQueue[i] = false;
        }

        /// add first zero degree vertex
        for(int i = 0; i < graph.size(); i++) {
            if(!graph[i].size()) {
                zeroDegree.push(i);
                inQueue[i] = true;
                break;
            }
        }

        /// start sorting
        while(!zeroDegree.empty()) {
            /// first zero degree vertex
            int actualVertex = zeroDegree.front();
            visited[actualVertex] = true;
            /// write it to the output
            cout << " " << beverages[actualVertex];
            /// delete all edges with this vertex
            for(int i = 0; i < graph.size(); i++) {
                if(i != actualVertex) {
                    for(int j = 0; j < graph[i].size(); j++) {
                        if(graph[i][j] == actualVertex) {
                            vector < int >::iterator it = graph[i].begin()+j;
                            graph[i].erase(it);
                            break;
                        }
                    }
                }
            }
            /// delete this vertex from queue
            zeroDegree.pop();
            /// after operations add new zero degree vertex into the queue
            for(int i = 0; i < graph.size(); i++) {
                if((visited[i] == false) && (inQueue[i] == false) && (graph[i].size() == 0)) {
                    zeroDegree.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
        }

        cout << "." << endl;


    }

    return 0;
}

