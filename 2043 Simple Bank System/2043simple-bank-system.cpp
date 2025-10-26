class Bank {
public:
    vector<long long> khaata;
    int n;

    Bank(vector<long long>& balance) {
        khaata = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 >= 1 && account1 <= n && account2 >= 1 && account2 <= n && khaata[account1 - 1] >= money) {
            khaata[account1 - 1] -= money;  // Deduct from sender
            khaata[account2 - 1] += money;  // Add to receiver
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (account >= 1 && account <= n) {
            khaata[account - 1] += money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        if (account >= 1 && account <= n && khaata[account - 1] >= money) {
            khaata[account - 1] -= money;
            return true;
        }
        return false;
    }
};
