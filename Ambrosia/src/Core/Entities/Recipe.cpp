#include "Core/Entities/Recipe.hpp"

namespace Ambrosia::Core::Entities
{
    Recipe::Recipe() {

    }

    Recipe::Recipe(std::string title, std::string description) {
        this->guid = boost::lexical_cast<std::string>(Utils::NewGUID());
        this->created_at = Utils::Now();
        this->title = title;
        this->description = description;
    }

    Recipe::Recipe( std::string guid, std::tm created_at,
                    std::string title, std::string description) {
        this->title = title;
        this->description = description;
        this->guid = guid;
        this->created_at = created_at;
    }

    Recipe::~Recipe() {

    }

    void Recipe::InitTable(soci::session& sql)
    {
        sql <<   "CREATE TABLE IF NOT EXISTS recipes"
                 "("
                    "guid NVARCHAR(255) NOT NULL PRIMARY KEY,"
                    "created_at DATETIME NOT NULL,"
                    "title NVARCHAR(255) NOT NULL,"
                    "description NVARCHAR(512) NOT NULL"
                 ")";
    }

    void Recipe::Add(soci::session& sql, Recipe& recipe) {
        sql << "INSERT INTO recipes(guid, created_at, title, description)"
                "values(:guid, :created_at, :title, :description)",
                soci::use(recipe.guid), soci::use(recipe.created_at),
                soci::use(recipe.title), soci::use(recipe.description);
    }

    void Recipe::Delete(soci::session& sql, Recipe& recipe) {
        sql << "DELETE * FROM recipes WHERE guid=" << recipe.guid;
    }
}