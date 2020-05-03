TARGET = Soulless
OBJS = src/main.o \
src/state_manager.o \
src/states/intro_state.o \

INCDIR = $(PSPPATH)/include lib/Stardust-Engine/include lib/Stardust-Engine/libs/include 

CFLAGS = -G0 -mpreferred-stack-boundary=4 -ffast-math -fno-rtti -fno-exceptions 
CXXFLAGS = -std=gnu++17
ASFLAGS = $(CFLAGS)

BUILD_PRX = 1
PSP_FW_VERSION=500
PSP_LARGE_MEMORY = 1 #PHAT SUPPORT! Our app isn't that big! 

LDFLAGS =
# -losl -lmmio -lpng

LIBDIR = lib/Stardust-Engine/lib lib/Stardust-Engine/libs/lib
LIBS    = -lstardust -ljson -lintraFont -lpng -lpspmath -lpspwlan -lpspnet_adhocmatching -lpspnet_adhoc -lpspnet_adhocctl -lpspusb -lpspusbstor -lpspmp3 -lmad -lpspvram -lpspreg -lpspumd -lpsphprm -lpspaudiolib -lpspaudio -lmikmod -lpspaudiocodec -lpng -lz -lpspgum -lpspgu -lstdc++ -lpsprtc -lpspctrl -lm -lpspvfpu -lpspsdk -lpsppower -lpsphttp -ljpeg -lpspssl
# LIBS = -lpspaudiolib -lpspaudio -lmikmod -lpspaudiocodec -lpng -lz -lpspgum -lpspgu -lstdc++ -lpsprtc -lpspctrl -lm -lpspvfpu -lpspsdk -lpsppower -lpsphttp

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_ICON= ICON0.png
PSP_EBOOT_TITLE = Soulless

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
