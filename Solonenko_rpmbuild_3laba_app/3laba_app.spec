Name:    3laba_app
Version: 1.0
Release: alt1
Summary: Most simple RPM package
License: no
Group:   Development/Other
Source:  %name-%version.tar
BuildRequires: gcc-c++

%description
Hello world and roman sanich

%prep
%setup -n %name

%build
%make_build 3laba_app

%install
mkdir -p %{buildroot}%_bindir
install -m 755 3laba_app %{buildroot}%_bindir

# Параметры для хранения файла max_score.txt
mkdir -p %{buildroot}%{_localstatedir}/lib/3laba_app

%post
# Создаем каталог при установке
if [ ! -d %{_localstatedir}/lib/3laba_app ]; then
    mkdir -p %{_localstatedir}/lib/3laba_app
fi

%postun
# Удаляем файл max_score.txt и каталог при удалении пакета
rm -f %{_localstatedir}/lib/3laba_app/max_score.txt
rmdir --ignore-fail-on-non-empty %{_localstatedir}/lib/3laba_app

%files
%_bindir/%name
%dir %{_localstatedir}/lib/3laba_app

%changelog
* Mon Apr 01 2024 Your Name <your_email@altlinux.org> 1.0-alt1
- Initial build
