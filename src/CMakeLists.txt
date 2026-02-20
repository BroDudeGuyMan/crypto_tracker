add_subdirectory(api)
add_subdirectory(ui)
add_subdirectory(core)
add_subdirectory(app)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
	PRIVATE
	 main.cpp
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
	 application
)
