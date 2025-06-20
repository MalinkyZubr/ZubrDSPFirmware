export PROJECT=`pwd`
export PICO_SDK_PATH=$PROJECT/lib/pico-sdk
cd $PICO_SDK_PATH
git submodule update --init
cd -
mkdir build
cd ./build
cmake .. -DPICO_CYW43_SUPPORTED=1 -DPICO_BOARD=pico_w
make main SPEED=full all