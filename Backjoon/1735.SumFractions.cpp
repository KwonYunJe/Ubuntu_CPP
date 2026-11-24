#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int as, am, bs, bm;
    int s, m;

    cin >> as >> am;
    cin >> bs >> bm;

    s = as*bm + bs*am;
    m = am * bm;

    as = min(s,m);
    am = max(s,m);

    while(as != 0){
        bs = am % as;
        am = as;
        as = bs;
    }

    cout << s/am << ' ' << m/am ;
    

    return 0;
}
