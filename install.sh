# freebsd-net-tools
sudo apt install -y datefudge docbook docbook-to-man fonts-lmodern gtk-doc-tools  guile-3.0-dev libcmocka-dev libcmocka0 libopts25 libopts25-dev libosp5  libptexenc1 libsofthsm2 libteckit0 libtexlua53 libtexluajit2  libunbound-dev libzzip-0-13 net-tools opensp softhsm2 softhsm2-common  texlive-base texlive-binaries texlive-latex-base texlive-plain-generic  bison  ca-certificates  chrpath datefudge  debhelper-compat    gperf  guile-3.0-dev  libcmocka-dev  libidn2-dev libopts25-dev libp11-kit-dev  libssl-dev  libtasn1-6-dev  libunbound-dev  libunistring-dev  net-tools  nettle-dev  openssl pkg-config  python3  softhsm2  gtk-doc-tools  texinfo  texlive-latex-base texlive-plain-generic  unbound-anchor unbound asn1c
  
  sudo unbound-anchor -a "/etc/unbound/root.key"
  ./configure  --with-included-libtasn1 --without-p11-kit
  

