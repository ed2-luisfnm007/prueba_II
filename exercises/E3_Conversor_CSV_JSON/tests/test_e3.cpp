#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "solution.hpp"

#include <filesystem>
#include <string>

TEST_CASE("E3: round-trip verificado") {
    const std::string csv = std::string(DATA_DIR) + "/products.csv";
    const std::string out =
        (std::filesystem::temp_directory_path() / "e3_roundtrip.json").string();

    const ConversionResult r = convert_and_verify(csv, out);

    CHECK(r.record_count == 4);
    CHECK(r.verified == true);
    CHECK(r.differences.empty());

    std::filesystem::remove(out);
}
