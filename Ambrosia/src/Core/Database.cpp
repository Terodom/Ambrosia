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

        Entities::Recipe recipe1("asfg", "asdaüsoif");
        Entities::Recipe recipe2("24252", "asdaüsoif");
        Entities::Recipe recipe3("TEasfST", "asdaüsoif");
        Entities::Recipe recipe4("TEasfasST", "asdaüsoif");
        Entities::Recipe recipe5("TE234ST", "asdaüsoif");

        Entities::Recipe::Add(*sql, recipe1);
        Entities::Recipe::Add(*sql, recipe2);
        Entities::Recipe::Add(*sql, recipe3);
        Entities::Recipe::Add(*sql, recipe4);
        Entities::Recipe::Add(*sql, recipe5);
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
            Models::Recipe rec(i);
            std::cout << rec.GetGUID() << " - " << rec.GetTitle() << "\n";
        }


        return recipes;
    }

#pragma endregion
}
