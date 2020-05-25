set(INCLUDES 
    ${THIRD_PARTY_DIR}/glew/include)

set(LIBS 
    opengl32
    glfw
	glew
    glm
    imgui
    Platform
    Assert
    System)

cbt_build_project(NAME Dolce FOLDER Dolce TYPE STATIC INCLUDES "${INCLUDES}" LIBS "${LIBS}")

target_compile_definitions(Dolce PUBLIC -DGLM_FORCE_SILENT_WARNINGS)