#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <caffe/caffe.hpp>
#include <string>
#include <utility>
#include <memory>

namespace caffe_export {

/* Pair (label, confidence) representing a prediction. */
typedef std::pair<std::string, float> Prediction;

class Classifier {
 public:
  Classifier(const std::string &model_file,
             const std::string &trained_file,
             const std::string &mean_file,
             const std::string &label_file);

  std::vector<Prediction> Classify(const cv::Mat &img, int N = 5);

 private:
  void SetMean(const std::string &mean_file);

  std::vector<float> Predict(const cv::Mat &img);

  void WrapInputLayer(std::vector<cv::Mat> *input_channels);

  void Preprocess(const cv::Mat &img,
                  std::vector<cv::Mat> *input_channels);

 private:
  std::shared_ptr<caffe::Net < float>> net_;
  cv::Size input_geometry_;
  int num_channels_;
  cv::Mat mean_;
  std::vector<std::string> labels_;
};

std::vector<Prediction> predict(const std::string &model_file,
                                const std::string &trained_file,
                                const std::string &mean_file,
                                const std::string &label_file,
                                const std::string &image_file);
}
