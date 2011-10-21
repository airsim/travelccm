#
%global mydocs __tmp_docdir
#
Name:           travelccm
%global sfname  travel-ccm
Version:        0.5.0
Release:        1%{?dist}

Summary:        C++ Travel Customer Choice Model Library

Group:          System Environment/Libraries 
License:        LGPLv2+
URL:            http://sourceforge.net/projects/%{sfname}/
Source0:        http://downloads.sourceforge.net/%{sfname}/%{name}-%{version}.tar.bz2
BuildRoot:      %(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)

BuildRequires:  cmake, python-devel
BuildRequires:  boost-devel, soci-mysql-devel, zeromq-devel, readline-devel
BuildRequires:  stdair-devel


%description
%{name} aims at providing a clean API, and the corresponding
C++ implementation, for choosing one item among a set of travel
solutions, given demand-related characteristics (e.g.,
Willingness-To-Pay, preferred airline, preferred cabin, etc.).

The %{name} C++ library implements some simple Customer Choice Models
(CCM), as referenced in the literature (PhD dissertations at MIT, for
instance: http://dspace.mit.edu).

The %{name} C++ library exposes a simple, clean and object-oriented,
API. For instance, the choose() method takes, as input, both a
structure representing the travel request (e.g., "from Washington, DC,
US, to Beijing, China, on the 25th of May") and a list of travel
solutions (as provided by the Airline Schedule Manager project:
http://sourceforge.net/projects/air-sched), and yields, as output, the
chosen item.

The output can then be used by other systems, for instance to book the
corresponding travel or to visualise it on a map and calendar and to
share it with others.

Install the %{name} package if you need a library for high-level
customer-choice modeling functionality.

%package        devel
Summary:        Header files, libraries and development documentation for %{name}
Group:          Development/Libraries
Requires:       %{name}%{?_isa} = %{version}-%{release}
Requires:       pkgconfig

%description    devel
This package contains the header files, static libraries and
development documentation for %{name}. If you would like to develop
programs using %{name}, you will need to install %{name}-devel.

%package doc
Summary:        HTML documentation for the %{name} library
Group:          Documentation
%{?fedora:BuildArch:      noarch}
BuildRequires:  tex(latex)
BuildRequires:  doxygen, ghostscript

%description doc
This package contains the documentation in the HTML format of the %{name}
library. The documentation is the same as at the %{name} web page.


%prep
%setup -q
# Fix some permissions and formats
chmod -x AUTHORS ChangeLog COPYING NEWS README
find . -type f -name '*.[hc]pp' -exec chmod -x {} \;


%build
%cmake .
make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT

mkdir -p %{mydocs}
mv $RPM_BUILD_ROOT%{_docdir}/%{name}-%{version}/html %{mydocs}
rm -f %{mydocs}/html/installdox

%check
ctest

%clean
rm -rf $RPM_BUILD_ROOT

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%defattr(-,root,root,-)
%doc AUTHORS ChangeLog COPYING NEWS README
%{_bindir}/%{name}
%{_libdir}/lib*.so.*
%{_mandir}/man1/%{name}.1.*

%files devel
%defattr(-,root,root,-)
%{_includedir}/%{name}
%{_bindir}/%{name}-config
%{_libdir}/lib%{name}.so
%{_libdir}/pkgconfig/%{name}.pc
%{_datadir}/aclocal/%{name}.m4
%dir %{_datadir}/%{name}
%{_datadir}/%{name}/CMake
%{_mandir}/man1/%{name}-config.1.*
%{_mandir}/man3/%{name}-library.3.*

%files doc
%defattr(-,root,root,-)
%doc %{mydocs}/html
%doc COPYING


%changelog
* Sat Aug 20 2011 Denis Arnaud <denis.arnaud_fedora@m4x.org> 0.5.0-1
- Upstream integration

* Mon Aug 23 2010 Denis Arnaud <denis.arnaud_fedora@m4x.org> 0.4.0-1
- Initial RPM release

