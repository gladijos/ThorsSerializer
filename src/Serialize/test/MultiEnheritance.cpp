
#include "gtest/gtest.h"
#include "JsonThor.h"
#include "Serialize.h"

struct Connection
{
    std::string     name;
};
struct IPv4Connection: public Connection
{
    int             ip;
};
struct IPv6Connection: public Connection
{
    int             ip;
    float           lp;
};
struct TcpConnection
{
    std::string     tcpStack;
};
struct UdpConnection
{
    std::string     udpStack;
};
ThorsAnvil_MakeTrait(Connection, name);
ThorsAnvil_ExpandTrait(Connection, IPv4Connection, ip);
ThorsAnvil_ExpandTrait(Connection, IPv6Connection, ip, lp);
ThorsAnvil_MakeTrait(TcpConnection, tcpStack);
ThorsAnvil_MakeTrait(UdpConnection, udpStack);

struct Tcp4Connection : public IPv4Connection, public TcpConnection
{
    int             id;
};
namespace ThorsAnvil
{
    namespace Serialize
    {
    }
}
ThorsAnvil_ExpandTrait(IPv4Connection, Tcp4Connection, id);

TEST(MultiEnheritance, Simple)
{
    Tcp4Connection      data{"google.com", 12, "1:2:3:4:5:6", 8};
}

