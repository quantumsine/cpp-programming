#include <iostream>
#include <string>
#include <memory>
using namespace std;

class AuthenticationResult{
  const bool _c_is_authenticated;
  const string _c_username;

  public:
    AuthenticationResult( bool is_authenticated, const string& username = "unauthenticated_user" ): _c_is_authenticated(is_authenticated), _c_username(username) {}

    string get_username() const{
      return _c_username;
    }

    bool is_authenticated() const{
      return _c_is_authenticated;
    }
};

class IAuthenticationProcedure{
  public:
    virtual AuthenticationResult authenticate() = 0;
};

class Client{
  IAuthenticationProcedure* _authentication_procedure = nullptr;

  public:
    void set_authentication_procedure(IAuthenticationProcedure* auth_procedure){
      _authentication_procedure = auth_procedure;
    }

    void execute() const{
      if (!_authentication_procedure) return;

      const AuthenticationResult result = _authentication_procedure->authenticate();
      if (result.is_authenticated()){
        cout << "Das Programm wird ausgeführt für " << result.get_username()<< "." << endl;
      } else {
        cout << "Das Programm konnte nicht ausgeführt werden." << endl;
      }
     }

};

class MockAuthentication : public IAuthenticationProcedure{
  public:
    AuthenticationResult authenticate() override{
      return AuthenticationResult(true, "Default");
    }
};

class UsernamePassword : public IAuthenticationProcedure {
  public:
    AuthenticationResult authenticate() override{
      string username, password;
      cout << "Username: " << endl;
      getline(cin, username);
      cout << "Password: " << endl;
      getline(cin, password);

      if(username == password){
        return AuthenticationResult(true, username);
      } else {
        return AuthenticationResult(false);
       }
    }
};


class Certificate : public IAuthenticationProcedure{
  public:
    AuthenticationResult authenticate() override{
      string issuer;
      cout << "Zertifikatsaussteller: " << endl;
      getline(cin, issuer);

      if(issuer == "hs-esslingen") {
        return AuthenticationResult(true, "certificate.owner");
      } else {
        return AuthenticationResult(false);
      }
    }
};


int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung über das Authentifizierungsverfahren Mock Authentication" << endl;
    IAuthenticationProcedure* mock_authentication = new MockAuthentication();
    client.set_authentication_procedure(mock_authentication);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Username Password" << endl;
    IAuthenticationProcedure* username_password = new UsernamePassword();
    client.set_authentication_procedure(username_password);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Zertifikat" << endl;
    IAuthenticationProcedure* certificate = new Certificate();
    client.set_authentication_procedure(certificate);
    client.execute();
    return 0;
}