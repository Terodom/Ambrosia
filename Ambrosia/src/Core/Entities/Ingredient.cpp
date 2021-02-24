#include "Core/Entities/Ingredient.hpp"

namespace Ambrosia::Core::Entities
{
    Ingredient::Ingredient() {

    }
    
    Ingredient::Ingredient(const std::string& name, double amount, const std::string& measurement_units_guid, const std::string& recipes_guid) {
        this->amount = amount;
        this->name = name;
        this->measurement_units_guid = measurement_units_guid;
        this->recipes_guid = recipes_guid;
    }

    Ingredient::~Ingredient() {

    }

    void Ingredient::InitTable(soci::session& sql) {
        sql <<  "CREATE TABLE IF NOT EXISTS ingredients"
                "("
                    "guid NVARCHAR(255) NOT NULL PRIMARY KEY,"
                    "created_at DATETIME NOT NULL,"
                    "name NVARCHAR(255) NOT NULL,"
                    "amount DOUBLE NOT NULL,"
                    "measurement_units_guid NVARCHAR(255) NOT NULL,"
                    "recipes_guid NVARCHAR(255) NOT NULL,"
                    "FOREIGN KEY(measurement_units_guid) REFERENCES measurement_units(guid),"
                    "FOREIGN KEY(recipes_guid) REFERENCES recipes(guid)"
                ")";
    }

    void Ingredient::Add(soci::session& sql, Ingredient& ing) {
        sql << "INSERT INTO ingredients(guid, created_at, name, amount, measurement_units_guid, recipes_guid)"
               "values(:guid, :created_at, :name, :amount, :measurement_units_guid, :recipes_guid)",
               soci::use(ing.guid), soci::use(ing.created_at), soci::use(ing.name) ,soci::use(ing.amount), soci::use(ing.measurement_units_guid), soci::use(ing.recipes_guid);
    }

    void Ingredient::Delete(soci::session& sql, const Ingredient& ing) {
        sql << "DELETE * from ingredients WHERE guid=" << ing.guid;
    }
}