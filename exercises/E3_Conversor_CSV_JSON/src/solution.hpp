#pragma once

#include <string>
#include <vector>

struct ConversionResult {
    int record_count = 0;
    bool verified = false;
    std::vector<std::string> differences;  // descripciones de diferencias encontradas
};

// Lee el CSV, escribe un JSON (sangría de 2 espacios) con metadatos de nivel
// superior `warehouse` y `generated_at`, vuelve a abrir el JSON y verifica la
// integridad round-trip (número de registros, sku, name, stock y price).
ConversionResult convert_and_verify(const std::string& csv_path,
                                    const std::string& json_out_path);
