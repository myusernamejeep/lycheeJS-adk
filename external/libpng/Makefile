
# TODO: support ${ARCHES.$MODE} builds

ARCHES = ia32 x64 arm
MODES = release debug
ANDROID_ARCHES = android_ia32 android_arm

BUILDS = $(foreach mode,$(MODES),$(addsuffix .$(mode),$(ARCHES)))
ANDROID_BUILDS = $(foreach mode,$(MODES), $(addsuffix .$(mode),$(ANDROID_ARCHES)))


AR=ar
CC=gcc
RANLIB=ranlib
CFLAGS=-W -Wall -O3 -funroll-loops -Iinclude/
LDFLAGS=


HEADERS = include/png.h \
	include/pngconf.h \
	include/pnglibconf.h \
	include/pngpriv.h \
	include/pngstruct.h \
	include/pnginfo.h \
	include/pngdebug.h

OBJECTS = $(OUTDIR)/png.o \
	$(OUTDIR)/pngset.o \
	$(OUTDIR)/pngget.o \
	$(OUTDIR)/pngrutil.o \
	$(OUTDIR)/pngtrans.o \
	$(OUTDIR)/pngwutil.o \
	$(OUTDIR)/pngread.o \
	$(OUTDIR)/pngrio.o \
	$(OUTDIR)/pngwio.o \
	$(OUTDIR)/pngwrite.o \
	$(OUTDIR)/pngrtran.o \
	$(OUTDIR)/pngwtran.o \
	$(OUTDIR)/pngmem.o \
	$(OUTDIR)/pngerror.o \
	$(OUTDIR)/pngpread.o

OUTDIR = ./out/$@

clean:
	rm -rf ./out/

all: $(MODES)

# release debug:
$(BUILDS): $(HEADERS)
	rm -rf $(OUTDIR)
	mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/png.o src/png.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngset.o src/pngset.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngget.o src/pngget.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngrutil.o src/pngrutil.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngtrans.o src/pngtrans.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngwutil.o src/pngwutil.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngread.o src/pngread.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngrio.o src/pngrio.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngwio.o src/pngwio.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngwrite.o src/pngwrite.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngrtran.o src/pngrtran.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngwtran.o src/pngwtran.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngmem.o src/pngmem.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngerror.o src/pngerror.c $(LDFLAGS)
	$(CC) $(CFLAGS) -c -o $(OUTDIR)/pngpread.o src/pngpread.c $(LDFLAGS)
	$(AR) rc $(OUTDIR)/libpng.a $(OBJECTS)
	$(RANLIB) $(OUTDIR)/libpng.a


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

