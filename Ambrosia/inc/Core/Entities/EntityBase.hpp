#ifndef AMBROSIA_ENTITYBASE_HPP
#define AMBROSIA_ENTITYBASE_HPP

#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include <chrono>

#include "soci/soci.h"
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/lexical_cast.hpp"

namespace Ambrosia::Core::Entities
{
    /*
        Base class for all database entities.
        Only inherit.
    */
    class EntityBase
    {
        public:
            std::string guid;
            std::tm created_at;
    };
}

#endif