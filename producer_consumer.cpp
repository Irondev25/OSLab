#include <iostream>
using namespace std;

int mutex = 1, in = 0, out = 0, count = 0, a[10];

int cap;

//atomic wait
int wait(int x)
{
    return --x;
}

//atomic signal
int signal(int x)
{
    return ++x;
}

void producer(int x)
{
    mutex = wait(mutex);
    a[in] = x;
    in = (in + 1) % (cap + 1);
    count = signal(count);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    // if (out == in)
    // {
    //     cout << "Buff empty"<<endl;
    //     return;
    // }
    cout << a[out]<<endl;
    out = (out + 1) % (cap + 1);
    count = wait(count);
    mutex = signal(mutex);
}

int main()
{
    int ch;
    cin >> cap;
    while (1)
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            if ((in + 1) % (cap + 1) == out)
            {
                cout << "Overflow" << endl;
            }
            else
            {
                int key;
                cin >> key;
                producer(key);
            }
            break;
        case 2:
            if(out==in){
                cout<<"Underflow"<<endl;
            }
            else{
                consumer();
            }
            break;
        case 3:
            exit(0);
        }
    }
}