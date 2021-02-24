#include "Core/Models/MeasurementUnit.hpp"

namespace Ambrosia::Core::Models
{

    MeasurementUnit::MeasurementUnit(const Entities::MeasurementUnit& unit) : ModelBase(unit) {

    }

    MeasurementUnit::MeasurementUnit(const std::string& name) : ModelBase() {
        this->SetName(name);
    }

    MeasurementUnit::~MeasurementUnit() {

    }

    std::string MeasurementUnit::GetName() {
        return entity.name;
    }

    void MeasurementUnit::SetName(const std::string& name) {
        entity.name = name;
    }

}