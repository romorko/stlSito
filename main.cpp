#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::cout;

int main()
{
    vector<int> cisla(50);
    int k=1;
    generate_n(cisla.begin(),50,[&k](){return ++k;});
    copy(cisla.begin(), cisla.end(), std::ostream_iterator<int>(cout, " "));
    cout<<std::endl;
    auto pos = cisla.begin();
    auto nenulovy=pos;
    while (nenulovy=std::find_if(pos, cisla.end(), [](auto i) { return i != 0; }),nenulovy!=cisla.end())
    {
        std::replace_if(nenulovy + 1, cisla.end(), [nenulovy](auto i) { return i % (*nenulovy) == 0; }, 0);
        pos = nenulovy + 1;
    }
    std::copy_if(cisla.begin(), cisla.end(), std::ostream_iterator<int>(cout, " "),[](auto i){return i!=0;});
    return 0;
}
