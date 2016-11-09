#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <time.h>
#include <numeric>
#include <algorithm>
#include <assert.h>



using namespace std;

class agent
{
public:
    vector<double> archivex;
    vector<double> archivey;
    vector<double> evaluationx;
    vector<double> evaluationy;
    vector<double> noveltyofx;
    vector<double> noveltyofy;
    vector<double> noveltyvector;
    double novelty;

    agent();
    void clean();
    void initialize();
    void create();
    void evaluate();

};

//Variables

    int l = 10;
    int valx;
    int valy;
    int evalx;
    int evaly;
    int evaltotal;
    double evalxtotal = 0;
    double evalytotal = 0;
    double sumx = 0;
    double sumy = 0;


agent::agent()
{
    novelty = 0.0;
}

void agent::clean()
{
    valx = 0, valy = 0, evalx = 0, evaly = 0, evaltotal = 0, sumx = 0, sumy = 0;
    fill(noveltyvector.begin(), noveltyvector.end(), 0);
    fill(archivex.begin(), archivex.end(), 0);
    fill(archivey.begin(), archivey.end(), 0);
    fill(noveltyofx.begin(), noveltyofx.end(), 0);
    fill(noveltyofy.begin(), noveltyofy.end(), 0);
    fill(evaluationx.begin(), evaluationx.end(), 0);
    fill(evaluationy.begin(), evaluationy.end(), 0);
    cout << "Agent Variables Clean: " << endl;
    cout << " " << endl;
}

void agent::initialize()
{
    archivex.clear();
    archivey.clear();
    for (int j = 0; j <= l; j++)
    {
        valx = (rand() % 10 + 1);
        archivex.push_back(valx);

        valy = (rand() % 10 + 1);
        archivey.push_back(valy);
    }
    cout << "X and Y vectors created:" << endl;
}

void agent::create()
{

}

void agent::evaluate()
{
    int k = 10;

    for (int i = 0; i <= k; ++i)
    {

    evalx = abs(archivex.at(i)- archivex.at(k-i));
    evalxtotal = evalxtotal + evalx;

    evaly = abs(archivey.at(i) - archivey.at(k-i));
    evalytotal = evalytotal + evaly;

        noveltyofx.push_back(evalxtotal);
        noveltyofy.push_back(evalytotal);

    }

        sumx = accumulate(noveltyofx.begin(), noveltyofx.end(), 0.0);
        sumy = accumulate(noveltyofy.begin(), noveltyofy.end(), 0.0);
        novelty = sumx+sumy;

        noveltyvector.push_back(novelty);


    cout << "Novelty Vector: " << endl;
        for (vector<double>::const_iterator i = noveltyvector.begin(); i != noveltyvector.end(); ++i)
        {
            std::cout << *i << ' ';
        }


    cout << " " << endl;
    cout << "Novelty: "<< novelty << endl;

}

int main()
{
    srand(time(NULL));

    cout << "Program Initialization:" << endl;
    cout << " " << endl;


vector<agent>agents(3);
for (unsigned int m = 0; m< agents.size(); m++)
{
    agents[m].clean();
   for (int i = 0; i <= 10; i++)
    {
    agents[m].initialize();
    agents[m].create();
    agents[m].evaluate();
    evalytotal = 0;
    evalxtotal = 0;
    sumx = 0;
    sumy = 0;
    cout << agents[0].novelty << " ?? " << agents[1].novelty << endl;
    assert(agents[0].novelty != agents[1].novelty);

    cout << " End of Run: " << i << endl;
    cout << " " << endl;
    }
}
    cout << " " << endl;
    cout << "Done"<< endl;

    return 0;
}
