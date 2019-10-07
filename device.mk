#
# Copyright (C) 2020 The MoKee Open Source Project
#
# SPDX-License-Identifier: Apache-2.0
#

$(call inherit-product, vendor/meizu/m1872/m1872-vendor.mk)

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
    $(LOCAL_PATH)/overlay \
    $(LOCAL_PATH)/overlay-mokee

# Boot animation
TARGET_SCREEN_HEIGHT := 2160
TARGET_SCREEN_WIDTH := 1080

 # Vibrator
 PRODUCT_PACKAGES += \
    android.hardware.vibrator@1.3-service.m1872

# Inherit from sdm710-common
$(call inherit-product, device/meizu/sdm710-common/common.mk)
