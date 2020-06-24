#include "SerializeConfig.h"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "ThorSerialize/Traits.h"
#include "ThorSerialize/JsonThor.h"
#include "ThorSerialize/SerUtil.h"
#include "filterTest.h"

using namespace ThorsAnvil::Serialize;

TEST(FilterTes, BasicFilter)
{
    using ThorsAnvil::Serialize::jsonImporter;
    using ThorsAnvil::Serialize::jsonExporter;

    std::ifstream       jsonStrem("test/data/large.json");
    std::vector<Data>    value;
    jsonStrem >> jsonImporter(value);
    EXPECT_EQ(1, value.size());
}

