CMAKE_MINIMUM_REQUIRED(VERSION 3.2.3 FATAL_ERROR)#cmake最小的要求

PROJECT(Serialize) #项目

#设置编辑的二进制文件输出路径
IF(${HOST_PLATFORM} STREQUAL PLATFORM_X86)
    IF(${HOST_OS} STREQUAL WINDOWS)
        SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/x86/windows")
        SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/x86/windows")
        SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/x86/windows")
    ENDIF()
ELSEIF(${HOST_PLATFORM} STREQUAL PLATFORM_X64)
    IF(${HOST_OS} STREQUAL WINDOWS)
        SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/x64/windows")
        SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/x64/windows")
        SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/x64/windows")
    ENDIF()
ENDIF()

#编译器选项设置
IF(${HOST_OS} STREQUAL WINDOWS)
    #warning C4819: The file ... code page (936).
    #warning C4996: ... use _CRT_SECURE_NO_WARNINGS.
    #warning C4800: forcing value to bool 'true' or 'false'
    #warning C4244 C4267: possible loss of data
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4819 /wd4996 /wd4800 /wd4244 /wd4267")
    set(CMAKE_CXX_STANDARD 17)
    #fatal error C1128: number of sections exceeded object file format limit: compile with /bigobj
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    #warning LNK4099: PDB '*.pdb' was not found
    #warning LNK4075: ignoring '/EDITANDCONTINUE' due to '/SAFESEH' specification
    #warning LNK4221: This object file does not define any previously undefined public symbols
    #warning LNK4098: defaultlib 'LIBCMTD' conflicts with use of other libs; use /NODEFAULTLIB:library
    #warning LNK4197: export 'XXX' specified multiple times
    SET(IGNORE_WARNING "/IGNORE:4099,4075,4221,4098,4197")
    SET(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    ${IGNORE_WARNING} ")
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${IGNORE_WARNING} ")
    SET(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} ${IGNORE_WARNING} ")
    SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${IGNORE_WARNING} ")
ENDIF()

#添加子目录
ADD_SUBDIRECTORY(TestJafSerialize)

IF(${HOST_OS} STREQUAL WINDOWS)
ELSEIF(${HOST_OS} STREQUAL REDHAT_LINUX)
ELSEIF(${HOST_OS} STREQUAL UBUNTU_16_04_LINUX)
ELSEIF(${HOST_OS} STREQUAL ARM_LINUX_FRERSCALE)
ELSEIF(${HOST_OS} STREQUAL AARCH64_UNKNOWN_LINUX)
ENDIF()
