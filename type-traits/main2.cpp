#include <iostream>

#include "test/tester.h"

using namespace std;
// Separate files
class UserRepository {
    public: 
        virtual bool isUserLoggedIn(string email) = 0;

        virtual bool login(string email, string password) = 0;
};

// Separate files
class UserRepositoryImpl : public UserRepository {
    public:
        bool isUserLoggedIn(string email) {
            // logic
            return false;
        }

        bool login(string email, string password) {

        }
};

// Separate files
class UserRepositoryImpl2 : public UserRepository {
    public:
        bool isUserLoggedIn(string email) {
            // logic2
            return false;
        }

        bool login(string email, string password) {
            // libreria 2
        }
};

// Separate files
class LoginUserUseCase {
    UserRepository* repository;

    void validateCredentials(string email, string password) {
      
    }

    public: 
    LoginUserUseCase(UserRepository* repository) {
        this->repository = repository;
    }

    void execute(string email, string password) {
        if (email == "" || password == "") {
            throw "El email o password no debe estar vacio";
        }   

        if (repository->isUserLoggedIn(email)) {
            throw "El usuario ya está logeado";
        }

        validateCredentials(email, password);
        repository->login(email, password);
    }
};

UserRepository* repository = new UserRepositoryImpl2();
LoginUserUseCase loginUserUseCase(repository);

int main(int argc, char const *argv[]) {
    Tester::execute();
    SelfList<int> list(SelfList<int>::Transpose);

    auto email = "luis@luis.com";
    auto password = "luis@luis.com";

    loginUserUseCase.execute(email, password);


    // Double pointers
    auto pointer = &head;

    auto temp1 = head;

    head = new Node<int>;
    Node<int>* temp = head;
    temp = new Node<int>;

    Node<int>** temp = &head; 
    (*temp) = new Node<int>;

    auto newNode = new Node<int>;
    newNode->next = *temp;
    *temp = newNode;

    return EXIT_SUCCESS;
}
