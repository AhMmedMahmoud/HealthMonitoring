cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
project(health_monitoring)

add_library(
   health_monitoring

   #manifest/manager/manifest_manager.h
   manifest/manager/manifest_manager.cpp

   #manifest/metadata/file_info.h
   manifest/metadata/file_info.cpp
   #manifest/metadata/delay_info.h
   manifest/metadata/delay_info.cpp
   #manifest/metadata/text_info.h
   manifest/metadata/text_info.cpp
   #manifest/metadata/manifest_headers.h
   #manifest/metadata/manifest_types.h

   file_writer/file_writer.cpp 
   #file_writer/file_writer.h  

   controllers/init/health_monitoring_init.cpp  
   #controllers/init/health_monitoring_init.h  
   #controllers/init/init_abstract.h

   controllers/run/health_monitoring_run.cpp  
   #controllers/run/health_monitoring_run.h  
   #controllers/run/run_abstract.h

   #controllers/shutdown/shutdown.h
   controllers/shutdown/shutdown.cpp  
   #controllers/shutdown/shutdown_returnType.h
)

################################################################################
##                                execuatables                                ##
################################################################################

add_executable(app_v1 app_v1.cpp)
target_link_libraries(app_v1 health_monitoring)

add_executable(app_v2 app_v2.cpp)
target_link_libraries(app_v2 health_monitoring)

add_executable(killer_v2 killer_v2.cpp)
target_link_libraries(killer_v2 health_monitoring)