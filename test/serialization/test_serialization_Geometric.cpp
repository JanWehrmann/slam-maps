#define BOOST_TEST_MODULE SerializationTest
#include <boost/test/unit_test.hpp>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

/** Element type **/
#include <maps/geometric/Point.hpp>
#include <maps/geometric/LineSegment.hpp>

/** Geometric maps **/
#include <maps/geometric/GeometricMap.hpp>

using namespace ::maps::geometric;

BOOST_AUTO_TEST_CASE(test_2d_point_serialization)
{
    Point<double, 2> p_a_original(-2, -3);

    /** Serialization **/
    std::stringstream stream;
    boost::archive::binary_oarchive oa(stream);
    //std::cout << stream.str().size() << std::endl;
    oa << p_a_original;

    /** De-serialize **/
    Point<double, 2> p_a_copy;
    boost::archive::binary_iarchive ia(stream);
    ia >> p_a_copy;

    BOOST_CHECK_EQUAL(p_a_original.x(), p_a_copy.x());
    BOOST_CHECK_EQUAL(p_a_original.y(), p_a_copy.y());

}

BOOST_AUTO_TEST_CASE(test_3d_point_serialization)
{
    Point<double, 3> p_a_original(-2, -3, 1);

    /** Serialization **/
    std::stringstream stream;
    boost::archive::binary_oarchive oa(stream);
    //std::cout << stream.str().size() << std::endl;
    oa << p_a_original;

    /** De-serialize **/
    Point<double, 3> p_a_copy;
    boost::archive::binary_iarchive ia(stream);
    ia >> p_a_copy;

    BOOST_CHECK_EQUAL(p_a_original.x(), p_a_copy.x());
    BOOST_CHECK_EQUAL(p_a_original.y(), p_a_copy.y());
    BOOST_CHECK_EQUAL(p_a_original.z(), p_a_copy.z());
}

BOOST_AUTO_TEST_CASE(test_2d_line_serialization)
{
    Point<double, 2> p_a(0, 6);
    Point<double, 2> p_b(6, 6);
    LineSegment<double, 2> line_original(p_a, p_b);

    /** Serialization **/
    std::stringstream stream;
    boost::archive::binary_oarchive oa(stream);
    oa << line_original;

    /** De-serialize **/
    LineSegment<double, 2> line_copy;
    boost::archive::binary_iarchive ia(stream);
    ia >> line_copy;

    BOOST_CHECK_EQUAL(line_original.psi_a(), line_copy.psi_a());
    BOOST_CHECK_EQUAL(line_original.psi_b(), line_copy.psi_b());
    BOOST_CHECK_EQUAL(line_original.direction(), line_copy.direction());
    BOOST_CHECK_EQUAL(line_original.rho(), line_copy.rho());
    BOOST_CHECK_EQUAL(line_original.alpha(), line_copy.alpha());
}

BOOST_AUTO_TEST_CASE(test_3d_line_serialization)
{
    Point<double, 3> p_a(0, 6, -10);
    Point<double, 3> p_b(6, 6, 2);
    LineSegment<double, 3> line_original(p_a, p_b);

    /** Serialization **/
    std::stringstream stream;
    boost::archive::binary_oarchive oa(stream);
    oa << line_original;

    /** De-serialize **/
    LineSegment<double, 3> line_copy;
    boost::archive::binary_iarchive ia(stream);
    ia >> line_copy;

    BOOST_CHECK_EQUAL(line_original.psi_a(), line_copy.psi_a());
    BOOST_CHECK_EQUAL(line_original.psi_b(), line_copy.psi_b());
    BOOST_CHECK_EQUAL(line_original.direction(), line_copy.direction());
    BOOST_CHECK_EQUAL(line_original.rho(), line_copy.rho());
}


BOOST_AUTO_TEST_CASE(test_geometric_2d_point_map_serialization)
{
    GeometricMap< Point<double, 2> > geometric;
    Point<double, 2> my_point(0.0, 0.0);

    for (register int i=0; i < 99 ; ++i)
    {
        geometric.push_back(my_point);
        my_point.x()++;
    }

    /** Serialization **/
    std::stringstream stream;
    boost::archive::binary_oarchive oa(stream);
    //std::cout << stream.str().size() << std::endl;
    oa << geometric;

    /** De-serialize **/
    GeometricMap< Point<double, 2> > geometric_copy;
    boost::archive::binary_iarchive ia(stream);
    ia >> geometric_copy;

    /** Verification **/
    my_point << 0.00, 0.00;
    for (register int i=0; i < 99 ; ++i)
    {
        BOOST_CHECK_EQUAL(geometric_copy[i], my_point);
        my_point.x()++;
    }
}


BOOST_AUTO_TEST_CASE(test_geometric_3d_point_map_serialization)
{
    GeometricMap< Point<double, 3> > geometric;
    Point<double, 3> my_point(0.0, 0.0, 0.0);

    for (register int i=0; i < 99 ; ++i)
    {
        geometric.push_back(my_point);
        my_point.x()++;
    }

    /** Serialization **/
    std::stringstream stream;
    boost::archive::binary_oarchive oa(stream);
    //std::cout << stream.str().size() << std::endl;
    oa << geometric;

    /** De-serialize **/
    GeometricMap< Point<double, 3> > geometric_copy;
    boost::archive::binary_iarchive ia(stream);
    ia >> geometric_copy;

    /** Verification **/
    my_point << 0.00, 0.00, 0.00;
    for (register int i=0; i < 99 ; ++i)
    {
        BOOST_CHECK_EQUAL(geometric_copy[i], my_point);
        my_point.x()++;
    }
}

