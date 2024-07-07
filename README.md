cmake -G "Unix Makefiles" -B ./buildsystem/x64/debug -S .

cmake --build ./buildsystem/x64/debug

ctest --test-dir ./buildsystem/x64/debug