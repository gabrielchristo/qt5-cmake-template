
# script by gabriel christo
# 2019

# versão minima do cmake 
# recomendado sempre usar a partir da 2.8
cmake_minimum_required(VERSION 3.12)

# permitindo somente modos debug e release
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE TYPE INTERNAL FORCE)

# nome do projeto
project(Generic_Qt_Project)

# incluir diretorio atual (path do cmakelists)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# desativando zero_check
set(CMAKE_SUPPRESS_REGENERATION true)

# automoc do qt
# necessario para criar codigo das classes com a macro Q_OBJECT
set(CMAKE_AUTOMOC ON)

# autorcc do qt para resources files
set(CMAKE_AUTORCC ON)

# autouic
# cria os ui_*.cpp referentes aos formularios de UI
set(CMAKE_AUTOUIC ON)

# opcoes de compilacao da linha de comando
# incluindo opcao de all warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# procurando libs do qt no sistema para posterior linkagem (verificar variaveis de ambiente)
# requerindo widgets automaticamente incluimos qtcore e qtgui
find_package(Qt5 REQUIRED Widgets)

# codigos fonte do projeto na variavel project_sources
set(project_sources
main.cxx
mainwindow.cxx
)

# headers do projeto na variavel project_headers
set(project_headers
mainwindow.h
)

# wrap do pre processador do moc
qt5_wrap_cpp(wrap_code ${project_headers})

# form files do projeto na variavel project_ui
set(project_ui
mainwindow.ui
)

# fazendo wraping dos arquivos do qt designer
qt5_wrap_ui(wrap_ui ${project_ui})

# pesquisando qt resources no diretorio atual e incluindo no projeto
file(GLOB_RECURSE Rsrcs *.qrc)
qt5_add_resources(Resources ${Rsrcs})

# criando executavel com arquivos do projeto
add_executable(${PROJECT_NAME}
${project_headers}
${project_sources}
${wrap_code}
${project_ui}
${wrap_ui}
${Resources}
)

# linkando as libs do qt com o executavel
target_link_libraries(${PROJECT_NAME}
Qt5::Widgets
Qt5::Core
Qt5::Gui
)


# estrutura de pastas do projeto (testado no visual studio somente)
SOURCE_GROUP("Headers" FILES
${project_headers}
)

SOURCE_GROUP("Sources" FILES
${project_sources}
)

SOURCE_GROUP("UI" FILES
${project_ui}
${wrap_ui}
)

SOURCE_GROUP("Resources" FILES
${Resources}
${Rsrcs}
)

SOURCE_GROUP("Wrap Files" FILES
${wrap_code}
)

# diretorio exclusivo para executavel
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/bin)
