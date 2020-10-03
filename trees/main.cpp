#include <iostream>

using namespace std;

struct Student {
    int id;
    string firstname;
    string lastname;
    string address;
    string phone;
};

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();

    BSTree<string> test;

    test.insert(5, "hola");

    test[5] = "hola";
    test[5] = "chau";

    test.remove(5);

    Student luis;
    luis.id = 7;
    luis.firstname = "Luis";
    luis.lastname = "Talavera";

    BSTree<Student> students;
    students[luis.id] = luis;

    if (students.hasKey(luis.id)) {
        auto student = students[luis.id];
        // work with student
    }

    auto it = students.begin();

    while (it != students.end()) {
        auto userInfo = *it;
        auto key = userInfo.first;
        auto student = userInfo.second;

        cout << "Key: " << userInfo.first << endl;
        cout << "Value: " << userInfo.second.firstname << endl;
        ++it;
    }

    return EXIT_SUCCESS;
}