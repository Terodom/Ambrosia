#ifndef AMBROSIA_MODELS_MEASUREMENT_UNITS_HPP
#define AMBROSIA_MODELS_MEASUREMENT_UNITS_HPP

#include "Core/Models/ModelBase.hpp"
#include "Core/Entities/MeasurementUnit.hpp"

namespace Ambrosia::Core::Models
{
    class MeasurementUnit : public ModelBase<Entities::MeasurementUnit> {
        public:
            explicit MeasurementUnit(const Entities::MeasurementUnit& unit);
            explicit MeasurementUnit(const std::string& name);
            ~MeasurementUnit();

            // Getters
            std::string GetName();

            // Setters
            void SetName(const std::string& name);
    };
}

#endif