
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
# V8GL game runtime
#

V8GL_PROG_NAME = v8gl
V8GL_CFLAGS = -D__V8GL__ -D__WEBGL__

V8GL_HEADER_FILES = src/v8gl.h \
	src/binding/gl.h \
	src/binding/webgl.h \
	src/binding/glu.h \
	src/binding/glut.h \
	src/lib/fs.h \
	src/lib/os.h \
	src/api/arraybuffer.h \
	src/api/script.h \
	src/api/text.h \
	src/api/texture.h
 

V8GL_SRC_FILES = src/v8gl.cpp \
	src/binding/gl.cpp \
	src/binding/webgl.cpp \
	src/binding/glu.cpp \
	src/binding/glut.cpp \
	src/lib/fs.cpp \
	src/lib/os.cpp \
	src/api/arraybuffer.cpp \
	src/api/navigator.cpp \
	src/api/script.cpp \
	src/api/text.cpp \
	src/api/texture.cpp
 

V8GL_SHARED_LIBRARIES = -lglut -lGLU -lGL

V8GL_LDFLAGS = $(STATIC_LIBRARIES) $(SHARED_LIBRARIES) $(V8GL_SHARED_LIBRARIES)


LIB_ARCH = $(basename $(build))
V8GL_ROOT = $(shell pwd)
OUTDIR = ./out/$@

clean:
	rm -rf ./out/
	rm ./src/js/console.h
	rm ./src/js/interval.h
	rm ./src/js/timeout.h

all: $(MODES)

dependencies: must-set-LIBPNG_PATH must-set-LIBV8_PATH
	rm -rf lib/raw
	mkdir -p lib/raw
	rm -rf lib/$(LIB_ARCH)
	mkdir -p lib/$(LIB_ARCH)
	cp $(LIBPNG_PATH)/libpng.a $(V8GL_ROOT)/lib/$(LIB_ARCH)/libpng.a
	cp $(LIBV8_PATH)/libv8_base.a $(V8GL_ROOT)/lib/$(LIB_ARCH)/libv8_base.a
	cp $(LIBV8_PATH)/libv8_nosnapshot.a $(V8GL_ROOT)/lib/$(LIB_ARCH)/libv8_nosnapshot.a

builtin-js:
	cd src/ && xxd -i "js/console.js" "js/console.h"
	cd src/ && xxd -i "js/interval.js" "js/interval.h"
	cd src/ && xxd -i "js/timeout.js" "js/timeout.h"


$(BUILDS): builtin-js $(HEADER_FILES)
	rm -rf $(OUTDIR)
	mkdir -p $(OUTDIR)
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/main.cpp $(V8GL_SRC_FILES) -o $(OUTDIR)/v8gl $(V8GL_LDFLAGS)
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/v8gl.cpp -c -o $(OUTDIR)/v8gl.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/binding/gl.cpp -c -o $(OUTDIR)/binding_gl.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/binding/webgl.cpp -c -o $(OUTDIR)/binding_webgl.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/binding/glu.cpp -c -o $(OUTDIR)/binding_glu.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/binding/glut.cpp -c -o $(OUTDIR)/binding_glut.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/lib/fs.cpp -c -o $(OUTDIR)/lib_fs.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/lib/os.cpp -c -o $(OUTDIR)/lib_os.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/arraybuffer.cpp -c -o $(OUTDIR)/api_arraybuffer.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/navigator.cpp -c -o $(OUTDIR)/api_navigator.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/script.cpp -c -o $(OUTDIR)/api_script.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/text.cpp -c -o $(OUTDIR)/api_text.o
	$(CC) -Wall $(V8GL_CFLAGS) $(STATIC_INCLUDES) src/api/texture.cpp -c -o $(OUTDIR)/api_texture.o
	$(AR) rc $(OUTDIR)/libv8gl.a $(OUTDIR)/v8gl.o \
	$(OUTDIR)/binding_gl.o $(OUTDIR)/binding_webgl.o \
	$(OUTDIR)/binding_glu.o $(OUTDIR)/binding_glut.o \
	$(OUTDIR)/lib_fs.o $(OUTDIR)/lib_os.o \
	$(OUTDIR)/api_arraybuffer.o \
	$(OUTDIR)/api_navigator.o $(OUTDIR)/api_script.o \
	$(OUTDIR)/api_text.o $(OUTDIR)/api_texture.o
	$(RANLIB) $(OUTDIR)/libv8gl.a


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
 
