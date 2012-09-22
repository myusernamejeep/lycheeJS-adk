
# Note to self:
# all relative include paths are relative
# to the project root folder and
# NOT relative to this file.
#
# LOCAL_C_INCLUDE := $(LOCAL_PATH)/../file.txt
# 
# will result in:
#
# -Ijni/../file.txt
#

LOCAL_PATH := $(call my-dir)



# V8 Base

include $(CLEAR_VARS)

LOCAL_MODULE    := libv8_base
LOCAL_SRC_FILES := ../lib/libv8_base.a

include $(PREBUILT_STATIC_LIBRARY)



# V8 NoSnapshot

include $(CLEAR_VARS)

LOCAL_MODULE    := libv8_nosnapshot
LOCAL_SRC_FILES := ../lib/libv8_nosnapshot.a

include $(PREBUILT_STATIC_LIBRARY)



# PNG library

include $(CLEAR_VARS)

LOCAL_MODULE    := libpng
LOCAL_SRC_FILES := ../lib/libpng.a

include $(PREBUILT_STATIC_LIBRARY)



# V8GL library

include $(CLEAR_VARS)

LOCAL_MODULE    := libv8gl
LOCAL_SRC_FILES := ../lib/libv8gl.a

include $(PREBUILT_STATIC_LIBRARY)


# Android Runtime

include $(CLEAR_VARS)

LOCAL_MODULE     := runtime

LOCAL_SRC_FILES  := main.c \
	wrapper.cpp

LOCAL_C_INCLUDES := ../lib/include/libpng \
	../lib/include/libv8 \
	../lib/include/libv8gl

# LOCAL_CPPFLAGS   := -D__ANDROID__
# LOCAL_EXPORT_CPPFLAGS := -D__ANDROID__
LOCAL_LDLIBS     := -llog -landroid -lEGL -lGLESv2
LOCAL_STATIC_LIBRARIES := android_native_app_glue libpng libv8_base libv8_nosnapshot libv8gl


include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)

