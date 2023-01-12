#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define dg(x) cout << #x << " = " << x << endl

class MyLinkedList
{
public:
    int valx;
    MyLinkedList *next;

    MyLinkedList()
    {
        valx = -1;
        next = NULL;
    }

    int get(int index)
    {
        int cnt = 0;
        MyLinkedList *nextx = this;
        while (nextx->next != NULL)
        {
            if (cnt == index)
                break;
            nextx = nextx->next;
            cnt++;
        }
        if (cnt < index)
            return -1;
        return nextx->valx;
    }

    void addAtHead(int val)
    {
        if (valx == -1)
            valx = val;
        else
        {
            MyLinkedList *temp = new MyLinkedList();
            temp->valx = this->valx;
            temp->next = this->next;
            this->valx = val;
            this->next = temp;
        }
    }

    void addAtTail(int val)
    {
        if (valx == -1)
            valx = val;
        else
        {
            MyLinkedList *nextx = this;
            while (nextx->next != NULL)
                nextx = nextx->next;
            MyLinkedList *temp = new MyLinkedList();
            temp->valx = val;
            nextx->next = temp;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
            this->addAtHead(val);
        else
        {
            int cnt = 0;
            MyLinkedList *nextx = this;
            while (nextx->next != NULL)
            {

                if (cnt == index - 1)
                    break;
                cnt++;
                nextx = nextx->next;
            }
            if (cnt < index - 1)
                return;
            MyLinkedList *temp = new MyLinkedList();
            temp->valx = val;
            temp->next = nextx->next;
            nextx->next = temp;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            if (next == NULL)
                valx = -1;
            else
            {
                valx = next->valx;
                next = next->next;
            }
        }
        else
        {
            int cnt = 0;
            MyLinkedList *nextx = this;
            while (nextx->next != NULL)
            {
                if (cnt == index - 1)
                    break;
                cnt++;
                nextx = nextx->next;
            }

            if (cnt < index - 1 || nextx->next == NULL)
                return;
            nextx->next = nextx->next->next;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    int param_1 = obj->get(1);
    obj->deleteAtIndex(1);
    int param_2 = obj->get(1);
    int param_3 = obj->get(3);
    obj->deleteAtIndex(3);
    obj->deleteAtIndex(0);
    int param_4 = obj->get(0);
    obj->deleteAtIndex(0);
    int param_5 = obj->get(0);
    dg(param_1);
    dg(param_2);
    dg(param_3);
    dg(param_4);
    dg(param_5);
    // obj->addAtHead(5);
    // obj->addAtTail(3);
    // obj->addAtIndex(1,2);
    // obj->deleteAtIndex(0);

    return 0;
}
