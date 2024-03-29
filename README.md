*Note: This library is no longer maintained by Arduino and has therefore been archived. If you are interested in maintaining it, please write an email to support@arduino.cc.*

Arduino_CRC32
=============

[![Check Arduino status](https://github.com/arduino-libraries/Arduino_CRC32/actions/workflows/check-arduino.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_CRC32/actions/workflows/check-arduino.yml)
[![Compile Examples status](https://github.com/arduino-libraries/Arduino_CRC32/actions/workflows/compile-examples.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_CRC32/actions/workflows/compile-examples.yml)
[![Spell Check status](https://github.com/arduino-libraries/Arduino_CRC32/actions/workflows/spell-check.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_CRC32/actions/workflows/spell-check.yml)

This Arduino library provides a simple interface to perform checksum calculations utilizing the CRC-32 algorithm. The C code for the CRC-32 algorithm was generated using [PyCRC](https://pycrc.org) with the predefined [crc-32 model](https://pycrc.org/models.html#crc-32).

## Usage

```C++
#include <Arduino_CRC32.h>
/* ... */
Arduino_CRC32 crc32;
/* ... */
char const str[] = "Hello CRC32 ;)";
uint32_t const crc32_res = crc32.calc((uint8_t const *)str, strlen(str));
```
