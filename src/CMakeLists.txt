set(Dirs
    "../include"
)

set(Sources 
    "Towers.cpp"
)

add_library(src ${Sources})
target_include_directories(src PUBLIC ${Dirs})