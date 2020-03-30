Arduino_CRC32
=============

This Arduino library provides a simple interface to perform checksum calculations utilizing the CRC-32 algorithm. The C code for the CRC-32 algorithm was generated using [PyCRC](https://pycrc.org) with the predefined [crc-32 model](https://pycrc.org/models.html#crc-32).

== License ==

Copyright (c) 2020 Arduino.  All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA


## Usage

```C++
#include <Arduino_CRC32.h>
/* ... */
Arduino_CRC32 crc32;
/* ... */
char const str[] = "Hello CRC32 ;)";
uint32_t const crc32_res = crc32.calc((uint8_t const *)str, strlen(str));
```
