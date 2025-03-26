# File Splitter

A command-line utility to split files into smaller parts by size or number of parts. Written in C.

---

## Features
- Split files by **size** (e.g., `-s 100` → 100-byte parts) or **number of parts** (e.g., `-n 5` → 5 parts).
- Custom output filename prefixes (e.g., `-o output` → `output_0`, `output_1`).
- Handles binary files.
- Error checking for invalid inputs.

### Prerequisites
- `gcc` compiler
- GNU Make

### Build
```bash

git clone https://github.com/your-repo/file-splitter.git
cd file-splitter
make
```

The executable will be generated in `./bin/split`.

---

## Usage

### Basic Syntax
```bash
./bin/split (-n <parts> | -s <size>) [-o <output_prefix>] <file...>
```

### Examples
1. **Split `largefile.bin` into 3 parts**:
   ```bash
   ./bin/split -n 3 largefile.bin
   ```
   Output: `largefile_0`, `largefile_1`, `largefile_2`.

2. **Split `data.log` into 500-byte chunks with a custom prefix**:
   ```bash
   ./bin/split -s 500 -o logs data.log
   ```
   Output: `logs_0`, `logs_1`, etc.

3. **Split multiple files**:
   ```bash
   ./bin/split -n 4 file1.txt file2.txt
   ```

### Error Handling
- Invalid size/parts:  
  ```bash
  ./bin/split -n 0 file.txt  # Error: "Invalid option"
  ```
- Missing file:  
  ```bash
  ./bin/split -s 100 missing.txt  # Error: "Failed to open file"
  ```

---

## Testing

1. **Build the project**:
   ```bash
   make
   ```

2. **Create a test file**:
   ```bash
   dd if=/dev/urandom of=testfile.bin bs=1024 count=10
   ```

3. **Run tests**:
   ```bash
   # Split into 5 parts
   ./bin/split -n 5 testfile.bin

   # Split into 200-byte chunks
   ./bin/split -s 200 -o chunks testfile.bin
   ```

4. **Verify output**:
   ```bash
   ls -l testfile_*
   cat testfile_* > merged.bin && diff testfile.bin merged.bin
   ```

---

## File Structure
```
.
├── bin/          # Compiled binary
├── obj/          # Object files
├── src/          # Source code
│   ├── split_file.c
│   ├── scan_part.c
│   ├── main.c
│   └── ...
├── inc/          # Header files
│   └── split.h
└── Makefile
```

<div style="text-align: center;">
    <img src="img/popcat-meme.gif">
</div>