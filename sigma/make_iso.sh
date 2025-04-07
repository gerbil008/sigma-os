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
#grub-install --target=i386-pc --boot-directory=isodir/boot --modules="biosdisk part_msdos ext2 multiboot"

