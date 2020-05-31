C++ Travel Customer Choice Model Library
========================================

# Summary
TravelCCM aims at providing a clean API, and the corresponding
C++ implementation, for choosing one item among a set of travel
solutions, given demand-related characteristics (_e.g._,
Willingness-To-Pay, preferred airline, preferred cabin, etc.).

The TravelCCM C++ library implements some simple Customer Choice Models
(CCM), as referenced in the literature (PhD dissertations at MIT, for
instance: http://dspace.mit.edu).

The TravelCCM C++ library exposes a simple, clean and object-oriented,
API. For instance, the choose() method takes, as input, both a
structure representing the travel request (e.g., "from Washington, DC,
US, to Beijing, China, on the 25th of May") and a list of travel
solutions (as provided by the Airline Schedule Manager project:
http://sourceforge.net/projects/air-sched), and yields, as output, the
chosen item.

The output can then be used by other systems, for instance to book the
corresponding travel or to visualize it on a map and calendar and to
share it with others.

TravelCCM makes an extensive use of existing open-source libraries for
increased functionality, speed and accuracy. In particular the
Boost (C++ Standard Extensions: http://www.boost.org) library is used.

TravelCCM is the one of the components of the Travel Market Simulator
(http://www.travel-market-simulator). However, it may be used in a
stand-alone mode.

# Installation

## On Fedora/CentOS/RedHat distribution
Just use DNF:
```bash
$ dnf -y install travelccm-devel travelccm-doc
```

You can also get the RPM packages (which may work on Linux
distributions like Suse and Mandriva) from the Fedora repository
(_e.g._, for Fedora 32, 
https://fr2.rpmfind.net/linux/RPM/fedora/32/x86_64/)


## Building the library and test binary from Git repository
The Git repository may be cloned as following:
```bash
$ git clone git@github.com:airsim/travelccm.git travelccmgit # through SSH
$ git clone https://github.com/airsim/travelccm.git # if the firewall filters SSH
$ cd travelccmgit
```

Then, you need the following packages (Fedora/RedHat/CentOS names here, 
but names may vary according to distributions):
* cmake
* gcc-c++
* boost-devel / libboost-dev
* python-devel / python-dev
* gettext-devel / gettext-dev
* sqlite3-devel / libsqlite3-dev
* readline-devel / readline-dev
* ncurses-devel
* soci-mysql-devel, soci-sqlite3-devel
* stdair-devel / libstdair-dev
* sevmgr-devel / libsevmgr-dev
* doxygen, ghostscript, graphviz
* tetex-latex (optional)
* rpm-build (optional)


## Building the library and test binary from the tarball
The latest stable source tarball (`travelccm*.tar.gz` or `.bz2`)
can be found here:
https://github.com/airsim/travelccm/releases

To customise the following to your environment, you can alter the path
to the installation directory:
```bash
export INSTALL_BASEDIR="${HOME}/dev/deliveries"
export CCM_VER="1.00.5"
if [ -d /usr/lib64 ]; then LIBSUFFIX="64"; fi
export LIBSUFFIX_4_CMAKE="-DLIB_SUFFIX=$LIBSUFFIX"
```

Then, as usual:
* To configure the project, type something like:
```bash
  mkdir build && cd build
  cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_BASEDIR}/travelccm-$CCM_VER \
   -DWITH_STDAIR_PREFIX=${INSTALL_BASEDIR}/stdair-stable \
   -DCMAKE_BUILD_TYPE:STRING=Debug -DENABLE_TEST:BOOL=ON -DINSTALL_DOC:BOOL=ON \
   -DRUN_GCOV:BOOL=OFF ${LIBSUFFIX_4_CMAKE} ..
```
* To build the project, type:
```bash
  make
```
* To test the project, type:
```bash
  make check
```
* To install the library (`libtravelccm*.so*`) and the binary (`travelccm`),
  just type:
```bash
  make install
  cd ${INSTALL_BASEDIR}
  rm -f travelccm-stable && ln -s travelccm-${CCM_VER} travelccm-stable
  cd -
```
* To package the source files, type:
```bash
  make dist
```
* To package the binary and the (HTML and PDF) documentation:
```bash
  make package
```
* To browse the (just installed, if enabled) HTML documentation:
```bash
  midori file://${INSTALL_BASEDIR}/travelccm-$CCM_VER/share/doc/travelccm/html/index.html
```
* To browse the (just installed, if enabled) PDF documentation:
```bash
  evince ${INSTALL_BASEDIR}/travelccm-$CCM_VER/share/doc/travelccm/html/refman.pdf
```
* To run the local binary version:
```bash
  ./travelccm/travelccm -b
```
* To run the installed version:
```bash
  ${INSTALL_BASEDIR}/travelccm-$CCM_VER/bin/travelccm -b
```

Denis Arnaud (June 2015)

