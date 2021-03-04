// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2020-2021 Intel Corporation. All Rights Reserved.
#include "Cmds.h"
#include <sstream>

namespace RealSenseID
{
namespace FwUpdate
{
std::string Cmds::dlver()
{
    return "dlver";
}

std::string Cmds::dlspd(uint32_t spd)
{
    std::ostringstream oss;
    oss << "dlspd " << spd;
    return oss.str();
}

std::string Cmds::dlinfo(const std::string& module_name)
{
    std::ostringstream oss;
    oss << "dlinfo " << module_name;
    return oss.str();
}

std::string Cmds::dlinit(const std::string& name, const std::string& version, size_t size,
                                          bool start_session, uint32_t crc, uint32_t block_size)
{
    std::ostringstream oss;
    oss << "dlinit " << name << " ver=" << version << " sz=" << size << " blksz=" << block_size << " crc=" << std::hex
        << crc;

    if (start_session)
        oss << " session";

    return oss.str();
}

std::string Cmds::dl(size_t n)
{
    std::ostringstream oss;
    oss << "dl " << n;

    return oss.str();
}

std::string Cmds::dlact(bool is_last)
{
    std::ostringstream oss;
    oss << "dlact ";

    if (is_last)
        oss << " session reboot";
   
    return oss.str();
}
} // namespace FwUpdate
} // namespace RealSenseID