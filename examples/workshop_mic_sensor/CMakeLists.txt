include_directories(.)

file(GLOB_RECURSE SELF_CPP RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")
qi_create_lib(workshop_mic_sensor SHARED ${SELF_CPP})
qi_use_lib(workshop_mic_sensor self wdc)
qi_stage_lib(workshop_mic_sensor)