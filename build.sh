export PATH=/mnt/data1/nix/root/bin:$PATH
#libtasn1
./configure --without-p11-kit  --prefix=/mnt/data1/nix/root/ 		--disable-srp-authentication --with-gnu-ld LDFLAGS="-ldl"
# ./configure  --with-included-libtasn1 --without-p11-kit
make -j20
sudo make install
