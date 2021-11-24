cmake_minimum_required(VERSION 3.15)

# set the project name
# project(PhotoBatch)

# ------- or --------
# set the project name and version
project(PhotoBatch VERSION 1.0)

# add the executable
add_executable(PhotoBatch
	"PhotoBatch.cpp" 
	"ArgumentParser.h" 
	"ArgumentParser.cpp"
	"Utils.h"
	"Utils.cpp"
)