#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /* code */
    vector<int> vec = {1,2,3,4,5,6,7,8};

    for(int x : vec) {
        cout << x << " ";
    }
    cout << endl;
    cout << "vec size =  " << vec.size() << endl;

    vec.push_back(9);
    vec.push_back(10);

    cout<< "new size : "<<vec.size() << endl;
    cout << "front value" << vec.front() << endl;
    cout << "last ind value : " << vec[-1] << endl;

    // q - print non duplicate number from vector
    vector<int> arr = {1,1,5,3,6,6,5};
    int ans = 0;
    for(int x : arr) {
        ans = ans^x;
    }    
    cout << "unique : "<<ans<<endl;
    return 0;
}
