# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /eos/user/l/llappo/final_all/rooty/251Es

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /eos/user/l/llappo/final_all/rooty/251Es/build

# Include any dependencies generated for this target.
include CMakeFiles/exampleB2b.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exampleB2b.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exampleB2b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exampleB2b.dir/flags.make

CMakeFiles/exampleB2b.dir/exampleB2b.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/exampleB2b.cc.o: ../exampleB2b.cc
CMakeFiles/exampleB2b.dir/exampleB2b.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exampleB2b.dir/exampleB2b.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/exampleB2b.cc.o -MF CMakeFiles/exampleB2b.dir/exampleB2b.cc.o.d -o CMakeFiles/exampleB2b.dir/exampleB2b.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/exampleB2b.cc

CMakeFiles/exampleB2b.dir/exampleB2b.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/exampleB2b.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/exampleB2b.cc > CMakeFiles/exampleB2b.dir/exampleB2b.cc.i

CMakeFiles/exampleB2b.dir/exampleB2b.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/exampleB2b.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/exampleB2b.cc -o CMakeFiles/exampleB2b.dir/exampleB2b.cc.s

CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.o: ../src/B2ActionInitialization.cc
CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.o -MF CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.o.d -o CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/B2ActionInitialization.cc

CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/B2ActionInitialization.cc > CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.i

CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/B2ActionInitialization.cc -o CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.s

CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.o: ../src/B2EventAction.cc
CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.o -MF CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.o.d -o CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/B2EventAction.cc

CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/B2EventAction.cc > CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.i

CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/B2EventAction.cc -o CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.s

CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.o: ../src/B2PrimaryGeneratorAction.cc
CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.o -MF CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.o.d -o CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/B2PrimaryGeneratorAction.cc

CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/B2PrimaryGeneratorAction.cc > CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.i

CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/B2PrimaryGeneratorAction.cc -o CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.s

CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.o: ../src/B2RunAction.cc
CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.o -MF CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.o.d -o CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/B2RunAction.cc

CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/B2RunAction.cc > CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.i

CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/B2RunAction.cc -o CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.s

CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.o: ../src/B2SteppingAction.cc
CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.o -MF CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.o.d -o CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/B2SteppingAction.cc

CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/B2SteppingAction.cc > CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.i

CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/B2SteppingAction.cc -o CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.s

CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.o: ../src/B2TrackerHit.cc
CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.o -MF CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.o.d -o CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/B2TrackerHit.cc

CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/B2TrackerHit.cc > CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.i

CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/B2TrackerHit.cc -o CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.s

CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.o: ../src/B2TrackerSD.cc
CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.o -MF CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.o.d -o CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/B2TrackerSD.cc

CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/B2TrackerSD.cc > CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.i

CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/B2TrackerSD.cc -o CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.s

CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.o: ../src/B2bDetectorConstruction.cc
CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.o -MF CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.o.d -o CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/B2bDetectorConstruction.cc

CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/B2bDetectorConstruction.cc > CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.i

CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/B2bDetectorConstruction.cc -o CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.s

CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.o: ../src/B2bDetectorMessenger.cc
CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.o -MF CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.o.d -o CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/B2bDetectorMessenger.cc

CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/B2bDetectorMessenger.cc > CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.i

CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/B2bDetectorMessenger.cc -o CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.s

CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.o: ../src/GammaNuclearPhysics.cc
CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.o -MF CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.o.d -o CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/GammaNuclearPhysics.cc

CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/GammaNuclearPhysics.cc > CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.i

CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/GammaNuclearPhysics.cc -o CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.s

CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.o: CMakeFiles/exampleB2b.dir/flags.make
CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.o: ../src/PhysicsList.cc
CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.o: CMakeFiles/exampleB2b.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.o"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.o -MF CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.o.d -o CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.o -c /eos/user/l/llappo/final_all/rooty/251Es/src/PhysicsList.cc

CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.i"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /eos/user/l/llappo/final_all/rooty/251Es/src/PhysicsList.cc > CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.i

CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.s"
	/cvmfs/sft.cern.ch/lcg/releases/gcc/11.3.0-de683/x86_64-el9/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /eos/user/l/llappo/final_all/rooty/251Es/src/PhysicsList.cc -o CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.s

# Object files for target exampleB2b
exampleB2b_OBJECTS = \
"CMakeFiles/exampleB2b.dir/exampleB2b.cc.o" \
"CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.o" \
"CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.o" \
"CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.o" \
"CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.o" \
"CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.o" \
"CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.o" \
"CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.o" \
"CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.o" \
"CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.o" \
"CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.o" \
"CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.o"

# External object files for target exampleB2b
exampleB2b_EXTERNAL_OBJECTS =

exampleB2b: CMakeFiles/exampleB2b.dir/exampleB2b.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/B2ActionInitialization.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/B2EventAction.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/B2PrimaryGeneratorAction.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/B2RunAction.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/B2SteppingAction.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/B2TrackerHit.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/B2TrackerSD.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/B2bDetectorConstruction.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/B2bDetectorMessenger.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/GammaNuclearPhysics.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/src/PhysicsList.cc.o
exampleB2b: CMakeFiles/exampleB2b.dir/build.make
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4Tree.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4FR.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4GMocren.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4visHepRep.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4RayTracer.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4VRML.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4ToolsSG.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4OpenGL.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4visQt3D.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4vis_management.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4modeling.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4interfaces.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4persistency.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4error_propagation.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4readout.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4physicslists.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4run.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4event.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4tracking.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4parmodels.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4processes.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4digits_hits.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4track.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4particles.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4geometry.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4materials.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4graphics_reps.so
exampleB2b: /usr/lib64/libGL.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt5OpenGL.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt5PrintSupport.so.5.15.9
exampleB2b: /usr/lib64/libXmu.so
exampleB2b: /usr/lib64/libXext.so
exampleB2b: /usr/lib64/libXm.so
exampleB2b: /usr/lib64/libXt.so
exampleB2b: /usr/lib64/libICE.so
exampleB2b: /usr/lib64/libSM.so
exampleB2b: /usr/lib64/libX11.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt5Widgets.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt53DExtras.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt53DInput.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt53DLogic.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt53DRender.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt53DCore.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt5Gui.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt5Network.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/qt5/5.15.9/x86_64-el9-gcc11-opt/lib/libQt5Core.so.5.15.9
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/XercesC/3.2.4/x86_64-el9-gcc11-opt/lib/libxerces-c.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4analysis.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4expat.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4zlib.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4intercoms.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4global.so
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/Geant4/11.1.2/x86_64-el9-gcc11-opt/lib64/libG4ptl.so.2.3.3
exampleB2b: /cvmfs/sft.cern.ch/lcg/releases/LCG_104/clhep/2.4.6.4/x86_64-el9-gcc11-opt/lib/libCLHEP-2.4.6.4.so
exampleB2b: CMakeFiles/exampleB2b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable exampleB2b"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exampleB2b.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exampleB2b.dir/build: exampleB2b
.PHONY : CMakeFiles/exampleB2b.dir/build

CMakeFiles/exampleB2b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exampleB2b.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exampleB2b.dir/clean

CMakeFiles/exampleB2b.dir/depend:
	cd /eos/user/l/llappo/final_all/rooty/251Es/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /eos/user/l/llappo/final_all/rooty/251Es /eos/user/l/llappo/final_all/rooty/251Es /eos/user/l/llappo/final_all/rooty/251Es/build /eos/user/l/llappo/final_all/rooty/251Es/build /eos/user/l/llappo/final_all/rooty/251Es/build/CMakeFiles/exampleB2b.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exampleB2b.dir/depend

