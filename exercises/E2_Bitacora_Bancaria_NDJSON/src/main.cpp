#include "solution.hpp"

#include <format>
#include <iostream>
#include <stdexcept>

int main() {
    const std::string path = std::string(DATA_DIR) + "/transactions.ndjson";

    try {
        const BankReport report = process_transactions(path);

        std::cout << "Balances:\n";
        for (const auto& [account, balance] : report.balances) {
            std::cout << std::format("  {} = ${:.2f}\n", account, balance);
        }

        std::cout << "Large transactions (>= $1000):\n";
        for (const auto& t : report.large_transactions) {
            std::cout << "  " << t << '\n';
        }

        std::cout << std::format("Valid records: {}, Invalid records: {}\n",
                                 report.valid_records, report.invalid_records);
    } catch (const std::exception& error) {
        std::cerr << std::format("Error: {}\n", error.what());
        return 1;
    }

    return 0;
}
