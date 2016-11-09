void agent::create()
{
    for (int z = 0; z <= k; z++)
    {
    x.push_back(z);
    cout << x.at(z) << endl;
    }

    cout << "X vector Printed:" << endl;

    for (int n = 0; n <= k; n++){

    y.push_back(n);
    cout << y.at(n) << endl;
    }

    cout << "Y vector Printed:" << endl;
}
