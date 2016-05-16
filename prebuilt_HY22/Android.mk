LOCAL_PATH := $(call my-dir)
PREBUILT_DIR_PATH := $(LOCAL_PATH)

ifeq ($(call is-board-platform,msm8916),true)
ifeq ($(strip $(TARGET_BOARD_SUFFIX)),_64)
  -include $(LOCAL_PATH)/target/product/msm8916_64/Android.mk
endif
endif

-include $(sort $(wildcard $(PREBUILT_DIR_PATH)/*/*/Android.mk))
