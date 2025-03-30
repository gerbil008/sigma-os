mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp  sigma.kernel isodir/boot/sigma.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "sigma" {
	multiboot /boot/sigma.kernel
}
EOF
grub-mkrescue -o sigma.iso isodir