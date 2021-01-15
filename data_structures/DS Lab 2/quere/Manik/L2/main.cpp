#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int n;
class st {
public :
    int roll;
    void input ();
    void calculate();
    double display ();

private :
    char name[20];
    double marks[10];
    double total;
    void total_marks();
} s1[10];

void st :: input () {
    cout << "Enter roll name and marks "<< endl;
    cin >> roll >> name;
    for(int i=0; i<n; i++)
        cin >> marks[i];
}
void st :: total_marks() {
    for(int i=0; i<n; i++)
        total+=marks[i];
}

void st :: calculate() {
    return total_marks();
}

double st :: display() {
    cout << "Total " << total << endl;
}

int main() {

    int m;
    cout << "Number of students " << endl;
    cin >> m;
    cout << "How many subjects ? " << endl;
    cin >> n;
    for(int i=0; i<m; i++) {
        s1[i].input();
        s1[i].calculate();
        cout << "Roll " << s1[i].roll << endl ;
        s1[i].display();
    }
    return 0;
}
