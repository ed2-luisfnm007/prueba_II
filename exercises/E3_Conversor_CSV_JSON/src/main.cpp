#include "solution.hpp"

#include <format>
#include <iostream>
#include <stdexcept>

int main() {
    const std::string csv_path = std::string(DATA_DIR) + "/products.csv";
    const std::string json_path = std::string(DATA_DIR) + "/../inventory.json";

    try {
        const ConversionResult result = convert_and_verify(csv_path, json_path);

        std::cout << std::format("Records: {}\n", result.record_count);
        std::cout << std::format("Verified: {}\n", result.verified ? "true" : "false");

        if (result.differences.empty()) {
            std::cout << "VALIDATION PASSED\n";
        } else {
            std::cout << "Differences found:\n";
            for (const auto& d : result.differences) {
                std::cout << "  - " << d << '\n';
            }
        }

        std::cout << std::format("JSON written to: {}\n", json_path);
    } catch (const std::exception& error) {
        std::cerr << std::format("Error: {}\n", error.what());
        return 1;
    }

    return 0;
}
