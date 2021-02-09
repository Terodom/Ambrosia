find_package(SQLite3 REQUIRED)
find_package(Soci REQUIRED sqlite3)


set(AMBROSIA_SOURCES  "src/main.cpp"
                      "src/Core/Database.cpp"
                      "src/Core/Entities/EntityBase.cpp"
                      "src/Core/Entities/Recipe.cpp"
                      "src/Core/Models/Recipe.cpp")

add_executable(Ambrosia ${AMBROSIA_SOURCES})

target_include_directories(Ambrosia PUBLIC ${SOCI_INCLUDE_DIRS} "inc")
target_link_libraries(Ambrosia SQLite::SQLite3 ${SOCI_LIBRARY} ${SOCI_sqlite3_PLUGIN})