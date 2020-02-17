/*
 * Copyright (C) 2019 The LineageOS Project
 * Copyright (C) 2020 The MoKee Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef VENDOR_MOKEE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_0_FINGERPRINTINSCREEN_H
#define VENDOR_MOKEE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_0_FINGERPRINTINSCREEN_H

#include <vendor/mokee/biometrics/fingerprint/inscreen/1.0/IFingerprintInscreen.h>
#include <vendor/synaptics/fingerprint/interfaces/extensions/1.0/ISteller.h>
#include <vendor/synaptics/fingerprint/interfaces/extensions/1.0/IStellerClientCallback.h>

namespace vendor {
namespace mokee {
namespace biometrics {
namespace fingerprint {
namespace inscreen {
namespace V1_0 {
namespace implementation {

using ::android::sp;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::hidl_vec;

using ::vendor::synaptics::fingerprint::interfaces::extensions::V1_0::ISteller;
using ::vendor::synaptics::fingerprint::interfaces::extensions::V1_0::IStellerClientCallback;

class FingerprintInscreen : public IFingerprintInscreen {
  public:
    FingerprintInscreen();

    Return<int32_t> getPositionX() override;
    Return<int32_t> getPositionY() override;
    Return<int32_t> getSize() override;
    Return<void> onStartEnroll() override;
    Return<void> onFinishEnroll() override;
    Return<void> onPress() override;
    Return<void> onRelease() override;
    Return<void> onShowFODView() override;
    Return<void> onHideFODView() override;
    Return<bool> handleAcquired(int32_t acquiredInfo, int32_t vendorCode) override;
    Return<bool> handleError(int32_t error, int32_t vendorCode) override;
    Return<void> setLongPressEnabled(bool enabled) override;
    Return<int32_t> getDimAmount(int32_t cur_brightness) override;
    Return<bool> shouldBoostBrightness() override;
    Return<void> setCallback(const sp<IFingerprintInscreenCallback>& callback) override;

  private:
    sp<ISteller> mSteller;
    sp<IStellerClientCallback> mStellerClientCallback;

    bool mFingerPressed;

    void notifyHal(int32_t status, int32_t data);
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace inscreen
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace mokee
}  // namespace vendor

#endif  // VENDOR_MOKEE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_0_FINGERPRINTINSCREEN_H
