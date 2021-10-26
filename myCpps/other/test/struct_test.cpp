#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct student
{
    int no;
    int point1;
    int point2;
    int point3;
    int point4;
    int point5;

    int total() const
    {
        return point1 + point2 + point3 + point4 + point5;
    };

    bool operator<(const student &newStudent1) const
    {

        if (total() < newStudent1.total())
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

// bool operator<(const student & newStudent1,const student & newStudent2)
// {
//     int r1=newStudent1.total;
//     int r2=newStudent2.total;
//     return r1 < r2;
// }

void priority_queue_struct()
{
    priority_queue<student> q;
    srand(time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        student student1 = {i, rand(), rand(), rand(), rand(), rand()};
        q.push(student1);
    }

    while (!q.empty())
    {
        cout << "no:" << q.top().no << ",total:" << q.top().total() << '\n';
        q.pop();
    }
}

void vector_struct()
{
    vector<student> v;
    srand(time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        student student1 = {i, rand(), rand(), rand(), rand(), rand()};
        v.push_back(student1);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < 10; ++i)
    {
        cout << "no:" << v[i].no << ",total:" << v[i].total() << '\n';
    }
}

void struct_as_map_key()
{
    map<student, int> map1;
    for (int i = 0; i < 10; ++i)
    {
        student student1 = {i, rand(), rand(), rand(), rand(), rand()};
        map1[student1] = i;
    }
    cout << map1.size() << endl;
}

struct test
{
    int id;
    int a;
    int b;

    test(int id, int a, int b)
    {

        this->id = id;
        this->a = a;
        this->b = b;
    }

    bool operator<(const test & newtest1) const
    {
        //C++ 严格弱序
        return std::tie(this->a, this->b) < std::tie(newtest1.a, newtest1.b);
    };
};


bool mySortFunc (test &i,test &j)
{
    return i.id<j.id; 
}


int main()
{
    set<test> set1;

    set1.insert(test(4, 2, 1));
    set1.insert(test(6, 1, 2));
    set1.insert(test(7, 2, 1));     //重复

    set1.insert(test(1, 3, 5));
    set1.insert(test(2, 2, 1));
    set1.insert(test(3, 9, 8));

    set1.insert(test(60, 3, 5)); //重复
    set1.insert(test(50, 3, 5)); //重复

    set1.insert(test(35, 2, 1)); //重复

    //遍历set并放入vector
    vector<test> vec1;
    for (set<test>::iterator it=set1.begin(); it!=set1.end(); ++it)
    {
        vec1.push_back(*it);
    }
    
    //根据id排序vector
    sort(vec1.begin(),vec1.end(),mySortFunc);

   
    return 0;
}