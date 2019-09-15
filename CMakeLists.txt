
cmake_minimum_required(VERSION 3.9.5)
 
project(ReadDICOMImage)
 
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})
if (ITKVtkGlue_LOADED)
  find_package(VTK REQUIRED)
  include(${VTK_USE_FILE})
else()
  find_package(ItkVtkGlue REQUIRED)
  include(${ItkVtkGlue_USE_FILE})
  set(Glue ItkVtkGlue)
endif()
 
add_executable(ReadDICOMImage MACOSX_BUNDLE ReadDICOMImage.cxx)
target_link_libraries(ReadDICOMImage
  ${Glue}  ${VTK_LIBRARIES} ${ITK_LIBRARIES})
