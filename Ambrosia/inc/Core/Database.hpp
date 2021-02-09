#ifndef AMBROSIA_LIB_DATABASE_HPP
#define AMBORISA_LIB_DATABASE_HPP

#include <iostream>
#include <stdexcept>

#include "Entities/Recipe.hpp"
#include "Models/Recipe.hpp"

namespace Ambrosia
{

    namespace Core
    {
        namespace Entities = Ambrosia::Core::Entities;

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

#pragma region "EntityAcessors"

                std::vector<Entities::Recipe> GetRecipes();

#pragma endregion

        };
    }
}

#endif