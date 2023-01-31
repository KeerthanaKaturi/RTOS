# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/batch-1/esp/esp-idf/components/bootloader/subproject"
  "/home/batch-1/Desktop/Keerthana/rtos/priority/build/bootloader"
  "/home/batch-1/Desktop/Keerthana/rtos/priority/build/bootloader-prefix"
  "/home/batch-1/Desktop/Keerthana/rtos/priority/build/bootloader-prefix/tmp"
  "/home/batch-1/Desktop/Keerthana/rtos/priority/build/bootloader-prefix/src/bootloader-stamp"
  "/home/batch-1/Desktop/Keerthana/rtos/priority/build/bootloader-prefix/src"
  "/home/batch-1/Desktop/Keerthana/rtos/priority/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/batch-1/Desktop/Keerthana/rtos/priority/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/batch-1/Desktop/Keerthana/rtos/priority/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
