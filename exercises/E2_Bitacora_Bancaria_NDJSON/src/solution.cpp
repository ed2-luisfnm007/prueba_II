#include "solution.hpp"

#include <nlohmann/json.hpp>

#include <fstream>
#include <stdexcept>

BankReport process_transactions(const std::string& ndjson_path) {
    BankReport report;

    // TODO: abra el archivo con std::ifstream y lea línea por línea con
    //   std::getline. No cargue el archivo completo en un único arreglo JSON.
    //
    // TODO: convierta cada línea con nlohmann::json::parse(line). Si el parse
    //   falla, incremente invalid_records y continúe (no detenga el proceso).
    //
    // TODO: lea account, type, amount. CREDIT suma amount, DEBIT lo resta.
    //
    // TODO: registre en large_transactions las transacciones con amount >= 1000.00.

    return report;
}
