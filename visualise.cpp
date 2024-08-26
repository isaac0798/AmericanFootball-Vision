#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    // Check if video path is provided
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <VideoPath>" << std::endl;
        return -1;
    }

    // Open the video file
    cv::VideoCapture cap(argv[1]);

    // Check if video opened successfully
    if (!cap.isOpened()) {
        std::cout << "Error opening video file" << std::endl;
        return -1;
    }

    // Get video properties
    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(cv::CAP_PROP_FPS);

    std::cout << "Video properties:" << std::endl;
    std::cout << "Width: " << frame_width << std::endl;
    std::cout << "Height: " << frame_height << std::endl;
    std::cout << "FPS: " << fps << std::endl;

    cv::namedWindow("Frame", cv::WINDOW_NORMAL);

    while (true) {
        cv::Mat frame;
        // Read a new frame from video
        bool success = cap.read(frame);
        
        // Break the loop if no more frames
        if (!success)
            break;

        // Display the frame
        cv::imshow("Frame", frame);

        // Press 'q' to exit
        if (cv::waitKey(30) == 'q')
            break;
    }

    // Release the video capture object
    cap.release();

    // Close all windows
    cv::destroyAllWindows();

    return 0;
}
