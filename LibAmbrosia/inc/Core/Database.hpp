#ifndef AMBROSIA_LIB_DATABASE_HPP
#define AMBORISA_LIB_DATABASE_HPP

#include <string>

#include <sqlite3.h>

namespace Ambrosia
{

    namespace Core
    {
        class Database {
            private:
                std::string connectionString;
            public:
                Database();
                ~Database();

                void Init();
        };
    }
}

#endif