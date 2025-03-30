
SOURCE_DIR="figma"            # Hauptquelle
OUTPUT_DIR="figma/obj"        # Ausgabeverzeichnis
ASSEMBLY_FILES=$(find "$SOURCE_DIR" -type f -name "*.S")   # Alle .S-Dateien finden
C_FILES=$(find "$SOURCE_DIR" -type f -name "*.c")           # Alle .c-Dateien finden

# Sicherstellen, dass das Ausgabeverzeichnis existiert
mkdir -p "$OUTPUT_DIR"

# Alle .S-Dateien mit i686-elf-as kompilieren
for file in $ASSEMBLY_FILES; do
    # Der Name der .S-Datei ohne Verzeichnispfad und mit .o-Endung
    output="$OUTPUT_DIR/$(basename "${file%.S}.o")"
    echo "Assembling $file -> $output"
    i686-elf-as "$file" -o "$output"
done

# Alle .c-Dateien mit i686-elf-gcc kompilieren
for file in $C_FILES; do
    # Der Name der .c-Datei ohne Verzeichnispfad und mit .o-Endung
    output="$OUTPUT_DIR/$(basename "${file%.c}.o")"
    echo "Compiling $file -> $output"
    i686-elf-gcc -c "$file" -o "$output" -std=gnu99 -ffreestanding -O2 -Wall -Wextra
done

echo "Build complete!"
