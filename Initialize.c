void agent::initialize()
{

    for (int j = 0; j <= l; j++)
    {
        valx = (rand() % 100 + 1);
        x.push_back(valx);

        valy = (rand() % 100 + 1);
        y.push_back(valy);
    }
    cout << "X and Y vectors created:" << endl;
}
