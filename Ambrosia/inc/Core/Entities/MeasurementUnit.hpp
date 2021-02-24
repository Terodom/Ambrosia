#ifndef AMBROSIA_MEASUREMENTUNIT_HPP
#define AMBROSIA_MEASUREMENTUNIT_HPP

#include "EntityBase.hpp"

namespace Ambrosia::Core::Entities
{
    class MeasurementUnit : public EntityBase {
        public:
            MeasurementUnit();
            explicit MeasurementUnit(const std::string& name);
            MeasurementUnit(const std::string& guid, const std::tm& created_at,
                            const std::string& name);
            ~MeasurementUnit();

            std::string name;

            static void InitTable(soci::session& sql);
            static void Add(soci::session& sql, MeasurementUnit& mu);
            static void Delete(soci::session& sql, const MeasurementUnit& mu);
    };
}

namespace soci
{

    namespace Entities = Ambrosia::Core::Entities;

    template<>
    struct type_conversion<Entities::MeasurementUnit>
    {
        typedef values base_type;

        static void from_base(values const& v, indicator ind, Entities::MeasurementUnit& r)
        {
            r.guid = v.get<std::string>("guid");
            r.created_at = v.get<std::tm>("created_at");
            r.name = v.get<std::string>("name");
        }

        static void to_base(const Entities::MeasurementUnit& r, values& v, indicator& ind)
        {
            v.set("guid", r.guid);
            v.set("created_at", r.created_at);
            v.set("name", r.name);

            ind = i_ok;
        }
    };
}
#endif