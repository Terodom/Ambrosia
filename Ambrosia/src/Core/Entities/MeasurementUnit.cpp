#include "Core/Entities/MeasurementUnit.hpp"

namespace Ambrosia::Core::Entities
{
    MeasurementUnit::MeasurementUnit() {

    }

    MeasurementUnit::MeasurementUnit(const std::string& name) {
        this->guid = Utils::NewGUIDAsString();
    }

    MeasurementUnit::MeasurementUnit(const std::string& guid, const std::tm& created_at,
                                     const std::string& name) {
        this->guid = guid;
        this->created_at = created_at;
        this->name = name;
    }

    MeasurementUnit::~MeasurementUnit() {

    }

    void MeasurementUnit::InitTable(soci::session& sql) {
        sql <<  "CREATE TABLE IF NOT EXISTS measurement_units"
                "("
                    "guid NVARCHAR(255) NOT NULL PRIMARY KEY,"
                    "created_at DATETIME NOT NULL,"
                    "name NVARCHAR(255) NOT NULL"
                ")";
    }

    void MeasurementUnit::Add(soci::session& sql, MeasurementUnit& mu) {
        sql <<  "INSERT INTO measurement_units(guid, created_at, name)"
                "values(:guid, :created_at, :name)",
                soci::use(mu.guid), soci::use(mu.created_at), soci::use(mu.name);
    }

    void MeasurementUnit::Delete(soci::session& sql, const MeasurementUnit& mu) {
        sql << "DELETE * FROM measurement_units WHERE guid=" << mu.guid;
    }
}