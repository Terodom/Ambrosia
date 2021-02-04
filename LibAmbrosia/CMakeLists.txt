find_package(SQLite3 REQUIRED)

set(LIB_AMBROSIA_SOURCES "src/Core/Database.cpp")

add_library(Ambrosia ${LIB_AMBROSIA_SOURCES})
target_include_directories(Ambrosia PUBLIC inc)