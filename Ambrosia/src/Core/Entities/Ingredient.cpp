#include "Core/Entities/Ingredient.hpp"

namespace Ambrosia::Core::Entities
{
    Ingredient::Ingredient() {

    }

    Ingredient::~Ingredient() {

    }

    void Ingredient::InitTable(soci::session& sql) {
        sql <<  "CREATE TABLE IF NOT EXISTS ingredients"
                "("
                    "guid NVARCHAR(255) NOT NULL PRIMARY KEY,"
                    "created_at DATETIME NOT NULL,"
                    "title NVARCHAR(255) NOT NULL,"
                    "description NVARCHAR(512) NOT NULL"
                ")";
    }
}