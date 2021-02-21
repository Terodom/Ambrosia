#ifndef AMBROSIA_UTILS_HPP
#define AMBROSIA_UTILS_HPP

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/lexical_cast.hpp"

namespace Ambrosia::Core::Utils {
    boost::uuids::uuid NewGUID();
    std::tm Now();
}

#endif