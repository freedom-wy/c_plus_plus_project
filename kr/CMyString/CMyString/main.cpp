#include <iostream>
using namespace std;

//class Person {
//    public:
//        Person() {
//            cout << "无参构造" << endl;
//        }
//        Person(int a, int b) {
//            this->age = a;
//            this->m_height = new int(b); // new返回一个指针
//            cout << "有参构造" << endl;
//        }
//        Person(const Person& p) {
//            this->age = p.age;
//            cout << "拷贝构造" << endl;
//            this->m_height = new int(*p.m_height); // 深拷贝
//        }
//        ~Person() {
//            if (this->m_height != NULL) {
//                delete this->m_height;
//                this->age = 0;
//            }
//            cout << "析构" << endl;
//        }
//
//        int GetAge() {
//            return this->age;
//        }
//    private:
//        int age;
//        int* m_height;
//};
//
//void test01() {
//    Person p;
//}
//
//void test02() {
//    Person p1(10, 20);
//    cout << "age: " << p1.GetAge() << endl;
//    Person p2 = Person(p1); // 调用拷贝构造
//    cout << "age: " << p2.GetAge() << endl;
//    Person p3 = p2; // 调用拷贝构造
//    cout << "age: " << p3.GetAge() << endl;
//}
//
//void doWork(Person p1) { // 拷贝构造
//    cout << "age: " << p1.GetAge() << endl;
//};
//
//void test03() {
//    Person p1(10, 20);
//    doWork(p1);
//}
//
//int main() {
//    // test01();
//    test03();
//    return 0;
//}