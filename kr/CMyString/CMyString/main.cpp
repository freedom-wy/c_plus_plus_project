#include <iostream>
using namespace std;

//class Person {
//    public:
//        Person() {
//            cout << "�޲ι���" << endl;
//        }
//        Person(int a, int b) {
//            this->age = a;
//            this->m_height = new int(b); // new����һ��ָ��
//            cout << "�вι���" << endl;
//        }
//        Person(const Person& p) {
//            this->age = p.age;
//            cout << "��������" << endl;
//            this->m_height = new int(*p.m_height); // ���
//        }
//        ~Person() {
//            if (this->m_height != NULL) {
//                delete this->m_height;
//                this->age = 0;
//            }
//            cout << "����" << endl;
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
//    Person p2 = Person(p1); // ���ÿ�������
//    cout << "age: " << p2.GetAge() << endl;
//    Person p3 = p2; // ���ÿ�������
//    cout << "age: " << p3.GetAge() << endl;
//}
//
//void doWork(Person p1) { // ��������
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