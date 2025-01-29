#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(ReadMatrix3x3)
{
  const int expectedMatrixSize{3};
  MatrixXd  expectedMatrix(3, 3);
  expectedMatrix << 0.680375, 0.59688, -0.329554,
      -0.211234, 0.823295, 0.536459,
      0.566198, -0.604897, -0.444451;

  auto data = matrixIO::openData("test_m3.csv", 3);
  BOOST_TEST(expectedMatrixSize == data.rows());
  BOOST_TEST(expectedMatrixSize == data.cols());
  for (size_t x = 0; x < expectedMatrixSize; ++x) {
    for (size_t y = 0; y < expectedMatrixSize; ++y) {
      std::stringstream errorMsg;
      errorMsg << "Matrix does not match at (" << std::to_string(x) << ", " << std::to_string(y) << ")";
      BOOST_CHECK_MESSAGE(expectedMatrix.coeff(x, y) == data.coeff(x, y), errorMsg.str().c_str());
    }
  }
}

BOOST_AUTO_TEST_CASE(ReadMatrix250x250)
{
  const int expectedMatrixSize{250};

  auto data = matrixIO::openData("test_m250.csv", 250);
  BOOST_TEST(expectedMatrixSize == data.rows());
  BOOST_TEST(expectedMatrixSize == data.cols());
}

BOOST_AUTO_TEST_SUITE_END()
