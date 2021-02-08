#include "Core/Database.hpp"

namespace Ambrosia::Core
{
    Database::Database() {

    }

    Database::~Database() {

    }

    void Database::Init(string connectionString)
    {
        this->sql = make_unique<soci::session>("sqlite3", "dbname=test.db");
        Entities::Recipe::InitTable(*sql);
        Entities::Recipe recipe("Test", "teasdsad");
        Entities::Recipe recipe2("Test", "teasdsad");
        Entities::Recipe recipe3("Test", "teasdsad");
        Entities::Recipe recipe4("Test", "teasdsad");
        Entities::Recipe recipe5("Test", "teasdsad");
        Entities::Recipe recipe6("Test", "teasdsad");


        Entities::Recipe::Add(*sql, recipe);
        Entities::Recipe::Add(*sql, recipe2);
        Entities::Recipe::Add(*sql, recipe3);
        Entities::Recipe::Add(*sql, recipe4);
        Entities::Recipe::Add(*sql, recipe5);
        Entities::Recipe::Add(*sql, recipe6);
    }

#pragma region "EntityAcessors"#

    std::vector<Entities::Recipe> Database::GetRecipes() {
        if(!GetSQLInitialized()) {
            std::cerr << "ERROR: Database not Initialized...\n";
            throw std::runtime_error("Database not initialized");
        }


        std::vector<Entities::Recipe> recipes;



        soci::rowset<Entities::Recipe> rs = (sql->prepare << "SELECT * FROM recipes");

        for(auto i : rs)
        {
            recipes.push_back(i);
        }


        return recipes;
    }

#pragma endregion
}
