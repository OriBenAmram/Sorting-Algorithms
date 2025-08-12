import os, sys

# Add the <repo>/python directory to sys.path so `from algorithms.*` works
repo_root = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
python_dir = os.path.join(repo_root, "python")
if python_dir not in sys.path:
    sys.path.insert(0, python_dir)
