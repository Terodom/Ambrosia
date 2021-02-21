#ifndef AMBROSIA_LIB_ENTITYBASE_HPP
#define AMBROSIA_LIB_ENTITYBASE_HPP

#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include <chrono>
#include <iostream>

#include "soci/soci.h"

#include "Core/Utils/Utils.hpp"

namespace Ambrosia::Core::Entities
{
    /**
    *  @brief Base Class for all Database Interactions
    */
    class EntityBase
    {
        public:
            std::string guid;
            std::tm created_at;
    };
}

#endif