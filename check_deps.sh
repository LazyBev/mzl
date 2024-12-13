#!/bin/bash

# Function to install packages on Debian/Ubuntu-based systems
install_debian() {
  echo "Installing OpenGL packages for Debian/Ubuntu..."
  sudo apt update
  sudo apt install -y build-essential libglew-dev libglfw3-dev libglm-dev libgl1-mesa-dev
}

# Function to install packages on RedHat/CentOS/Fedora-based systems
install_redhat() {
  echo "Installing OpenGL packages for RedHat/CentOS/Fedora..."
  sudo dnf install -y glew-devel glfw-devel glm-devel mesa-libGL-devel
}

# Function to install packages on Arch-based systems
install_arch() {
  echo "Installing OpenGL packages for Arch Linux..."
  sudo pacman -Syu --noconfirm glew glfw glm mesa
}

# Function to determine the Linux distribution
detect_distro() {
  if [[ -f /etc/os-release ]]; then
    . /etc/os-release
    DISTRIBUTION=$ID
  else
    echo "Cannot detect distribution."
    exit 1
  fi
}

# Main script logic
detect_distro

# Check for the distribution and install the appropriate packages
case "$DISTRIBUTION" in
  debian|ubuntu|linuxmint)
    if ! dpkg -l | grep -i "libglew-dev" > /dev/null 2>&1; then
      install_debian
    else
      echo "OpenGL packages are already installed for Debian/Ubuntu."
    fi
    ;;
  centos|fedora|rhel)
    if ! rpm -qa | grep -i "glew-devel" > /dev/null 2>&1; then
      install_redhat
    else
      echo "OpenGL packages are already installed for RedHat/CentOS/Fedora."
    fi
    ;;
  arch|manjaro)
    if ! pacman -Q| grep -i "glew" > /dev/null 2>&1; then
      install_arch
    else
      echo "OpenGL packages are already installed for Arch Linux."
    fi
    ;;
  *)
    echo "Unsupported Linux distribution: $DISTRIBUTION"
    exit 1
    ;;
esac
