require "test/unit"
require "rbfnv"

LONGKEY = "the easter island statue memorial tabernacle choir presents"

class FnvTest < Test::Unit::TestCase
  def test_fnv1_32
    assert_nothing_raised { Rbfnv }
    assert_equal Rbfnv.fnv1_32(""), 2166136261
    assert_equal Rbfnv.fnv1_32("cat"), 983016379
    assert_equal Rbfnv.fnv1_32(LONGKEY), 2223726839
  end

  def test_fnv1a_32
    assert_nothing_raised { Rbfnv }
    assert_equal Rbfnv.fnv1a_32(""), 2166136261
    assert_equal Rbfnv.fnv1a_32("cat"), 108289031
    assert_equal Rbfnv.fnv1a_32(LONGKEY), 1968151335
  end

  def test_fnv1_64
    assert_nothing_raised { Rbfnv }
    assert_equal Rbfnv.fnv1_64(""), 14695981039346656037
    assert_equal Rbfnv.fnv1_64("cat"), 15624606792861450203
    assert_equal Rbfnv.fnv1_64(LONGKEY), 6216328457121903479
  end

  def test_fnv1a_64
    assert_nothing_raised { Rbfnv }
    assert_equal Rbfnv.fnv1a_64(""), 14695981039346656037
    assert_equal Rbfnv.fnv1a_64("cat"), 17718013163177550631
    assert_equal Rbfnv.fnv1a_64(LONGKEY), 3347195641695891815
  end
end
