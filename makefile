-include local.mk

ENV  ?= esp32dev
PORT ?=
BAUD ?= 115200

UPLOAD_PORT = $(if $(PORT),--upload-port $(PORT))
MONITOR_PORT = $(if $(PORT),--port $(PORT))

all: build

init:
	@test -f local.mk || echo "PORT ?=" > local.mk

build:
	pio run -e $(ENV)

upload:
	pio run -e $(ENV) -t upload $(UPLOAD_PORT)

monitor:
	pio device monitor -b $(BAUD) $(MONITOR_PORT)

flash: upload monitor

clean:
	pio run -e $(ENV) -t clean

ports:
	pio device list

compiledb:
	pio run -e $(ENV) -t compiledb

.PHONY: all init build upload monitor flash clean ports compiledb
