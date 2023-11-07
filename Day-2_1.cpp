#include <iostream>
#include <vector>

using namespace std;

class NStacks {
private:
    int numStacks; 
    int size;       
    vector<int> top; 
    vector<int> data; 

public:
    NStacks(int n, int s) : numStacks(n), size(s) {
        top.resize(numStacks, -1);
        data.resize(size, 0);
    }

    bool push(int x, int m) {
        if (m < 1 || m > numStacks) {
            return false;
        }

        int index = (m - 1) * (size / numStacks) + top[m - 1] + 1;

        if (index >= m * (size / numStacks)) {
            return false;
        }

        data[index] = x;
        top[m - 1] = index;
        return true;
    }

    int pop(int m) {
        if (m < 1 || m > numStacks || top[m - 1] == -1) {
            return -1;
        }

        int index = top[m - 1];
        int value = data[index];
        top[m - 1]--;
        return value;
    }
};

int main() {
    int N, S, Q;
    cin >> N >> S >> Q;

    NStacks nStacks(N, S);

    for (int i = 0; i < Q; ++i) {
        int query;
        cin >> query;

        if (query == 1) {
           
            int X, M;
            cin >> X >> M;
            bool result = nStacks.push(X, M);
            cout << (result ? "True" : "False") << endl;
        } else if (query == 2) {
            int M;
            cin >> M;
            int result = nStacks.pop(M);
            cout << result << endl;
        }
    }
    return 0;
}
