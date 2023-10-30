project(mylibry)
add_library(mylibry constraints.c insertion_operator.c precalculation.c ridesharing.c searching_and_sorting.c segment_tree.c time_functions.c tools.c)
target_include_directories(mylibry PUBLIC 
	${PROJECT_SOURCE_DIR}/include
)
