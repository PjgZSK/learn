# iina build/mac
## 1. build by xcode
* install mpv

    > brew tap iina/homebrew-mpv-iina
    
    > brew install mpv-iina

* clone iina

    > git clone https://github.com/iina/iina.git

* run iina script

    > `cd iina`

    > `other/parse_doc.rb`

    > `other/change_lib_dependencies.rb "$(brew --prefix)" "$(brew --prefix mpv-iina)/lib/libmpv.dylib"`

* set .xcodeproj

    > first open iina by xcode

    > remove all .dylib from Frameworks group

    > add all .dylib in `deps/lib` to Frameworks group

    > open iina target, select `build phases->copy dylibs`, add all imported .dylib

    > build (debug)
## 2. build release
> select `product->scheme->edit scheme...`, switch `build configuration` to `release`

> open iina target, switch `build settings->build active architecture only->release` to `yes`

> build (release)

## 3. app location
> ~/Library/Developer/Xcode/DerivedData/iina-`...`/Build/Products/Debug/IINA.app

## 4. build error
* youtube-dl : No such file or directory
    
    > install youtube-dl  
    > sudo curl -L https://yt-dl.org/downloads/latest/youtube-dl -o /usr/local/bin/youtube-dl  
    > sudo chmod a+rx /usr/local/bin/youtube-dl

    > use `ln` soft link to right location.
