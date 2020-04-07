set(INCLUDES 
    ${GLEW_PROJECT_DIR}/include)

set(LIBS 
    opengl32
    glfw
	glew
    Platform
    Assert)

build_library(NAME Dolce FOLDER Dolce TYPE STATIC INCLUDES "${INCLUDES}" LIBS "${LIBS}")