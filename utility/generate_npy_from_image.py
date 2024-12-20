import numpy as np
import argparse
import torch
from numpy import asarray
from PIL import Image

def preprocessimage(img, ch, ht, wt):
    imgnpy = asarray(img)
    imgnpy = np.divide(imgnpy, 255)
    imgnpy = np.moveaxis(imgnpy, -1, 0)
    imgnpy = np.resize(imgnpy, (1, int(ch), int(ht), int(wt)))
    np.save("generated_npy.npy", imgnpy)
    check = np.load("generated_npy.npy")
    print(check.shape)

def main() -> None:
    img = Image.open("dog.jpg")
    parser = argparse.ArgumentParser()

    parser.add_argument("--channel", help="number of channels")
    parser.add_argument("--height",  help="height of the resized image")
    parser.add_argument("--width",  help="width of the resized image")
    args = parser.parse_args()

    preprocessimage(img, args.channel, args.height, args.width)


if __name__ == "__main__":
    main()