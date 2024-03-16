#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int	Account::getNbAccounts(void){return _nbAccounts;}
int	Account::getTotalAmount(void){return _totalAmount;}
int	Account::getNbDeposits(void){return _totalNbDeposits;}
int	Account::getNbWithdrawals(void){return _totalNbWithdrawals;}

void Account::_displayTimestamp(void){
    time_t t;
    char buf[16];
    
    time(&t);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&t));
    std::cout << "[" << buf << "] ";
}

void Account::displayAccountsInfos(void){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << "\n";
}

void Account::displayStatus(void) const{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals << "\n";
}

Account::Account(int initial_deposit){
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += this->_amount;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";created\n";
}

Account::~Account(void){
    this->_nbAccounts--;
    _totalAmount -= this->_amount;
    _totalNbDeposits -= this->_nbDeposits;
    _totalNbWithdrawals -= this->_nbWithdrawals;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";closed\n";
}

void Account::makeDeposit(int deposit){
    _totalNbDeposits++;
    this->_nbDeposits++;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount - deposit;
    std::cout << ";deposit:" << deposit;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal){
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    this->_amount -= withdrawal;
    if (!checkAmount()){
        this->_amount += withdrawal;
        std::cout << ";withdrawal:refused\n";
        return false;
    }
    else{
        _totalNbWithdrawals++;
        this->_nbWithdrawals++;
        this->_totalAmount -= withdrawal;
        std::cout << ";withdrawal:" << withdrawal;
        std::cout << ";amount:" << this->_amount;
        std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << "\n";
        return true;
    }
}

int Account::checkAmount(void) const{
    if (this->_amount < 0)
        return 0;
    return 1;
}

