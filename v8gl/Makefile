
# TODO: support ${ARCHES.$MODE} builds

ARCHES = ia32 x64 arm
MODES = release debug
ANDROID_ARCHES = android_ia32 android_arm

ARCH = $(basename $@)

BUILDS = $(foreach mode,$(MODES),$(addsuffix .$(mode),$(ARCHES)))
ANDROID_BUILDS = $(foreach mode,$(MODES), $(addsuffix .$(mode),$(ANDROID_ARCHES)))

AR=ar
RANLIB=ranlib
CC=g++

STATIC_INCLUDES = -I../external/libpng/include \
	-I../external/v8/include

STATIC_LIBRARIES =  lib/$(ARCH)/libpng.a \
	lib/$(ARCH)/libv8_base.a \
	lib/$(ARCH)/libv8_nosnapshot.a

SHARED_LIBRARIES = -lpthread -lz -lm


#
# V8ADK parsing runtime
#

V8ADK_PROG_NAME = v8adk
V8ADK_CFLAGS = -D__V8ADK__

V8ADK_HEADER_FILES = src/v8adk/v8gl.h

V8ADK_SRC_FILES = src/v8adk/v8gl.cpp

V8ADK_SHARED_LIBRARIES =


#
# V8GL game runtime
#

V8GL_PROG_NAME = v8gl
V8GL_CFLAGS = -D__V8GL__ -D__WEBGL__

V8GL_HEADER_FILES = src/v8gl/v8gl.h \
	src/binding/gl.h \
	src/binding/webgl.h \
	src/binding/glu.h \
	src/binding/glut.h

V8GL_SRC_FILES = src/v8gl/v8gl.cpp \
	src/binding/gl.cpp \
	src/binding/webgl.cpp \
	src/binding/glu.cpp \
	src/binding/glut.cpp

V8GL_SHARED_LIBRARIES = -lglut -lGLU -lGL





HEADER_FILES = src/lib/fs.h \
	src/api/arraybuffer.h \
	src/api/console.h \
	src/api/script.h \
	src/api/text.h \
	src/api/texture.h

SRC_FILES = src/lib/fs.cpp \
	src/api/arraybuffer.cpp \
	src/api/console.cpp \
	src/api/navigator.cpp \
	src/api/script.cpp \
	src/api/text.cpp \
	src/api/texture.cpp


V8ADK_SRC_FILES += $(SRC_FILES)
V8GL_SRC_FILES += $(SRC_FILES)

V8ADK_LDFLAGS = $(STATIC_LIBRARIES) $(SHARED_LIBRARIES) $(V8ADK_SHARED_LIBRARIES)
V8GL_LDFLAGS = $(STATIC_LIBRARIES) $(SHARED_LIBRARIES) $(V8GL_SHARED_LIBRARIES)


LIB_ARCH = $(basename $(build))
V8GL_ROOT = $(shell pwd)
OUTDIR = ./out/$@

clean:
	rm -rf ./out/
	rm -rf ./lib/
	rm ./src/js/interval.h
	rm ./src/js/timeout.h

all: $(MODES)

# ADK_PATH=$(cd "$(dirname "$0")"; pwd);

dependencies: must-set-LYCHEEJS_ROOT must-set-LIBPNG_PATH must-set-LIBV8_PATH
	rm -rf lib/raw
	mkdir -p lib/raw
	cd $(LYCHEEJS_ROOT) && xxd -i "lychee/core.js" $(V8GL_ROOT)/lib/raw/lychee_core_js.h
	cd $(LYCHEEJS_ROOT) && xxd -i "lychee/Builder.js" $(V8GL_ROOT)/lib/raw/lychee_Builder_js.h
	cd $(LYCHEEJS_ROOT) && xxd -i "lychee/platform/v8gl/Preloader.js" $(V8GL_ROOT)/lib/raw/lychee_Preloader_js.h
	rm -rf lib/$(LIB_ARCH)
	mkdir -p lib/$(LIB_ARCH)
	cp $(LIBPNG_PATH)/libpng.a $(V8GL_ROOT)/lib/$(LIB_ARCH)/libpng.a
	cp $(LIBV8_PATH)/libv8_base.a $(V8GL_ROOT)/lib/$(LIB_ARCH)/libv8_base.a
	cp $(LIBV8_PATH)/libv8_nosnapshot.a $(V8GL_ROOT)/lib/$(LIB_ARCH)/libv8_nosnapshot.a
	cd src/ && xxd -i "js/interval.js" "js/interval.h"
	cd src/ && xxd -i "js/timeout.js" "js/timeout.h"


$(BUILDS): $(HEADER_FILES)
	rm -rf $(OUTDIR)
	mkdir -p $(OUTDIR)
	$(CC) -Wall $(V8ADK_CFLAGS) $(STATIC_INCLUDES) src/v8adk/main.cpp $(V8ADK_SRC_FILES) -o $(OUTDIR)/v8adk $(V8ADK_LDFLAGS)
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/v8gl/main.cpp $(V8GL_SRC_FILES) -o $(OUTDIR)/v8gl $(V8GL_LDFLAGS)
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/v8gl/v8gl.cpp -c -o $(OUTDIR)/v8gl_v8gl.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/binding/gl.cpp -c -o $(OUTDIR)/binding_gl.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/binding/webgl.cpp -c -o $(OUTDIR)/binding_webgl.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/binding/glu.cpp -c -o $(OUTDIR)/binding_glu.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/binding/glut.cpp -c -o $(OUTDIR)/binding_glut.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/lib/fs.cpp -c -o $(OUTDIR)/lib_fs.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/arraybuffer.cpp -c -o $(OUTDIR)/api_arraybuffer.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/console.cpp -c -o $(OUTDIR)/api_console.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/navigator.cpp -c -o $(OUTDIR)/api_navigator.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/script.cpp -c -o $(OUTDIR)/api_script.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/text.cpp -c -o $(OUTDIR)/api_text.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/texture.cpp -c -o $(OUTDIR)/api_texture.o
	$(AR) rc $(OUTDIR)/libv8gl.a $(OUTDIR)/v8gl_v8gl.o \
	$(OUTDIR)/binding_gl.o $(OUTDIR)/binding_webgl.o \
	$(OUTDIR)/binding_glu.o $(OUTDIR)/binding_glut.o \
	$(OUTDIR)/lib_fs.o \
	$(OUTDIR)/api_arraybuffer.o \
	$(OUTDIR)/api_console.o $(OUTDIR)/api_navigator.o $(OUTDIR)/api_script.o \
	$(OUTDIR)/api_text.o $(OUTDIR)/api_texture.o
	$(RANLIB) $(OUTDIR)/libv8gl.a


must-set-LYCHEEJS_ROOT:
ifndef LYCHEEJS_ROOT
	$(error LYCHEEJS_ROOT must be set)
endif

must-set-LIBPNG_PATH:
ifndef LIBPNG_PATH
	$(error LIBPNG_PATH must be set)
endif

must-set-LIBV8_PATH:
ifndef LIBV8_PATH
	$(error LIBV8_PATH must be set)
endif

$(ANDROID_ARCHES): $(addprefix $$@.,$(MODES))

$(ANDROID_BUILDS): must-set-ANDROID_NDK_ROOT Makefile.android
	mkdir -p $(OUTDIR)
	@$(MAKE) -f Makefile.android $(subst .,,$(suffix $@)) \
		ARCH="$(basename $@)" \
		OUTDIR="$(OUTDIR)"

must-set-ANDROID_NDK_ROOT:
ifndef ANDROID_NDK_ROOT
	$(error ANDROID_NDK_ROOT must be set)
endif
 
