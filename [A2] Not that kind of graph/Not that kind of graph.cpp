#include<iostream>
#include<string>
using namespace std;

int main() {
    int cases, lineSize, graphHeight, minHeight = 51, maxHeight = 51;
    char graph[102][52];
    string line;

    cin>>cases;
    for(int c = 1; c <= cases; c++) {

        cin>>line;
        lineSize = line.size();

        for(int i = 0; i < 102; i++) {
            for(int j = 0; j < 52; j++) {
                graph[i][j] = NULL;
            }
        }
        minHeight = 51,
        maxHeight = 51;

        graphHeight = 51;
        if(line[0] == 'R') {

            graph[graphHeight][0] = '/';

        } else if(line[0] == 'F') {

            graph[graphHeight][0] = '\\';

        } else if(line[0] == 'C') {

            graph[graphHeight][0] = '_';
        }

        for(int i = 1; i < lineSize; i++) {
            if(line[i-1] == 'R') {
                if(line[i] == 'C') {

                    graphHeight--;
                    graph[graphHeight][i] = '_';

                } else if(line[i] == 'R') {

                    graphHeight--;
                    graph[graphHeight][i] = '/';

                } else {
                    graph[graphHeight][i] = '\\';
                }
            } else if(line[i-1] == 'C') {
                if(line[i] == 'F') {

                    graphHeight++;
                    graph[graphHeight][i] = '\\';

                } else if(line[i] == 'C') {

                    graph[graphHeight][i] = '_';

                } else if(line[i] == 'R') {

                    graph[graphHeight][i] = '/';
                }
            } else {
                if(line[i] == 'F') {

                    graphHeight++;
                    graph[graphHeight][i] = '\\';

                } else if(line[i] == 'C') {

                    graph[graphHeight][i] = '_';

                } else if(line[i] == 'R') {

                    graph[graphHeight][i] = '/';
                }
            }

            if(graphHeight > minHeight) minHeight = graphHeight;

            else if(graphHeight < maxHeight) maxHeight = graphHeight;

        }

        for(int i = maxHeight ; i <= minHeight; i++) {

            bool singleChar = false;
            int j=52;
            while(singleChar) {
                if(graph[i][j] == '/' || graph[i][j] == '_' || graph[i][j] == '\\') {

                    graph[i][j+1] = '\n';
                    singleChar = true;
                }
                j--;
            }
            for(j; j >= 0; j--) {
                if(!(graph[i][j] == '/' || graph[i][j] == '_' || graph[i][j] == '\\')) {

                    graph[i][j] = ' ';
                }
            }
        }
        cout << "Case #" << c << ":" << endl;

        for(int i = maxHeight ; i <= minHeight; i++) {

            cout << "| ";
            int j;

            for(j = 0; j < lineSize; j++) {
                cout << graph[i][j];
                if(graph[i][j] == '\n')
                    break;
            }

            if(j == lineSize)
                cout << endl;
        }

        cout << "+-";
        for(int i = 0; i <= lineSize; i++) {
            cout << "-";
        }
        cout << endl;
    }

    return 0;
}
