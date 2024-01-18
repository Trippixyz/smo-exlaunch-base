
.PHONY: all clean

BUILD_COUNTER_FILE := .build_counter
GAME_VERSION := 100

all: increment_counter
	cmake --toolchain=cmake/toolchain.cmake -S . -B build -DGAME_VERSION=$(GAME_VERSION) && $(MAKE) -C build

clean:
	rm -r build || true#

increment_counter:
	@if [ ! -f $(BUILD_COUNTER_FILE) ]; then echo 0 > $(BUILD_COUNTER_FILE); fi
	@echo $$(($$(cat $(BUILD_COUNTER_FILE)) + 1)) > $(BUILD_COUNTER_FILE)
	
