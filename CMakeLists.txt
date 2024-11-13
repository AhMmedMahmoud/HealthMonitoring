cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
project(health_monitoring)

add_library(
   health_monitoring

   manifest/manager/manifest_manager.h
   manifest/manager/manifest_manager.cpp

   manifest/metadata/file_info.h
   manifest/metadata/file_info.cpp
   
   manifest/metadata/delay_info.h
   manifest/metadata/delay_info.cpp
   
   manifest/metadata/manifest_headers.h
   manifest/metadata/manifest_types.h

   file_writer/file_writer.cpp 
   file_writer/file_writer.h  

   manifest/metadata/text_info.h
   manifest/metadata/text_info.cpp
)

################################################################################
##                                execuatables                                ##
################################################################################

add_executable(app app.cpp)
target_link_libraries(app health_monitoring)