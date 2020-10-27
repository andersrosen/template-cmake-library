# template-cmake-library
A template for libraries. This was inspired by https://jappieklooster.nl/using-git-for-templates.html

## Usage

```
git clone -r git@github.com:andersrosen/template-cmake-library new-project
git remote add template git@github.com:andersrosen/template-cmake-library.git
git remote set-url origin git@github.com:andersrosen/new-project.git
```

The library template example is using Catch2 for unit testing. It is added as
a git submodule.

To configure the project, assuming you want to use new-project/build as
the build directory:
```
cd new-project
cmake -B build -DBUILD_SHARED_LIBS=ON ...other settings...
```

To build and test:
```
cmake --build build
cd build && ctest # Terse output
cd build && ctest --output-on-failure # Shows output from tests that fail 
```

To install the project:
```
cmake --build build --target install
```

To create a source package:
```
cd build && cpack -C CPackSourceConfig.cmake
```

Documentation is generated using doxygen. There are two custom doxygen commands
available, to include example files and optionally their output after executing
them.

The commands are `\includeexample` and `\includeexamplewithoutput`, and both are
available in one and two argument versions. Take a look at the documentation
comment in `template.h` and the definition of the commands in `docs/CMakeLists.txt`
