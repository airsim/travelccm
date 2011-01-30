#
%global mydocs __tmp_docdir
#
Name:           travelccm
Version:        99.99.99
Release:        1%{?dist}

Summary:        Travel Customer Choice Model C++ library

Group:          System Environment/Libraries 
License:        LGPLv2+
URL:            http://sourceforge.net/projects/travel-ccm/
Source0:        http://downloads.sourceforge.net/travel-ccm/%{name}-%{version}.tar.bz2
%{?el5:BuildRoot: %(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)}

BuildRequires:  boost-devel
BuildRequires:  soci-mysql-devel


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
structure representing the travel request (e.g., from Washington, DC,
US, to Beijing, China, on the 25th of May) and a list of travel
solutions (as provided by the Airline Schedule Manager project:
http://sourceforge.net/projects/air-sched), and yields, as output, the
chosen item.

The output can then be used by other systems, for instance to book the
corresponding travel or to visualise it on a map and calendar and to
share it with others.

Install the %{name} package if you need a library for high-level
revenue management functionality.

%package        devel
Summary:        Header files, libraries and development documentation for %{name}
Group:          Development/Libraries
Requires:       %{name} = %{version}-%{release}
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
# The INSTALL package is not relevant for RPM package users
# (e.g., see https://bugzilla.redhat.com/show_bug.cgi?id=489233#c4)
rm -f INSTALL
# Fix some permissions and formats
chmod -x AUTHORS ChangeLog COPYING NEWS README
find . -type f -name '*.[hc]pp' -exec chmod 644 {} \;


%build
%configure --disable-static
make %{?_smp_mflags}

%install
# On Fedora, the BuildRoot is automatically cleaned. Which is not the case for
# RedHat. See: https://fedoraproject.org/wiki/Packaging/Guidelines#BuildRoot_tag
%{?rhel:rm -rf $RPM_BUILD_ROOT}

make install DESTDIR=$RPM_BUILD_ROOT INSTALL="install -p"

# Remove unpackaged files from the buildroot
rm -f $RPM_BUILD_ROOT%{_libdir}/lib%{name}.la

mkdir -p %{mydocs}
mv $RPM_BUILD_ROOT%{_docdir}/%{name}-%{version}/html %{mydocs}

%if 0%{?rhel}
%clean
rm -rf $RPM_BUILD_ROOT
%endif

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%defattr(-,root,root,-)
%doc AUTHORS ChangeLog COPYING NEWS README
%{_bindir}/%{name}/
%{_libdir}/lib*.so.*

%files devel
%defattr(-,root,root,-)
%{_includedir}/%{name}/
%{_bindir}/%{name}-config
%{_libdir}/lib%{name}.so
%{_libdir}/pkgconfig/%{name}.pc
%{_datadir}/aclocal/%{name}.m4
%{_mandir}/man1/%{name}-config.1.*

%files doc
%defattr(-,root,root,-)
%doc %{mydocs}/html
%doc COPYING


%changelog
* Mon Aug 23 2010 Denis Arnaud <denis.arnaud_fedora@m4x.org> 99.99.99-1
- Upstream integration

* Mon Aug 23 2010 Denis Arnaud <denis.arnaud_fedora@m4x.org> 0.5.0-1
- Initial RPM release
