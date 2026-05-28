#include <vector>
#include <iostream> 

using namespace std;

// brute force
void reverse(vector<int> &spanCt) {
    int i = 0, j = spanCt.size()-1;
    while(i <= j) {
        swap(spanCt[i], spanCt[j]);
        i++; 
        j--;
    }
}

vector<int> span(vector<int> &price) {
    vector<int> spanCt;

    for(int i = price.size()-1; i >= 0; i--) {
        int spanCount = 1;
        for(int j = i-1; j >= 0; j--) {
            if(price[i] > price[j]) spanCount++;
            else break;
        }
        spanCt.push_back(spanCount);
    }

    reverse(spanCt);

    return spanCt;
} 

int main() {
    vector<int> price = {100,80,60, 70,60,75,85};
    price = span(price);

    for(int i : price) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}