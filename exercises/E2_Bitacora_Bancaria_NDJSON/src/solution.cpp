#include "solution.hpp"

#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

namespace nl = nlohmann;

BankReport process_transactions(const std::string &ndjson_path)
{
    BankReport report;

    // TODO: abra el archivo con std::ifstream y lea línea por línea con
    //   std::getline. No cargue el archivo completo en un único arreglo JSON.
    //
    // TODO: convierta cada línea con nlohmann::json::parse(line). Si el parse
    //   falla, incremente invalid_records y continúe (no detenga el proceso).
    //
    // TODO: lea account, type, amount. CREDIT suma amount, DEBIT lo resta.
    //
    // TODO: registre en large_transactions las transacciones con amount >=
    // 1000.00.

    std::ifstream in(ndjson_path);

    if (!in)
    {
        std::cerr << "Not able to open file\n";
        // std::optional would be a way better solution in this case
        return {};
    }

    std::string line;
    report.invalid_records = 0;
    report.valid_records = 0;

    while (std::getline(in, line))
    {
        try
        {
            const nl::json rec = nl::json::parse(line);

            report.valid_records++;

            const auto account = rec.at("account").get<std::string>();
            const auto type = rec.at("type").get<std::string>();
            const auto amount = rec.at("amount").get<double>();

            if (type == "CREDIT")
            {
                report.balances[account] += amount;
            }
            else if (type == "DEBIT")
            {
                report.balances[account] -= amount;
            }

            if (amount >= 1000)
            {
                report.large_transactions.push_back(account);
            }
        }
        catch (const nl::json::parse_error &e)
        {
            std::cerr << ">> PARSE ERROR: " << e.what()
                      << ". The parsing will continue but the damaged record "
                         "will be ignored.\n";
            report.invalid_records++;
            continue;
        }
    }

    return report;
}
