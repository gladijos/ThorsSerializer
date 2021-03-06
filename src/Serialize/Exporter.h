#ifndef THORS_ANVIL_SERIALIZE_EXPORTER_H
#define THORS_ANVIL_SERIALIZE_EXPORTER_H
/*
 * The Exporter simply wrap an object of type T so that when serialized
 * it creates an object of type Serializer and calls it appropriately.
 */

#include "Serialize.h"

namespace ThorsAnvil
{
    namespace Serialize
    {

template<typename Format, typename T>
class Exporter
{
    using PrinterConfig = PrinterInterface::PrinterConfig;
    T const&        value;
    PrinterConfig   config;
    bool            catchException;
    public:
        Exporter(T const& value, PrinterConfig config, bool catchException = false)
            : value(value)
            , config(config)
            , catchException(catchException)
        {}
        friend std::ostream& operator<<(std::ostream& stream, Exporter const& data)
        {
            try
            {
                typename Format::Printer    printer(stream, data.config);
                Serializer                  serializer(printer);

                serializer.print(data.value);
            }
            catch (...)
            {
                stream.setstate(std::ios::failbit);
                if (!data.catchException)
                {
                    throw;
                }
            }

            return stream;
        }
};

template<typename Format, typename T>
Exporter<Format, T> Export(T const& value, PrinterInterface::PrinterConfig config = PrinterInterface::PrinterConfig{})
{
    return Exporter<Format, T>(value, config);
}


    }
}

#endif
