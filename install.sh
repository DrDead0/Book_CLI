#!/bin/bash

set -e

INSTALL_DIR="/usr/local/bin"
DOWNLOAD_URL="https://github.com/DrDead0/Book_CLI/releases/download/v0.2/book-unix"

echo "Downloading Book CLI v0.2.0..."
curl -fsSL -o book "$DOWNLOAD_URL"

echo "Granting executable permissions..."
chmod +x book

echo "Installing to $INSTALL_DIR (may require sudo)..."
sudo mv book "$INSTALL_DIR/book"

echo "Success! Book CLI installed. Run 'book' to get started."