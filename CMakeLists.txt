cmake_minimum_required(VERSION 3.0.0)
project(fisianito VERSION 0.1.0)

include(CTest)
include(FetchContent)
find_package(PostgreSQL REQUIRED)
FetchContent_Declare(
   taocpp-taopq
   GIT_REPOSITORY https://github.com/taocpp/taopq
   GIT_TAG main
)
FetchContent_MakeAvailable(taocpp-taopq)

enable_testing()
IF (WIN32)
# Windows specific config
  # Include local sfml cmake config
  set(SFML_DIR "C:/dev/SFML-2.5.1/lib/cmake/SFML/")
ENDIF()

find_package(SFML
  COMPONENTS
  system window graphics audio REQUIRED)

include_directories(include)
add_executable(fisianito
  include/Game/Animation.hpp
  include/Game/Bullet.hpp
  include/Game/Bullets.hpp
  include/Game/Enemy.hpp
  include/Game/EnemyManager.hpp
  include/Game/Entity.hpp
  include/Game/Frame.hpp
  include/Game/Game.hpp
  include/Game/GameFonts.hpp
  include/Game/GameOver.hpp
  include/Game/GameTextures.hpp
  include/Game/Menu.hpp
  include/Game/Maps.hpp
  include/Game/Platform.hpp
  include/Game/Player.hpp
  include/Game/Score.hpp
  include/Game/ScoreWindow.hpp
  include/DataStructures/EntityNode.hpp
  include/DataStructures/BulletNode.hpp
  include/DataStructures/ScoreRecordNode.hpp
  include/DataStructures/TextNode.hpp
  include/api/DataBase.hpp        
  src/Game/Animation.cpp
  src/Game/Bullet.cpp
  src/Game/Bullets.cpp
  src/Game/Enemy.cpp
  src/Game/EnemyManager.cpp
  src/Game/Entity.cpp
  src/Game/Game.cpp
  src/Game/GameFonts.cpp
  src/Game/GameOver.cpp
  src/Game/GameTextures.cpp
  src/Game/main.cpp
  src/Game/Maps.cpp
  src/Game/Menu.cpp
  src/Game/Platform.cpp
  src/Game/Player.cpp
  src/Game/Score.cpp
  src/Game/ScoreWindow.cpp
  src/api/DataBase.cpp

)

target_link_libraries(fisianito sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
target_link_libraries(fisianito taocpp::taopq)
set_property(TARGET fisianito PROPERTY CXX_STANDARD 17)
