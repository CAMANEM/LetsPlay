# LetsPlay
### Project #2 - Algorithms and Data Structures II - CE

Requisites

You need to install wxWidgets, in this link you can see tutorials explaining the installation for Windows, MacOS and Linux: https://www.youtube.com/playlist?list=PL37oPRxdrWm5cgUy5VcGe4ckoKuFqdjko 

Or you can follow the next instructions for Linux installation:

First, downdload wxWidgets last stable release "Source for Linux, macOS, etc" option at:
https://www.wxwidgets.org/downloads/

Second, Extract File.

Third, run these commands in terminal:

  sudo apt install build-essential
  sudo apt install libgtk2.0-dev
  sudo apt install libgtk-3-dev
  cd ~/wx/wxWidgets-3.1.3
  mkdir gtk-build
  cd gtk-build
  ../configure
  make -j3
  sudo make install
  sudo ldconfig
