/*
 * Copyright (C) 2016 The CyanogenMod Project
 *               2017-2019 The LineageOS Project
 * Copyright (C) 2020 The MoKee Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Utils.h"

#include <cutils/sockets.h>
#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string>

namespace vendor {
namespace mokee {
namespace livedisplay {
namespace V2_0 {
namespace sdm {

int Utils::sendDPPSCommand(char* buf, size_t len) {
    int rc = 0;
    int sock = socket_local_client("pps", ANDROID_SOCKET_NAMESPACE_RESERVED, SOCK_STREAM);
    if (sock < 0) {
        return sock;
    }

    if (write(sock, buf, strlen(buf) + 1) > 0) {
        memset(buf, 0, len);
        ssize_t ret;
        while ((ret = read(sock, buf, len)) > 0) {
            if ((size_t)ret == len) {
                break;
            }
            len -= ret;
            buf += ret;

            struct pollfd p = {.fd = sock, .events = POLLIN, .revents = 0};

            ret = poll(&p, 1, 20);
            if ((ret <= 0) || !(p.revents & POLLIN)) {
                break;
            }
        }
    } else {
        rc = -EIO;
    }

    close(sock);
    return rc;
}

}  // namespace sdm
}  // namespace V2_0
}  // namespace livedisplay
}  // namespace mokee
}  // namespace vendor
