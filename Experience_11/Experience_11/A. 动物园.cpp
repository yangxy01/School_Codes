//#include<iostream>
//#include<string>
//using namespace std;
//class Animal
//{
//protected:
//    string type;
//    string name;
//    int age;
//public:
//    Animal(string type = "no", string name = "no", int age = 0)
//    {
//        this->type = type;
//        this->name = name;
//        this->age = age;
//    }
//    virtual void speak() = 0;
//};
//class Tiger :public Animal
//{
//public:
//    Tiger(string type = "no", string name = "no", int age = 0) :
//        Animal(type, name, age) {}
//    void speak() { cout << "Hello,I am " << name << ",AOOO." << endl; }
//};
//class Dog :public Animal
//{
//public:
//    Dog(string type = "no", string name = "no", int age = 0) :
//        Animal(type, name, age) {}
//    void speak() { cout << "Hello,I am " << name << ",WangWang." << endl; }
//};
//class Duck :public Animal
//{
//public:
//    Duck(string type = "no", string name = "no", int age = 0) :
//        Animal(type, name, age) {}
//    void speak() { cout << "Hello,I am " << name << ",GAGA." << endl; }
//};
//class Pig :public Animal
//{
//public:
//    Pig(string type = "no", string name = "no", int age = 0) :
//        Animal(type, name, age) {}
//    void speak() { cout << "Hello,I am " << name << ",HENGHENG." << endl; }
//};
//
////void callspeak(Animal* p)
////{
////    p->speak();
////}
//
//int main()
//{
//    int t;
//    string type;
//    string name;
//    int age;
//    cin >> t;
//    while (t--)
//    {
//        Animal* p = NULL;
//        cin >> type >> name >> age;
//        if (type == "Tiger")
//        {
//            p=new Tiger(type, name, age);
//        }
//        else if (type == "Dog")
//        {
//            p = new Dog(type, name, age);
//
//        }
//        else if (type == "Duck")
//        {
//            p = new Duck(type, name, age);
//
//        }
//        else if (type == "Pig")
//        {
//            p = new Pig(type, name, age);
//        }
//        else
//        {
//            cout << "There is no " << type << " in our Zoo." << endl;
//            continue;
//        }
//        p->speak();
//        delete p;
//            
//    }
//    return 0;
//}