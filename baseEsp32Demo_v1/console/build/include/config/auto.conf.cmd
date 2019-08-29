deps_config := \
	D:\works\projects\esp32\IDF\esp-idf\components\app_trace\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\aws_iot\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\bt\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\driver\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\esp32\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\esp_adc_cal\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\esp_event\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\esp_http_client\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\esp_http_server\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\ethernet\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\fatfs\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\freemodbus\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\freertos\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\heap\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\libsodium\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\log\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\lwip\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\mbedtls\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\mdns\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\mqtt\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\nvs_flash\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\openssl\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\pthread\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\spi_flash\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\spiffs\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\tcpip_adapter\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\unity\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\vfs\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\wear_levelling\Kconfig \
	D:\works\projects\esp32\IDF\esp-idf\components\app_update\Kconfig.projbuild \
	D:\works\projects\esp32\IDF\esp-idf\components\bootloader\Kconfig.projbuild \
	D:\works\projects\esp32\IDF\esp-idf\components\esptool_py\Kconfig.projbuild \
	D:\works\projects\esp32\project\console\main\Kconfig.projbuild \
	D:\works\projects\esp32\IDF\esp-idf\components\partition_table\Kconfig.projbuild \
	/d/works/projects/esp32/IDF/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_TARGET)" "esp32"
include/config/auto.conf: FORCE
endif
ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
