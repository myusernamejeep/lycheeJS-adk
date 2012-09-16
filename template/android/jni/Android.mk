
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

LOCAL_MODULE    := v8_base
LOCAL_SRC_FILES := ../lib/libv8_base.a

include $(PREBUILT_STATIC_LIBRARY)



# V8 NoSnapshot

include $(CLEAR_VARS)

LOCAL_MODULE    := v8_nosnapshot
LOCAL_SRC_FILES := ../lib/libv8_nosnapshot.a

include $(PREBUILT_STATIC_LIBRARY)



# PNG library

include $(CLEAR_VARS)

LOCAL_MODULE    := libpng
LOCAL_SRC_FILES := ../lib/libpng.a

include $(PREBUILT_STATIC_LIBRARY)


# $(call import-module, libpng);


# V8GL

include $(CLEAR_VARS)

LOCAL_MODULE     := v8gl-runtime

LOCAL_SRC_FILES  := main.c \
	../src/v8gl/v8gl.cpp \
	../src/v8gl/path.cpp \
	../src/api/console.cpp \
	../src/api/script.cpp \
	../src/api/text.cpp

LOCAL_C_INCLUDES := ../external/v8/include \
	../external/libpng/include

LOCAL_CPPFLAGS   := -D__ANDROID__
LOCAL_LDLIBS     := -llog -landroid -lEGL -lGLESv1_CM -lGLESv2
LOCAL_STATIC_LIBRARIES := android_native_app_glue v8_base v8_nosnapshot libpng

# LOCAL_EXPORT_CPPFLAGS := -D__ANDROID__

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
