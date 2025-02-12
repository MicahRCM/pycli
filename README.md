# PyCli

PyCli is a domain specific language (DSL) embedded in Python for climate
modeling. Users can specify the amount of CO2 in the atmosphere in Python, and 
the model's C++ backend computes temperatures across the planet. By tweaking the
levels of greenhouse gases, users can see how changes in the
atmosphere's makeup affect global temperatures. The final output
of the simulation is a temperature map of the planet generated by the visualization
suite.

PyCli is designed to be an educational tool for understanding global warming
and climate change modeling. PyCli uses a very simplified model of the climate to
do  calculations and ignores factors such as particulate matter, cloud cover,
and ocean currents. This project is not meant to compete with the climate
models designed by national institutes. Rather, it is purely an educational
tool designed for people interested in climate change and scientific computing.

![Alt text](images/earth.png?raw=true "Earth temperature map")

## Table of Contents

1. [Supported Model Features](#supported-model-features)
2. [Environment](#environment)
3. [Installation](#installation)
4. [Running your first model](#running-first-model)
5. [Folder organization](#folder-organization)
6. [Contributors and Contact](#contributors-and-contact)
7. [License](#license)

## [Supported Model Features](#supported-model-features)

PyCli uses a discretized grid to represent the earth and to simulate
temperatures. Currently, the model allows users to specify:

1. The surface of the planet (land, sea, or ice)
2. The model resolution, defined by the size of the grid
3. The amount of CO2 in the atmosphere at each simulation step. 
The CO2 level is the main driver of temperature changes between steps. Users
can specify either the concentration (in ppm) or the amount of CO2 emitted 
annually (in gigatons).

## [Environment](#environment)

PyCli was has the following system requirements and dependencies:


Python:
```
python3
matplotlib
numpy
mpl_toolkits
argparse
```

C++:
```
C++14
OpenMP
gcc or clang compiler
```

OS and other:
```
macOS or Ubuntu
git
```

PyCli was tested on machines running macOS 10.15 Catalina and Ubuntu 14 but
should run on similar operating systems. PyCli has not been tested on a 
Windows machine, but it may run on the Windows Subsystem for Linux.

## [Installation](#installation)

The installation instructions require the user to have some familiarity
with using the terminal.To install PyCli, first clone the repository using the terminal:

```
git clone https://github.com/timsliu/pycli.git
```

Next, navigate to the python source file and install the PyCli python library:

```
cd pycli/pysrc
pip3 install -e .
```
And that's it! If you're missing some of the dependencies, follow the
instructions below. Please note that `pycli` is also the name of a Python
Command Line Interface (CLI) library and that installing PyCli may cause the 
Python CLI to be uninstalled. Future versions of PyCli will resolve this
naming issue.

### Installing dependencies
If you don't have some of the Python libraries, use pip to install them:

```
pip3 install matplotlib
pip3 install numpy
pip3 install mpl_toolkits
pip3 install argparse
```

To install OpenMP on macOS, use Homebrew:

```
brew install libomp
```

To install on Ubuntu:

```
sudo apt-get install libomp-dev
```


## [Running your First Model](#running-first-model)

First, make sure you've completed all the steps in the Installation section.
Climate models written in PyCli should be saved in the `pycli/models` subdirectory.
The PyCli repo includes several example climate models. The 
`earth.py` model simulates the Earth's climate across five timesteps
with varying levels of CO2.

To run a model, use the following command while in the `<models>` directory:

```
python3 run-pycli.py <model_name>
```

For the `earth_big` prewritten model, the command is:

```
python3 run-pycli.py earth
```

Note that the model name should not have `.py` at the end - only include
The name of the model. The `run-pycli.py` script will run the PyCli
model interpreter, the climate simulation backend, and the visualization
suite.

The script will create a directory with the name of the model in
the `<models>` folder and place a `surface.txt` and `atmosphere.txt`
file in the directory. These files describe the surface of the planet and
the atmosphere at each simulation step. After the simulation is run, a map
of the final temperatures and a chart of the average temperature
at each step will be placed in model's folder.

![Alt text](images/earth.png?raw=true "Earth temperature map")

## [Folder Organization](#folder-organization)
This section briefly describes the contents of each of the subfolders in the
PyCli repo. Some of the subfolders have a `README.md` with more details about
the subfolder's function.

### src
The `src` directory contains the C++ backend for running the climate model.
This folder also contains the `Makefile` for compiling the model and some
testing infrastructure. Users wishing to modify the climate model should
make changes in this directory.

### models
This directory contains PyCli models. All PyCli models should be written and
saved in this directory with a `.py` extension. Each time a PyCli model is 
run, a new subfolder will be generated holding the atmosphere and surface
configuration files. The final temperature map will then be placed in a
model's newly created subfolder.

This directory also holds the `run-pycli.py` script. This script is run to
invoke the entire PyCli stack. The script will run the PyCli front end to
generate configuration files, launch the C++ backend, and finally use the
visualization suite to create graphs and maps. The README in this folder
has more information on how to write models in PyCli.

### pysrc
This directory contains the PyCli library for the PyCli front end. The front
end is implemented as a series of method calls for users to create a new
model, set the surface, and specify the atmosphere at each step. The Python
front end is also responsible for generating the model configuration files used
by the C++ climate model.

### tex
This directory contains typeset documents describing how the C++ climate
model backend works. Users interested in the science and mathematics behind
the model should read this document.

### vis
This directory contains the visualization suite for creating plots and temperature
maps. Users interested in changing or adding output plots should modify files in
this folder.

### bin
The `bin` directory contains compiled binary files.

### spectrum
The `spectrum` directory includes several Python programs that were used to
calculate physical constants related to atmospheric infrared absorption for
the backend climate model. The file `pycli.pdf` in the `tex` folder has more
details on these calculations.

### images
Images used for this README file are stored in the `images` directory.

### docs
Documentation, release notes, and planned changes are detailed in the 
`docs` folder. Most folders have a README file with some details about the
folder's contents, but the bulk of the documentation is in the `docs` 
folder.


## [Contributors and Contact](#contributors-and-contact)
PyCli is an open source project created by Kalhan Koul, Timothy Liu, and
Jack Melchert at Stanford.  This project originated from a [CS343D: Domain Specific
Programming Models and Compilers](https://cs343d.github.io/) course assignment
and is currently maintained and updated by Timothy Liu. The developers of 
PyCli would like to thank Professor Paul Asimow from Caltech for his
helpful insights on the radiative transfer model used in the backend climate
model.

The best way to contact the PyCli-DSL team with questions or feature
suggestions is to use the [PyCli Google Group](https://groups.google.com/g/pycli-dsl).

## [License](#license)
PyCli-DSL is distributed under the MIT open source license. For the full
license contents, please see `license.txt`.



##
Copyright 2021 Timothy Liu
