ARCH = $(shell uname -m)

all:  OpenCVTest-$(ARCH) run

OpenCVTest-$(ARCH): OpenCVTest.cpp Makefile anglehelper.h ColorFilter.h EdgeDetection.h GetImage.h Settings.h stdafx.h ColorFilter.cpp GetImage.cpp OpenCVTest.cpp stdafx.cpp
	g++ -Wall -o $@ `pkg-config --cflags --libs opencv` *.cpp

run:
	./OpenCVTest-$(ARCH)

clean:
	rm -f OpenCVTest-$(ARCH)
