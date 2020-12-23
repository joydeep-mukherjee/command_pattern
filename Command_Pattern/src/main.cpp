//this program implements the observer pattern

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class BankAccount {
public:
    int32_t     m_balance;

    void deposit(int32_t amount) { m_balance += amount; }
    void withdraw(int32_t amount) { m_balance -= amount; }
    void display(){cout<<"Balance is :"<<m_balance<<endl;}
};

class Command {
public:
    virtual void execute() = 0;
};

class BankAccountCommand : public Command {
public:
    enum class Action : bool { deposit, withdraw };
    BankAccount&      m_ac;
    Action            m_action;
    int32_t           m_amount;

    BankAccountCommand(BankAccount& ac, Action a, int32_t amnt)
    : m_ac(ac), m_action(a), m_amount(amnt) {}

    void execute() {
        (m_action == Action::deposit) ? m_ac.deposit(m_amount) : m_ac.withdraw(m_amount);
    }
};


int main() {
    BankAccount ba1{1000};
    BankAccount ba2{1000};

    vector<BankAccountCommand> commands{
        BankAccountCommand{ba1, BankAccountCommand::Action::withdraw, 200},
        BankAccountCommand{ba2, BankAccountCommand::Action::deposit, 200}
    };

    for (auto& cmd : commands)
        cmd.execute();


    ba1.display();
    ba2.display();

    return EXIT_SUCCESS;
}
