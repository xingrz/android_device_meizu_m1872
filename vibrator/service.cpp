/*
 * Copyright (C) 2019 The Android Open Source Project
 * Copyright (C) 2019-2020 The MoKee Open Source Project
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
#define LOG_TAG "android.hardware.vibrator@1.3-service.m1872"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>

#include "Vibrator.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::hardware::vibrator::V1_3::IVibrator;
using android::hardware::vibrator::V1_3::implementation::Vibrator;

int main() {
    vibrator_device_t *vib_device;
    const hw_module_t *hw_module = nullptr;

    int ret = hw_get_module(VIBRATOR_HARDWARE_MODULE_ID, &hw_module);
    if (ret == 0) {
        ret = vibrator_open(hw_module, &vib_device);
        if (ret != 0) {
            LOG(ERROR) << "vibrator_open failed: " << ret;
            return ret;
        }
    } else {
        LOG(ERROR) << "hw_get_module " << VIBRATOR_HARDWARE_MODULE_ID
                   << " failed: " << ret;
        return ret;
    }

    android::sp<IVibrator> vibrator = new Vibrator(vib_device);

    configureRpcThreadpool(1, true);

    android::status_t status =  vibrator->registerAsService();

    if (status != android::OK) {
        return status;
    }

    joinRpcThreadpool();

    return 1;
}
