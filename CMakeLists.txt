cmake_minimum_required(VERSION 3.14)
project(Prueba_II LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Base URL of the LOCAL Forgejo instance that mirrors the two libraries.
# Defaults to the exam-network address. For local/offline testing override with:
#   cmake -DFORGEJO_BASE_URL=http://localhost:8081 ...
set(FORGEJO_BASE_URL "http://192.168.86.10:8081" CACHE STRING
    "Base URL of the local Forgejo instance (no trailing slash)")

include(FetchContent)

# ---------------------------------------------------------------------------
# fast-csv-parser (header-only). Mirrored locally; pinned to a known commit.
# ---------------------------------------------------------------------------
FetchContent_Declare(
    fast_cpp_csv_parser
    GIT_REPOSITORY "${FORGEJO_BASE_URL}/libs/fast-csv-parser.git"
    GIT_TAG 574a9fe4d323ba63416877a4a5fe59088d37aa34
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(fast_cpp_csv_parser)

add_library(fast_cpp_csv_parser INTERFACE)
target_include_directories(fast_cpp_csv_parser INTERFACE
    "${fast_cpp_csv_parser_SOURCE_DIR}")

# The parser may use a background I/O thread.
find_package(Threads REQUIRED)

# ---------------------------------------------------------------------------
# nlohmann/json. Mirrored locally; pinned to release tag v3.11.3.
# ---------------------------------------------------------------------------
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY "${FORGEJO_BASE_URL}/libs/nlohmann-json.git"
    GIT_TAG v3.11.3
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(nlohmann_json)

# ---------------------------------------------------------------------------
# doctest (vendored single header, no network needed).
# ---------------------------------------------------------------------------
add_library(doctest INTERFACE)
target_include_directories(doctest INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/doctest")

enable_testing()

add_subdirectory(exercises)
