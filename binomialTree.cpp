#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    double price;
    double time;
    double optionvalue;
};

class BinomialTree {
    public:
        BinomialTree(double Spot, double Vol, int n, double tstep);
        double getPrice(double Strike, double r);
        void print();
    
    private:
        Node **tree;
        int n;
        double Spot, Vol, upfactor, tfin, tstep;
        double getPrice(int level, int node, double Strike, double r);
        void initNode(int level, int node);
};

BinomialTree::BinomialTree(double price, double _Vol, int _n, double _tstep)
: Spot(price), Vol(_Vol), n(_n), tstep(_tstep) 
{
    tfin = n * tstep;
    upfactor = exp(Vol * sqrt(tstep));
    
    tree = new Node* [n];

    for (int i=0; i < n; i++) {
        tree[i] = new Node[i+1];
    }

    tree[0][0].price = Spot;
    tree[0][0].time = 0.0;
    double currTime = 0.0;

    for (int i=1; i < n; i++) {
        Node* currNode = tree[i];
        currTime += tstep;

        for(int j=0; j <= i; j++, currNode++) {
            if (!j) {
                currNode->price = tree[i-1][j].price / upfactor;
                currNode->time = currTime;
            } else {
                currNode->price = tree[i-1][j-1].price * upfactor;
                currNode->time = currTime;
            }
        }
    }
}

double BinomialTree::getPrice(int l, int node, double Strike, double df)
{
    if (l == (n-1))
    {
        if (Strike < tree[l][node].price) {
            return tree[l][node].optionvalue = tree[l][node].price - Strike;
        } else {
            return tree[l][node].optionvalue = 0.0;
            }

    } else {
      double g1 = getPrice(l + 1, node + 1, Strike, df);
      double g2 = getPrice(l + 1, node, Strike, df);
      return tree[l][node].optionvalue = 0.5 * df * (g1 + g2);
   }
}

double BinomialTree::getPrice(double Strike, double r) 
{
    double discountfactor = exp (-r * tstep);
    return getPrice(0, 0, Strike, discountfactor);
}

void BinomialTree::print()
{
    for (int i = 0; i < n; i++) {
        for( int j = 0; j <= i; j++ )
        {
            cout<< "[" << tree[i][j].price << "," << tree[i][j].time << ",";
            cout<< tree[i][j].optionvalue << "]\t";
        }
        cout <<endl;
   }
}

int main()
{
    double S, V, K, T, R, N;
    cout<<"Enter Spot Price: ";
    cin>>S;

    cout<<"Enter Volatility: ";
    cin>>V;

    cout<<"Enter Call Strike Price: ";
    cin>>K;

    cout<<"Enter Time To Expiry: ";
    cin>>T;

    cout<<"Enter Risk Free Rate: ";
    cin>>R;

    cout<<"Enter levels: ";
    cin>>N;

    BinomialTree bt(S, V, N, T / N);
    double value = bt.getPrice(K, R);
    bt.print();

    cout<< "OPTION VALUE = " << value <<endl;

    return 0;
}
