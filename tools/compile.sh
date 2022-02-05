echo "Creating build output directory..."
mkdir -p build

echo "Compiling modules..."
gcc -c src/buildManager/RNBuildManager.c -o build/RNBuildManager.o
gcc -c src/researchManager/RNResearchManager.c -o build/RNResearchManager.o

echo "Compiling main..."
gcc -c src/main.c -o build/main.o

echo "Linking modules to main to main executable..."
gcc build/main.o build/RNBuildManager.o build/RNResearchManager.o -o build/main

echo "Removing build ouputs..."
rm -rf build/*.o
