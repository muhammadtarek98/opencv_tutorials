# OpenCV Tutorials

A comprehensive collection of C++ examples demonstrating various OpenCV functionalities for image processing, computer vision, and geometric transformations.

## Overview

This repository contains practical tutorials and code examples for learning OpenCV. Each tutorial is self-contained with its own CMake configuration and demonstrates specific OpenCV features through working code examples.

## Repository Structure

### Histogram Operations

- **calcuate_histogram** - Calculate and visualize image histograms
- **campare_histograms** - Compare histograms between different images
- **histogram_equalization** - Enhance image contrast using histogram equalization

### Image Transformations

- **image_transformations/threshold** - Apply binary thresholding to images
- **image_transformations/adaptive_threshold** - Adaptive thresholding for varying lighting conditions
- **image_transformations/linear_blend** - Blend two images using linear interpolation
- **image_transformations/distance_transformation** - Compute distance transform of binary images
- **image_transformations/flood_fill** - Fill connected regions in images
- **image_transformations/grab_cut** - Foreground extraction using GrabCut algorithm
- **image_transformations/integral** - Calculate integral images for efficient region analysis

### Image Filtering

- **image_filtering/laplacian_operator** - Apply Laplacian operator for edge detection

### Geometric Transformations

- **geometric_transformation/affine_transformation** - Apply affine transformations to images
- **geometric_transformation/warp_perspective_transformation** - Perspective warping and transformation
- **geometric_transformation/rotation_matrix** - Rotate images using rotation matrices
- **geometric_transformation/resize** - Image resizing with various interpolation methods
- **geometric_transformation/remap** - Generic geometric transformations using remapping
- **geometric_transformation/get_rect_sub_pixel** - Extract sub-pixel accurate rectangular regions
- **geometric_transformation/polar_transformations** - Convert between Cartesian and polar coordinates

### OpenCV Utilities

- **opencv_utitities/applycolormap** - Apply color maps to grayscale images
- **opencv_utitities/mat_types** - Working with different Mat types and conversions
- **opencv_utitities/convert_maps** - Conversion between different mapping representations

## Prerequisites

- OpenCV library (version 4.x or later recommended)
- C++ compiler with C++11 support or later
- CMake (version 3.0 or later)

## Building the Tutorials

Each tutorial directory contains its own `CMakeLists.txt` file. To build a specific tutorial:

```bash
cd <tutorial_directory>
mkdir build
cd build
cmake ..
make
```

For example, to build the threshold tutorial:

```bash
cd image_transformations/threshold
mkdir build
cd build
cmake ..
make
./threshold
```

## Running the Examples

After building, run the generated executable from the build directory. Note that some examples may require you to update the image paths in the source code to point to your own images.
