.PHONY: $(MAKECMDGOALS)

export REPO_DIR=${PWD}
export BUILD_DIR=${REPO_DIR}/cxx/cmake-build-debug
export SOURCE_DIR=${REPO_DIR}/cxx
export CMAKE_PREFIX_DIR=${REPO_DIR}/cmake_prefix
export DEP_DIR=${REPO_DIR}/vendor
export CXX=clang++

help:
	echo "Check Makefile"

dep_build:
	bash ci/dep_build.sh

configure:
	bash ci/project_configure.sh

build:
	cmake --build ${BUILD_DIR} -j
	
run: 
	${BUILD_DIR}/bin/dag_range
	${BUILD_DIR}/bin/ranges_impl_1
bench:
	${BUILD_DIR}/bin/mathop_bench
	${BUILD_DIR}/bin/dag_bench
	${BUILD_DIR}/bin/ranges_impl_bench

clean:
	rm -rf ${BUILD_DIR}
	rm -rf ${DEP_DIR}
