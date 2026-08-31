#pragma once

#include <map>
#include <string>
#include <vector>

struct BankReport {
    std::map<std::string, double> balances;       // cuenta -> balance final
    std::vector<std::string> large_transactions;  // descripciones de montos >= 1000.00
    int valid_records = 0;
    int invalid_records = 0;
};

// Procesa un archivo NDJSON línea por línea (NO cargue el archivo completo en
// un único arreglo JSON). CREDIT suma el monto, DEBIT lo resta.
BankReport process_transactions(const std::string& ndjson_path);
