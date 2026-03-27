import os

# Source folder containing C++ directories
source_root = os.getcwd()  # Assuming you run the script in "DSA C++"
# Destination folder for Python skeletons
dest_root = os.path.join(source_root, "DSA Python")

for root, dirs, files in os.walk(source_root):
    # Skip the destination folder itself if it exists
    if "DSA Python" in root:
        continue

    # Filter C++ files
    cpp_files = [f for f in files if f.endswith(".cpp")]
    if not cpp_files:
        continue

    # Calculate relative path from source_root
    rel_path = os.path.relpath(root, source_root)
    dest_dir = os.path.join(dest_root, rel_path)
    os.makedirs(dest_dir, exist_ok=True)

    for cpp_file in cpp_files:
        # Convert file name to .py
        py_file = cpp_file.rsplit(".cpp", 1)[0] + ".py"
        py_path = os.path.join(dest_dir, py_file)

        # Write basic Python skeleton
        with open(py_path, "w") as f:
            f.write(f"# {py_file} - Python skeleton converted from C++\n\n")
            f.write("def main():\n")
            f.write("    pass\n\n")
            f.write("if __name__ == '__main__':\n")
            f.write("    main()\n")

print(f"Python skeletons for all C++ files created under '{dest_root}'")