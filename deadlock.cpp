
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int prs,rsc;
    cout << "Enter total number of Process: ";
    cin >> prs;
    cout << "Enter total number of Resources: ";
    cin >> rsc;
    int remNeed[prs+5][rsc+5],avail[rsc+5],totalRsc[rsc+5],prsAlloc[prs+5][rsc+5],visited[prs+5]={0};
    char c = 'A';
    for(int i=1; i<=rsc; i++)
    {
        cout << "Number of " << c++ << " resources has: ";
        cin >> totalRsc[i];
        avail[i] = totalRsc[i];
    }
    for(int i=1; i<=prs; i++)
    {
        char ch = 'A';
        for(int j=1; j<=rsc; j++)
        {
            int alloc,mxneed;
            cout << "Number of "<< ch++ << " resources allocation && max need allocation for process " << i << ": ";
            cin >> alloc >> mxneed;
            prsAlloc[i][j] = alloc;
            remNeed[i][j] = mxneed-alloc;
            avail[j] -= alloc;
        }
    }
    cout << "\n\n";
    cout << "Available Resources\n";
    c = 'A';
    for(int i=1; i<=rsc; i++)
    {
        cout << c++ << "->" << avail[i] << "\n";
    }
    cout << "\n\n";
    cout << "Process Allocation in present situation\n";
    for(int i=1; i<=prs; i++)
    {
        char ch = 'A';
        cout << "For Process " << i << "\n";
        for(int j=1; j<=rsc; j++)
        {
            cout << ch++ << "->" << prsAlloc[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n";
    cout << "Remaining Need\n";
    for(int i=1; i<=prs; i++)
    {
        char ch = 'A';
        cout << "For Process " << i << "\n";
        for(int j=1; j<=rsc; j++)
        {
            cout << ch++ << "->" << remNeed[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n";
    cout << "Checking Deadlock...\n";
    vector<int>safeSeq;
    int f=1;
    while(f)
    {
        f = 0;
        for(int i=1; i<=prs; i++)
        {
            if(visited[i]) continue;
            int flag=1;
            for(int j=1; j<=rsc; j++)
            {
                if(remNeed[i][j]>avail[j]) flag=0;
            }
            if(flag)
            {
                f = 1;
                safeSeq.push_back(i);
                visited[i] = 1;
                for(int j=1; j<=rsc; j++){
                    avail[j] += prsAlloc[i][j];
                }
            }
        }
    }
    if(safeSeq.size()==prs){
        cout << "Wow!!! There is no deadlock in your system. Your Safe Sequence is: ";
        for(auto &it:safeSeq) cout << it << " ";
    }
    else{
        cout << "Alas... Deadlock detected :(";
    }




}
