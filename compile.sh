set -e
cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
wine ./main.exe
