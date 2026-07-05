# Install script for directory: /c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so.1.0.20260705"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE SHARED_LIBRARY FILES
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/libncnn.so.1.0.20260705"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/libncnn.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so.1.0.20260705"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE SHARED_LIBRARY FILES "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/libncnn.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libncnn.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ncnn" TYPE FILE FILES
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/allocator.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/benchmark.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/blob.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/c_api.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/command.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/cpu.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/datareader.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/expression.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/gpu.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/layer.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/layer_shader_type.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/layer_type.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/mat.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/modelbin.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/net.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/option.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/paramdict.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/pipeline.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/pipelinecache.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/simpleocv.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/simpleomp.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/simplestl.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/simplemath.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/simplevk.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/source/src/vulkan_header_fix.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/ncnn_export.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/layer_shader_type_enum.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/layer_type_enum.h"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/platform.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/ncnn/ncnn.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/ncnn/ncnn.cmake"
         "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/CMakeFiles/Export/lib64/cmake/ncnn/ncnn.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/ncnn/ncnn-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/ncnn/ncnn.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/ncnn" TYPE FILE FILES "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/CMakeFiles/Export/lib64/cmake/ncnn/ncnn.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/ncnn" TYPE FILE FILES "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/CMakeFiles/Export/lib64/cmake/ncnn/ncnn-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/ncnn" TYPE FILE FILES
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/ncnnConfig.cmake"
    "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/ncnnConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/pkgconfig" TYPE FILE FILES "/c/Users/stwz13/catedit-aurora/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug/source/src/ncnn.pc")
endif()

