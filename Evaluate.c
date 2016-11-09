void agent::evaluate()
{

    for (int i = 0; i <= k; i++)
    {

    evalx = abs(x.at(i)- x.at(k-i));
    evalxtotal = evalxtotal + evalx;

    evalx = abs(y.at(i) - y.at (k-i));
    evalytotal = evalytotal + evaly;

    }
        evolutionx.push_back(evalxtotal);
        evolutiony.push_back(evalytotal);

        sumx = accumulate(evolutionx.begin(), evolutionx.end(), 0);
        sumy = accumulate(evolutiony.begin(), evolutiony.end(), 0);
        novelty = sumx + sumy;

cout << "Evaluation of Novelty:" << endl;

for (int i = 0; i <=k; i++)
{
    cout << "Novelty: "<< evaluationx.at(i) << endl;
}

}

