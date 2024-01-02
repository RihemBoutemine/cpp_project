cmake_minimum_required(VERSION 3.0.0)
project(SDLTEST VERSION 0.1.0 LANGUAGES C CXX)

# Spécifiez le répertoire de recherche de SDL2
set(SDL2_DIR ./)

# Copiez les fichiers nécessaires
file(COPY bin/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY images/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)

# Listez vos fichiers source
set(SRCS
        main.cpp
        framework.cpp
        asteroid.cpp
        Missile.cpp  # Correction ici
        FlyingObject.cpp
        Spaceship.cpp
)

# Listez vos fichiers d'en-tête
set(HEADERS
        framework.hpp
        asteroid.hpp
        Missile.hpp  # Correction ici
        FlyingObject.hpp
        Spaceship.hpp
        Model.cpp
        Model.hpp
        View.cpp
        View.hpp
        controller.cpp
        controller.hpp
)

# Recherchez SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Créez l'exécutable
add_executable(SDLTEST ${SRCS} ${HEADERS})

# Liez la bibliothèque SDL2 à l'exécutable
target_link_libraries(SDLTEST ${SDL2_LIBRARIES})
