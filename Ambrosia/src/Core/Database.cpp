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

        Models::Recipe recipe1("test", "teasasfst");
        Models::Recipe recipe2("asdasf", "teasfasfst");
        Models::Recipe recipe3("teasfasst", "teasfasfst");
        Models::Recipe recipe4("asfasf", "teasfasfst");
        Models::Recipe recipe5("teasfasfst", "tesasfasft");

        this->Add(recipe1);
        this->Add(recipe2);
        this->Add(recipe3);
        this->Add(recipe4);
        this->Add(recipe5);
    }


    #pragma region "Adders"

    void Database::Add(Models::Recipe& recipe) {
        std::string guid = recipe.GetGUIDAsString();
        std::tm created_at = recipe.GetCreatedAt();
        std::string title = recipe.GetTitle();
        std::string description = recipe.GetDescription();

        *sql << "INSERT INTO recipes(guid, created_at, title, description)"
            "values(:guid, :created_at, :title, :description)",
            soci::use(guid), soci::use(created_at),
            soci::use(title), soci::use(description);
    }

    #pragma endregion


    #pragma region "EntityAcessors"#

    std::vector<Models::Recipe> Database::GetRecipes() {
        if(!GetSQLInitialized()) {
            std::cerr << "ERROR: Database not Initialized...\n";
            throw std::runtime_error("Database not initialized");
        }


        soci::rowset<Entities::Recipe> rs = (sql->prepare << "SELECT * FROM recipes");

        std::vector<Models::Recipe> recipes;

        for(auto i : rs)
        {
            Models::Recipe recipe(i);
            recipes.push_back(recipe);
        }

        return recipes;
    }

    #pragma endregion
}
