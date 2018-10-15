/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2018      Lee Clagett <https://github.com/vtnerd>
 * Copyright 2016-2018 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef XMRIG_OCLGPU_H
#define XMRIG_OCLGPU_H


#include <vector>


#include "amd/GpuContext.h"
#include "common/xmrig.h"


namespace xmrig {
    class Config;
}


class OclGPU
{
public:
    static int findPlatformIdx(xmrig::Config *config);
    static std::vector<GpuContext> getDevices(xmrig::Config *config);

private:
    static int findPlatformIdx(xmrig::OclVendor vendor, char *name, size_t nameSize);
};


void printPlatforms();

size_t InitOpenCL(GpuContext *ctx, size_t num_gpus, xmrig::Config *config);
size_t XMRSetJob(GpuContext *ctx, uint8_t *input, size_t input_len, uint64_t target, xmrig::Variant variant);
size_t XMRRunJob(GpuContext *ctx, cl_uint *HashOutput, xmrig::Variant variant);

#endif /* XMRIG_OCLGPU_H */
