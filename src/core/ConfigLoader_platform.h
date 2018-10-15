/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2016-2018 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 *
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

#ifndef XMRIG_CONFIGLOADER_PLATFORM_H
#define XMRIG_CONFIGLOADER_PLATFORM_H


#ifdef _MSC_VER
#   include "getopt/getopt.h"
#else
#   include <getopt.h>
#endif


#include "common/interfaces/IConfig.h"
#include "version.h"


namespace xmrig {


static char const usage[] = "\
Usage: " APP_ID " [OPTIONS]\n\
Options:\n\
  -a, --algo=ALGO              specify the algorithm to use\n\
                                 cryptonight\n"
#ifndef XMRIG_NO_AEON
"\
                                 cryptonight-lite\n"
#endif
#ifndef XMRIG_NO_SUMO
"\
                                 cryptonight-heavy\n"
#endif
"\
  -o, --url=URL                URL of mining server\n\
  -O, --userpass=U:P           username:password pair for mining server\n\
  -u, --user=USERNAME          username for mining server\n\
  -p, --pass=PASSWORD          password for mining server\n\
      --rig-id=ID              rig identifier for pool-side statistics (needs pool support)\n\
  -k, --keepalive              send keepalived for prevent timeout (needs pool support)\n\
      --nicehash               enable nicehash.com support\n\
      --tls                    enable SSL/TLS support (needs pool support)\n\
      --tls-fingerprint=F      pool TLS certificate fingerprint, if set enable strict certificate pinning\n\
  -r, --retries=N              number of times to retry before switch to backup server (default: 5)\n\
  -R, --retry-pause=N          time to pause between retries (default: 5)\n\
      --opencl-devices=N       list of OpenCL devices to use.\n\
      --opencl-launch=IxW      list of launch config, intensity and worksize\n\
      --opencl-strided-index=N list of strided_index option values for each thread\n\
      --opencl-mem-chunk=N     list of mem_chunk option values for each thread\n\
      --opencl-comp-mode=N     list of comp_mode option values for each thread\n\
      --opencl-affinity=N      list of affinity GPU threads to a CPU\n\
      --opencl-platform=N      OpenCL platform index\n\
      --opencl-loader=N        path to OpenCL-ICD-Loader (OpenCL.dll or libOpenCL.so)\n\
      --print-platforms        print available OpenCL platforms and exit\n\
      --no-cache               disable OpenCL cache\n\
      --no-color               disable colored output\n\
      --variant                algorithm PoW variant\n\
      --donate-level=N         donate level, default 5%% (5 minutes in 100 minutes)\n\
      --user-agent             set custom user-agent string for pool\n\
  -B, --background             run the miner in the background\n\
  -c, --config=FILE            load a JSON-format configuration file\n\
  -l, --log-file=FILE          log all output to a file\n"
# ifdef HAVE_SYSLOG_H
"\
  -S, --syslog                 use system log for output messages\n"
# endif
"\
      --print-time=N           print hashrate report every N seconds\n\
      --api-port=N             port for the miner API\n\
      --api-access-token=T     access token for API\n\
      --api-worker-id=ID       custom worker-id for API\n\
      --api-id=ID              custom instance ID for API\n\
      --api-ipv6               enable IPv6 support for API\n\
      --api-no-restricted      enable full remote access (only if API token set)\n\
      --dry-run                test configuration and exit\n\
  -h, --help                   display this help and exit\n\
  -V, --version                output version information and exit\n\
";


static char const short_options[] = "a:c:khBp:Px:r:R:s:T:o:u:O:Vl:S";


static struct option const options[] = {
    { "algo",                 1, nullptr, xmrig::IConfig::AlgorithmKey      },
    { "api-access-token",     1, nullptr, xmrig::IConfig::ApiAccessTokenKey },
    { "api-port",             1, nullptr, xmrig::IConfig::ApiPort           },
    { "api-worker-id",        1, nullptr, xmrig::IConfig::ApiWorkerIdKey    },
    { "api-id",               1, nullptr, xmrig::IConfig::ApiIdKey          },
    { "api-ipv6",             0, nullptr, xmrig::IConfig::ApiIPv6Key        },
    { "api-no-restricted",    0, nullptr, xmrig::IConfig::ApiRestrictedKey  },
    { "background",           0, nullptr, xmrig::IConfig::BackgroundKey     },
    { "config",               1, nullptr, xmrig::IConfig::ConfigKey         },
    { "donate-level",         1, nullptr, xmrig::IConfig::DonateLevelKey    },
    { "dry-run",              0, nullptr, xmrig::IConfig::DryRunKey         },
    { "help",                 0, nullptr, xmrig::IConfig::HelpKey           },
    { "keepalive",            0, nullptr, xmrig::IConfig::KeepAliveKey      },
    { "log-file",             1, nullptr, xmrig::IConfig::LogFileKey        },
    { "nicehash",             0, nullptr, xmrig::IConfig::NicehashKey       },
    { "no-color",             0, nullptr, xmrig::IConfig::ColorKey          },
    { "variant",              1, nullptr, xmrig::IConfig::VariantKey        },
    { "pass",                 1, nullptr, xmrig::IConfig::PasswordKey       },
    { "print-time",           1, nullptr, xmrig::IConfig::PrintTimeKey      },
    { "retries",              1, nullptr, xmrig::IConfig::RetriesKey        },
    { "retry-pause",          1, nullptr, xmrig::IConfig::RetryPauseKey     },
    { "syslog",               0, nullptr, xmrig::IConfig::SyslogKey         },
    { "url",                  1, nullptr, xmrig::IConfig::UrlKey            },
    { "user",                 1, nullptr, xmrig::IConfig::UserKey           },
    { "user-agent",           1, nullptr, xmrig::IConfig::UserAgentKey      },
    { "userpass",             1, nullptr, xmrig::IConfig::UserpassKey       },
    { "rig-id",               1, nullptr, xmrig::IConfig::RigIdKey          },
    { "tls",                  0, nullptr, xmrig::IConfig::TlsKey            },
    { "tls-fingerprint",      1, nullptr, xmrig::IConfig::FingerprintKey    },
    { "version",              0, nullptr, xmrig::IConfig::VersionKey        },
    { "opencl-affinity",      1, nullptr, xmrig::IConfig::OclAffinityKey    },
    { "opencl-devices",       1, nullptr, xmrig::IConfig::OclDevicesKey     },
    { "opencl-launch",        1, nullptr, xmrig::IConfig::OclLaunchKey      },
    { "opencl-platform",      1, nullptr, xmrig::IConfig::OclPlatformKey    },
    { "opencl-strided-index", 1, nullptr, xmrig::IConfig::OclSridedIndexKey },
    { "opencl-mem-chunk",     1, nullptr, xmrig::IConfig::OclMemChunkKey    },
    { "opencl-unroll-factor", 1, nullptr, xmrig::IConfig::OclUnrollKey      },
    { "opencl-unroll",        1, nullptr, xmrig::IConfig::OclUnrollKey      },
    { "opencl-comp-mode",     1, nullptr, xmrig::IConfig::OclCompModeKey    },
    { "no-cache",             0, nullptr, xmrig::IConfig::OclCacheKey       },
    { "print-platforms",      0, nullptr, xmrig::IConfig::OclPrintKey       },
    { "opencl-loader",        1, nullptr, xmrig::IConfig::OclLoaderKey      },
    { nullptr,                0, nullptr, 0 }
};


static struct option const config_options[] = {
    { "algo",              1, nullptr, xmrig::IConfig::AlgorithmKey   },
    { "background",        0, nullptr, xmrig::IConfig::BackgroundKey  },
    { "colors",            0, nullptr, xmrig::IConfig::ColorKey       },
    { "donate-level",      1, nullptr, xmrig::IConfig::DonateLevelKey },
    { "dry-run",           0, nullptr, xmrig::IConfig::DryRunKey      },
    { "log-file",          1, nullptr, xmrig::IConfig::LogFileKey     },
    { "print-time",        1, nullptr, xmrig::IConfig::PrintTimeKey   },
    { "retries",           1, nullptr, xmrig::IConfig::RetriesKey     },
    { "retry-pause",       1, nullptr, xmrig::IConfig::RetryPauseKey  },
    { "syslog",            0, nullptr, xmrig::IConfig::SyslogKey      },
    { "user-agent",        1, nullptr, xmrig::IConfig::UserAgentKey   },
    { "opencl-platform",   1, nullptr, xmrig::IConfig::OclPlatformKey },
    { "cache",             0, nullptr, xmrig::IConfig::OclCacheKey    },
    { "opencl-loader",     1, nullptr, xmrig::IConfig::OclLoaderKey   },
    { "autosave",          0, nullptr, xmrig::IConfig::AutoSaveKey    },
    { nullptr,             0, nullptr, 0 }
};


static struct option const pool_options[] = {
    { "url",             1, nullptr, xmrig::IConfig::UrlKey         },
    { "pass",            1, nullptr, xmrig::IConfig::PasswordKey    },
    { "user",            1, nullptr, xmrig::IConfig::UserKey        },
    { "userpass",        1, nullptr, xmrig::IConfig::UserpassKey    },
    { "nicehash",        0, nullptr, xmrig::IConfig::NicehashKey    },
    { "keepalive",       2, nullptr, xmrig::IConfig::KeepAliveKey   },
    { "variant",         1, nullptr, xmrig::IConfig::VariantKey     },
    { "rig-id",          1, nullptr, xmrig::IConfig::RigIdKey       },
    { "tls",             0, nullptr, xmrig::IConfig::TlsKey         },
    { "tls-fingerprint", 1, nullptr, xmrig::IConfig::FingerprintKey },
    { nullptr,           0, nullptr, 0 }
};


static struct option const api_options[] = {
    { "port",          1, nullptr, xmrig::IConfig::ApiPort           },
    { "access-token",  1, nullptr, xmrig::IConfig::ApiAccessTokenKey },
    { "worker-id",     1, nullptr, xmrig::IConfig::ApiWorkerIdKey    },
    { "ipv6",          0, nullptr, xmrig::IConfig::ApiIPv6Key        },
    { "restricted",    0, nullptr, xmrig::IConfig::ApiRestrictedKey  },
    { "id",            1, nullptr, xmrig::IConfig::ApiIdKey          },
    { nullptr,         0, nullptr, 0 }
};


} /* namespace xmrig */

#endif /* XMRIG_CONFIGLOADER_PLATFORM_H */
