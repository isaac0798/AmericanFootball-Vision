#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Read an image from file
    cv::Mat image = cv::imread("input_image.jpg");

    // Check if the image was successfully loaded
    if (image.empty()) {
        std::cout << "Error: Could not open or find the image" << std::endl;
        return -1;
    }

    // Display the original image
    cv::imshow("Original Image", image);

    // Convert the image to grayscale
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);

    // Display the grayscale image
    cv::imshow("Grayscale Image", gray_image);

    // Apply Gaussian blur
    cv::Mat blurred_image;
    cv::GaussianBlur(gray_image, blurred_image, cv::Size(5, 5), 0);

    // Display the blurred image
    cv::imshow("Blurred Image", blurred_image);

    // Wait for a key press
    cv::waitKey(0);

    return 0;
}
