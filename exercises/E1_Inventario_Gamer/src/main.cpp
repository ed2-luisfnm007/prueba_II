#include "solution.hpp"

#include <format>
#include <iostream>
#include <stdexcept>

int main() {
    const std::string path = std::string(DATA_DIR) + "/products.csv";

    try {
        const InventoryReport report = analyze_inventory(path);

        std::cout << std::format("Total inventory value: ${:.2f}\n", report.total_value);

        std::cout << "Out of stock: ";
        for (const auto& sku : report.out_of_stock) {
            std::cout << sku << ' ';
        }
        std::cout << '\n';

        std::cout << "Low stock: ";
        for (const auto& sku : report.low_stock) {
            std::cout << sku << ' ';
        }
        std::cout << '\n';

        std::cout << std::format("Highest price: {} (${:.2f})\n",
                                 report.highest_price_sku, report.highest_price);
    } catch (const std::exception& error) {
        std::cerr << std::format("Error: {}\n", error.what());
        return 1;
    }

    return 0;
}
