#
cmake_minimum_required (VERSION 2.6)

##
# CMake macros for the project
include (config/project_config_embeddable.cmake)

##
# Project info
set_project_names (travelccm TravelCCM)
set_project_versions (99 99 99)

##
# Project options
# The parameters are:
#  * whether or not the documentation must be built and installed
set_project_options (off)


#####################################
##            Packaging            ##
#####################################
#
packaging_init (${PROJECT_NAME})
packaging_set_description ("C++ Travel Customer Choice Model Library")
packaging_set_summary (
"${PROJECT_NAME} aims at providing a clean API, and the corresponding 
C++ implementation, for choosing one item among a set of travel solutions,
given demand-related characteristics (e.g., Willingness-To-Pay, preferred
airline, preferred cabin, etc.).

The ${PROJECT_NAME} C++ library implements some simple Customer Choice 
Models (CCM), as referenced in the literature (PhD dissertations at MIT, 
for instance: http://dspace.mit.edu).

The ${PROJECT_NAME} C++ library exposes a simple, clean and object-oriented,
API. For instance, the choose() method takes, as input, both a
structure representing the travel request (e.g., from Washington, DC,
US, to Beijing, China, on the 25th of May) and a list of travel
solutions (as provided by the Airline Schedule Manager project:
http://sourceforge.net/projects/air-sched), and yields, as output, the
chosen item.

The output can then be used by other systems, for instance to book the
corresponding travel or to visualise it on a map and calendar and to
share it with others.

${PROJECT_NAME} makes an extensive use of existing open-source libraries for
increased functionality, speed and accuracy. In particular the
Boost (C++ Standard Extensions: http://www.boost.org) library is used")
packaging_set_contact ("Denis Arnaud <denis_arnaud - at - users dot sourceforge dot net>")
packaging_set_vendor ("Denis Arnaud")

#
packaging_set_other_options (TBZ2 "TBZ2;TGZ")


########################################
##            Dependencies            ##
########################################
#
get_external_libs (git "boost 1.41" mysql "soci 3.0" "stdair 0.35" doxygen)


##############################################
##           Build, Install, Export         ##
##############################################
##
# Initialise the building process
init_build ()

##
# Sub-modules
add_modules (${PROJECT_NAME})

##
# For other projects to use TravelCCM, install a few helpers for standard
# build/packaging systems: CMake, GNU Autotools (M4), pkgconfig/pc, 
# travelccm-config
install_dev_helper_files ()

##
# Basic documentation (i.e., AUTHORS, NEWS, README, INSTALL)
install_basic_documentation ()


##########################################
##            Documentation             ##
##########################################
if (${INSTALL_DOC} STREQUAL "ON")
  add_subdirectory (doc)
endif (${INSTALL_DOC} STREQUAL "ON")


#####################################
##              Tests              ##
#####################################
##
# Test suites
add_test_suites (${PROJECT_NAME})


#######################################
##          Overall Status           ##
#######################################
display_status ()


#######################################
##         CMake Cache Storage       ##
#######################################
store_in_cache ()
