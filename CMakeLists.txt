cmake_minimum_required(VERSION 3.30.1)

project(ip_filter VERSION 0.0.${PATCH_VERSION})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ip_filter ip_filter.cpp)

# Явно указываем каталог для установки исполняемого файла
install(TARGETS ip_filter RUNTIME DESTINATION bin)

include(CPack)

# Дополнительные настройки CPack для успешного создания пакета
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Seleznev Mikhail")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}-Linux")

# Явно указываем каталог установки, который CPack использует
set(CPACK_INSTALL_PREFIX "/usr")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "IP Filter Application")
set(CPACK_PACKAGE_CONTACT "seleznev.mikle@gmail.com")
