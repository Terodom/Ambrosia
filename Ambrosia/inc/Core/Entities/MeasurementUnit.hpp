#ifndef AMBROSIA_MEASUREMENTUNIT_HPP
#define AMBROSIA_MEASUREMENTUNIT_HPP

#include "EntityBase.hpp"

namespace Ambrosia::Core::Entities
{
    class MeasurementUnit : public EntityBase {
        public:
            MeasurementUnit();
            MeasurementUnit(std::string name);
            MeasurementUnit(std::string guid, std::tm created_at,
                            std::string name);
            ~MeasurementUnit();

            std::string name;

            static void InitTable(soci::session& sql);
            static void Add(soci::session& sql, MeasurementUnit& mu);
            static void Delete(soci::session& sql, MeasurementUnit& mu);
    };
}
#endif