#
# Copyright (C) 2018 The MoKee Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/product_launched_with_o_mr1.mk)

# Inherit from m1872 device
$(call inherit-product, device/meizu/m1872/device.mk)

# Inherit some common MoKee stuff.
$(call inherit-product, vendor/mokee/config/common_full_phone.mk)

PRODUCT_PROPERTY_OVERRIDES += \
    ro.mk.maintainer=XiNGRZ

PRODUCT_NAME := mokee_m1872
PRODUCT_BRAND := Meizu
PRODUCT_DEVICE := m1872
PRODUCT_MANUFACTURER := Meizu
PRODUCT_MODEL := 16 X

PRODUCT_BUILD_PROP_OVERRIDES += \
    TARGET_DEVICE="16X" \
    PRODUCT_NAME="meizu_16X_CN" \
    PRIVATE_BUILD_DESC="meizu_16X_CN-user 8.1.0 OPM1.171019.026 1572938190 release-keys"

BUILD_FINGERPRINT := Meizu/meizu_16X_CN/16X:8.1.0/OPM1.171019.026/1572938190:user/release-keys
