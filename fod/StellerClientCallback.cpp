/*
 * Copyright (C) 2020 The MoKee Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#define LOG_TAG "StellerClientCallback"

#include "StellerClientCallback.h"

#include <android-base/logging.h>

namespace vendor {
namespace mokee {
namespace biometrics {
namespace fingerprint {
namespace inscreen {
namespace V1_0 {
namespace implementation {

StellerClientCallback::StellerClientCallback() {
}

Return<void> StellerClientCallback::atuStatus(int32_t ret) {
    LOG(INFO) << "atuStatus: " << ret;
    return Void();
}

Return<void> StellerClientCallback::hbmCtrl(int32_t ret) {
    LOG(INFO) << "hbmCtrl: " << ret;
    return Void();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace inscreen
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace mokee
}  // namespace vendor
