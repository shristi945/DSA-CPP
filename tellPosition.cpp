#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int roll;
    int totalmarks;
};

bool compare(Student* S1, Student* S2){
    if(S1->totalmarks!=S2->totalmarks){
        return S1->totalmarks > S2->totalmarks;
    }
    return S1->roll < S2->roll;
}

int main()
{
    int n;
    cin>>n;

    Student** students=new Student*[n];
    for(int i=0;i<n;i++){
        students[i] = new Student();
    }
    for(int i=0;i<n;i++){
        cin>>students[i]->name;
        students[i]->roll = i+1;
        int m1,m2,m3;
        cin>>m1>>m2>>m3;

        int total = (m1+m2+m3);
        students[i]->totalmarks=total;
    }
    
    std::sort(students, students+n, compare);
    for(int i=0; i<n;i++){
        cout<<(i+1)<<" "<<students[i]->name<<endl;
    }
	return 0;
}
