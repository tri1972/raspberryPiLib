add_library(aquaBoardFunctions
  libRotaryEncoder.c
  BME280.c
  lib_mcp3425.c
  )

# インストール
install (TARGETS aquaBoardFunctions DESTINATION bin)
install (FILES libRotaryEncoder.h BME280.h lib_mcp3425.h DESTINATION include)
