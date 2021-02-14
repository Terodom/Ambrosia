#ifndef AMBROSIA_LIB_DATABASE_HPP
#define AMBROSIA_LIB_DATABASE_HPP

#include <iostream>
#include <stdexcept>

#include "Models/Recipe.hpp"

namespace Ambrosia
{

    namespace Core
    {

        using std::string;
        using std::unique_ptr;
        using std::make_unique;

        class Database {
            private:
                string connectionString;
                unique_ptr<soci::session> sql;

            public:
                Database();
                ~Database();

                void Init(string connectionString);

                const inline bool GetSQLInitialized() { return sql != nullptr; };


                #pragma region "Adders"

                void Add(Models::Recipe& recipe);

                #pragma endregion


                #pragma region "EntityAcessors"

                std::vector<Models::Recipe> GetRecipes();

                #pragma endregion

        };
    }
}

#endif