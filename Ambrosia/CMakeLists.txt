#find_package(SQLite3 REQUIRED)
#find_package(Soci REQUIRED sqlite3)

set(CMAKE_CXX_STANDARD 17)

set(AMBROSIA_SOURCES  "src/main.cpp"
                      "src/Core/Entities/EntityBase.cpp"
                      "src/Core/Entities/Recipe.cpp"
                      "src/Core/Models/ModelBase.inl"
                      "src/Core/Models/Recipe.cpp"
                      "src/Core/Database.cpp")

add_executable(Ambrosia ${AMBROSIA_SOURCES})

target_include_directories(Ambrosia PUBLIC ${SOCI_INCLUDE_DIRS} "inc")
target_link_libraries(Ambrosia ${SOCI_LIBRARY} ${SOCI_sqlite3_PLUGIN})