CC="i686-elf-gcc"
LINKER_SCRIPT="figma/linker.ld"
OUTPUT="sigma.kernel"
OBJ_FILES=$(find figma/obj -maxdepth 1 -type f -name "*.o")
$CC -T "$LINKER_SCRIPT" -o "$OUTPUT" -ffreestanding -O2 -nostdlib $OBJ_FILES -lgcc
if [ $? -eq 0 ]; then
    echo "Linking sucessful: $OUTPUT"
else
    echo "Linking error"
    exit 1
fi