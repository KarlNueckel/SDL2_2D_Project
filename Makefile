macos:
	g++ -o bin/main main.cpp src/* -std=c++11 -I lib/macos/include -L lib/macos/lib -l SDL2 -l SDL2_image
windows:
	g++ -o bin/main main.cpp src/* -std=c++11 -I lib/windows/include -L lib/windows/lib -l mingw32 -l SDL2main -l SDL2 -l SDL2_image
windows_mingw64:
	g++ -o bin/main main.cpp src/* -std=c++11 -I lib/windows_mingw64/include -L lib/windows_mingw64/lib -l mingw32 -l SDL2main -l SDL2 -l SDL2_image
windows_test:
	g++ -o bin/test test/* src/* -std=c++14 -I lib/windows_mingw64/include -L lib/windows_mingw64/lib -l mingw32 -l SDL2main -l SDL2 -l SDL2_image -I googletest/googletest/include -L lib/googletest/windows -l gtest_main -l gtest
macos_test:
	g++ -o bin/test test/* src/* -std=c++14 -I lib/macos/include -L lib/macos/lib -l SDL2main -l SDL2 -l SDL2_image -I googletest/googletest/include -L lib/googletest/macos -l gtest_main -l gtest
macos_leaks:
	leaks --atExit --list -- ./bin/main
	
# For leaks, use export MallocStackLogging=1 for more details.
