set(INCLUDES 
    ${THIRD_PARTY_DIR}/glew/include)

set(LIBS 
    opengl32
    glfw
	glew
    Platform
    Assert)

build_library(NAME Dolce FOLDER Dolce TYPE STATIC INCLUDES "${INCLUDES}" LIBS "${LIBS}")